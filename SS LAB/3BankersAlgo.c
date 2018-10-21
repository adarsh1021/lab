#include <stdio.h>

#define SIZE 20

void main()
{
    int N, i, j, check, flag, total_processes, num_resources, available[SIZE], allocation[SIZE][SIZE], max[SIZE][SIZE], need[SIZE][SIZE], status[SIZE], schedule[SIZE];

	printf("\nEnter the number of process: ");
	scanf("%d", &N);
	
	total_processes = N;

	printf("\nEnter the number of resources: ");
	scanf("%d", &num_resources);

    // Get the contents of allocation matrix
	for(i=0; i<N; i++)
	{
		for(j=0; j<num_resources; j++)
		{
			printf("\nEnter the allocated resources %d for process %d: ", j, i);
			scanf("%d", &allocation[i][j]);
		}
	}

    // Get the contents of max matrix
	for(i=0; i<N; i++)
	{
		for(j=0; j<num_resources; j++)
		{
			printf("\nEnter the max resources %d for process %d: ", j, i);
			scanf("%d", &max[i][j]);
            // Assign the values of need matrix
			need[i][j] = max[i][j] - allocation[i][j];
		}
	}

    // Get the contents of available array
	for(i=0; i<num_resources; i++)
	{
		printf("\nEnter the available number of resources j:");
		scanf("%d", &available[i]);
		
	}

    // Setting default status to 1, and initializing schedule
    for (i=0; i<N; i++)
    {
        status[i] = 1;
        schedule[i] = i+1;
    }

    printf("\nSafe Sequence\n");
    while(total_processes)
    {		check=0;
            for(i=0; i<N; i++)
            {	flag=1;
                if(status[i])
                {	
                    for(j=0; j<num_resources; j++)
                    {
                        if(available[j] < need[i][j])
                        {
                            flag=0;
                            break;
                        }
                    }
                    if(flag)
                    {
                        status[i]=0;
                        total_processes--;
                        check = 1;
                        printf("\n%d",schedule[i]);
                        for(j=0; j<num_resources; j++)
                        {
                            available[j] += allocation[i][j];
                        }
                        break;
                    }
                
                }
            }

        if(check==0)
        {
            printf("\nNOT SAFE STATE");
            break;
        }
    }
}