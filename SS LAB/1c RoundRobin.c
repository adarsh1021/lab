// Premptive Round Robin scheduling
#include<stdio.h>

void main() {
	int i, j, n, quanta, burst_time[20], schedule[20], wait_time[20], turnaround_time[20], remaining_time[20], current_process, clock, exec_time=0, total_time=0;

	// Get the total number of processes
	printf("Enter the total number of processes: ");
	scanf("%d", &n);

	// Get the burst time for each process
	printf("Enter the burst time for each process : \n");
	for(i=0; i<n; i++) {
		printf("P%d : ", i+1);
		scanf("%d", &burst_time[i]);
		remaining_time[i] = burst_time[i];
		exec_time += burst_time[i];
	}

	// Get the time quanta
	printf("Enter the time quanta : ");
	scanf("%d", &quanta);

    current_process = 0;
    clock = 0;
    total_time = exec_time;
	while(exec_time > 0) {
	    if(remaining_time[current_process] > 0) {
            if (remaining_time[current_process] <= quanta) {
                exec_time -= remaining_time[current_process];
                turnaround_time[current_process] = total_time - exec_time;
                remaining_time[current_process] = 0;
            }
            else if (remaining_time[current_process] > quanta){
                exec_time -= quanta;
                remaining_time[current_process] -= quanta;
            }
            schedule[clock] = current_process;
            clock++;
	    }
        current_process = (current_process + 1) % n;
	}

	for (i=0; i<n; i++) {
        wait_time[i] = turnaround_time[i] - burst_time[i];
	}

    printf("Schedule: ");
	for (i=0; i<clock; i++) {
        printf("\n%d: P%d", i+1, schedule[i]+1);
	}

	printf("\nProcess\t\tBurst Time\t\tWait Time\t\tTurnaround Time\n");
	for (i=0; i<n; i++) {
		printf("%d\t\t%d\t\t\t%d\t\t\t%d\n", schedule[i]+1, burst_time[i], wait_time[i], turnaround_time[i]);
	}
}
