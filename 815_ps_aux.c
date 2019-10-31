#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <dirent.h>
#include <pwd.h>
#include <grp.h>

char *GetFileLineInfo(char *TmpRetStr, char *TmpGetStr ,FILE *fp)
{
	char TmpLine[1024]  = {0};
	int CntSeek = 0;

	CntSeek = ftell(fp);
	while (NULL != fgets(TmpLine, sizeof(TmpLine), fp))
	{
		sscanf(TmpLine, TmpGetStr, TmpRetStr);
	}
	strcat(TmpRetStr, "\t");
	fseek(fp, CntSeek, SEEK_SET);

	return TmpRetStr;
}

int main(int argc, const char *argv[])
{
	int i = 0;
	int Cnt = 0;
	char TmpLine[1024] = {0};
	char TmpBuf[128] = {0};
	char TmpStat[4096] = {0};
	char TmpFile[1024] = {0};
	DIR *dp = NULL;
	struct dirent *dep = NULL;
	FILE *fp = NULL;
	struct passwd *pwd =NULL;
	struct group *grp = NULL;

	dp = opendir("/proc/");
	if (NULL == dp)
	{
		perror("fail to opendir");
		return -1;
	}
	printf("PID\tPPID\t    USR\t\t    GRP\t\tSTAT\tCOMMAND\n");
	while (NULL != (dep = readdir(dp)))
	{
		for (i = 0, Cnt = 0; i < strlen(dep->d_name); i++)
		{
			if (isdigit(dep->d_name[i]))
			{
				Cnt++;
			}
		}
		if (Cnt == i)
		{
			sprintf(TmpFile, "/proc/%s/status", dep->d_name);
			fp = fopen(TmpFile, "r");
			if (NULL == fp)
			{
				perror("fail to fopen");
				return -1;
			}
			printf("%s", GetFileLineInfo(TmpStat, "Pid:\t%s", fp));
			printf("%s", GetFileLineInfo(TmpStat, "PPid:\t%s", fp));
			printf("%8s\t", getpwuid(atoi(GetFileLineInfo(TmpStat, "Uid:\t%s", fp)))->pw_name);
			printf("%8s\t", getgrgid(atoi(GetFileLineInfo(TmpStat, "Gid:\t%s", fp)))->gr_name);
			printf("%s", GetFileLineInfo(TmpStat, "State:\t%s", fp));
			printf("%s\n", GetFileLineInfo(TmpStat, "Name:\t%s", fp));

#if 0	
			/* Pid */
			while (NULL != fgets(TmpLine, sizeof(TmpLine), fp))
			{
				sscanf(TmpLine, "Pid:\t%s", TmpBuf);
			}
			fseek(fp, 0, SEEK_SET);			
			sprintf(TmpStat, "%s\t", TmpBuf);	

			/* PPid */
			while (NULL != fgets(TmpLine, sizeof(TmpLine), fp))
			{
				sscanf(TmpLine, "PPid:\t%s", TmpBuf);
			}
			fseek(fp, 0, SEEK_SET);			
			sprintf(TmpStat+strlen(TmpStat), "%s\t", TmpBuf);	

			/* USR */
			while (NULL != fgets(TmpLine, sizeof(TmpLine), fp))
			{
				sscanf(TmpLine, "Uid:\t%s", TmpBuf);
			}
			fseek(fp, 0, SEEK_SET);			
			pwd = getpwuid(atoi(TmpBuf));
			sprintf(TmpStat+strlen(TmpStat), "%8s\t", pwd->pw_name);	

			/* GRP */
			while (NULL != fgets(TmpLine, sizeof(TmpLine), fp))
			{
				sscanf(TmpLine, "Gid:\t%s", TmpBuf);
			}
			fseek(fp, 0, SEEK_SET);			
			grp = getgrgid(atoi(TmpBuf));
			sprintf(TmpStat+strlen(TmpStat), "%8s\t", grp->gr_name);	

			/* State */
			while (NULL != fgets(TmpLine, sizeof(TmpLine), fp))
			{
				sscanf(TmpLine, "State:\t%s", TmpBuf);
			}
			fseek(fp, 0, SEEK_SET);			
			sprintf(TmpStat+strlen(TmpStat), "%s\t", TmpBuf);	

			/* COMMAND */
			while (NULL != fgets(TmpLine, sizeof(TmpLine), fp))
			{
				sscanf(TmpLine, "Name:\t%s", TmpBuf);
			}
			fseek(fp, 0, SEEK_SET);			
			sprintf(TmpStat+strlen(TmpStat), "%s\t", TmpBuf);	

			printf("%s\n", TmpStat);
#endif
			fclose(fp);
		}
	}



	return 0;
}
