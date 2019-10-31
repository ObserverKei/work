#include <stdio.h>
#include <string.h>

unsigned int N = 0, NowN = 0;
unsigned int M = 0, NowM = 0;
unsigned int T = 0, NowT = 0;

int GetTrainInfoInit(void);
int ExecTrainInfoT(char *TrainInfoTStr);
int OrderTrain(unsigned int TmpStartStandArg, unsigned int TmpEndStandArg, unsigned int TmpCntTicketArg);
int FindTrain(unsigned int TmpStartStandArg, unsigned int TmpEndStandArg);

int GetTrainInfoInit(void)
{
	int i = 0;
	char InfoLine[512] = {0};
	char *pTmpkey = NULL;

	
	fgets(InfoLine, sizeof(InfoLine)-1, stdin);
	
	if(NULL != (pTmpkey = strtok(InfoLine, " ")))
	{
		N = atoi(pTmpkey);
		NowN = N;

		if (NULL != (pTmpkey = strtok(NULL, " ")))
		{
			M = atoi(pTmpkey);
			NowM = M;

			if (NULL != (pTmpkey = strtok(NULL, "\0")))
			{
				T = atoi(pTmpkey);
				NowT = T;

				printf("N = %u, M = %u, T = %u\n", N, M, T);
				for (i = 0; i < T; ++i)
				{
					fgets(InfoLine, sizeof(InfoLine)-1, stdin);
					puts(InfoLine);
					ExecTrainInfoT(InfoLine);
				}
			}
			else
			{
				return -1;
			}
		}
		else
		{
			return -1;
		}
	}
	else
	{
		return -1;
	}

	return 0;
}

int ExecTrainInfoT(char *TrainInfoTStr)
{
	int i = 0;
	unsigned int TmpStartStand = 0;
	unsigned int TmpEndStand = 0;
	unsigned int TmpCntTicket = 0;

	char *TmpKey = NULL;

	TmpKey = TrainInfoTStr;

	if (NULL == TrainInfoTStr)
	{
		return -1;
	}
	else if ('B' == *TrainInfoTStr || 'Q' == *TrainInfoTStr)
	{
		TmpKey += 2;

		if (NULL != (TmpKey = strtok(TmpKey, " ")))
		{
			TmpStartStand = atoi(TmpKey);

			if (NULL != (TmpKey = strtok(NULL, " ")))
			{
				TmpEndStand = atoi(TmpKey);

				if ('B' == *TrainInfoTStr)
				{
					if (NULL != (TmpKey = strtok(NULL, " ")))
					{
						TmpCntTicket = atoi(TmpKey);
						OrderTrain(TmpStartStand, TmpEndStand, TmpCntTicket);
					}
					else
					{
						return -1;
					}					
				}
				else if ('Q' == *TrainInfoTStr)
				{
					FindTrain(TmpStartStand, TmpEndStand);
				}
				else
				{
					return -1;
				}
			}
			else
			{
				return -1;
			}
		}
		else
		{
			return -1;
		}
	}
	else
	{
		return -1;
	}

	return 0;
}

int OrderTrain(unsigned int TmpStartStandArg, unsigned int TmpEndStandArg, unsigned int TmpCntTicketArg)
{
	return 0;
}
int FindTrain(unsigned int TmpStartStandArg, unsigned int TmpEndStandArg)
{
	return 0;
}

int main(int argc, const char *argv[])
{
	int i = 0;

	GetTrainInfoInit();

	return 0;
}
