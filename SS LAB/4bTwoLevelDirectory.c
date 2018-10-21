#include<stdio.h>

struct dir_struct
{
	char dir_name[10];
	char subdir_name[10][10];
	char fname[10][10][10];
	int n_subd, n_files[10];
} dir[10];

void main()
{
	int i, j, k, n;

	printf("Number of directories in level 1: ");
	scanf("%d",&n);

	for(i=0; i<n; i++)
	{
		printf("Enter directory %d name:", i+1);
		scanf("%s", &dir[i].dir_name);
		printf("Enter number of subdirectories: ");
		scanf("%d",&dir[i].n_subd);

		for(j=0; j<dir[i].n_subd; j++)
		{
			printf("Enter subdirectory (%d-%d) name:", i+1, j+1);
			scanf("%s",&dir[i].subdir_name[j]);
			printf("Enter number of files: ");
			scanf("%d",&dir[i].n_files[j]);
			for(k=0; k<dir[i].n_files[j]; k++)
			{
				printf("Enter file name:");
				scanf("%s",&dir[i].fname[j][k]);
			}
		}
	}

	for (i=0; i<n; i++) {
		printf("%s\n", dir[i].dir_name);
		for (j=0; j<dir[i].n_subd; j++) {
			printf("|-- %s\n", dir[i].subdir_name[j]);
			for (k=0; k<dir[i].n_files[j]; k++) {
				printf("|   -- %s\n", dir[i].fname[j][k]);
			}
		}
	}
}