#include <stdio.h>

struct student
{
	char name[32];
	int id;
	int score[5];
};

int main(int argc, const char *argv[])
{
	struct student class[35] = {		
		{
			.name = "niko",	
			.id = 1,
			.score[0] = 91,
			.score[1] = 92,
			.score[2] = 95,
			.score[3] = 97,
			.score[4] = 92,			
		},
		{
			.name = "niko",	
			.id = 1,
			.score[0] = 91,
			.score[1] = 92,
			.score[2] = 95,
			.score[3] = 97,
			.score[4] = 92,			
		},
		{
			.name = "niko",	
			.id = 1,
			.score[0] = 91,
			.score[1] = 92,
			.score[2] = 95,
			.score[3] = 97,
			.score[4] = 92,			
		},
		{
			.name = "niko",	
			.id = 1,
			.score[0] = 91,
			.score[1] = 92,
			.score[2] = 95,
			.score[3] = 97,
			.score[4] = 92,			
		},
	};


	return 0;
}
