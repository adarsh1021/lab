// Non Preemptive Scheduling for SJF to find turnaround time & waiting time
#include<stdio.h>

void main() {
	int i, j, n, temp, burst_time[20], schedule[20], wait_time[20], turnaround_time[20];
	
	// Get the total number of processes
	printf("Enter the total number of processes: ");
	scanf("%d", &n);
	
	// Get the burst time for each process
	printf("Enter the burst time for each process : ");
	for(i=0; i<n; i++) {
		printf("\nP%d : ", i+1);
		scanf("%d", &burst_time[i]);
	}
	
	// Initaializing schedule to 1, 2, 3...
	for (i=0; i<n; i++) schedule[i] = i+1;
	// Sorting the processes based on burst time
	for(i=0; i<n-1; i++) {
		for(j=i+1; j<n; j++) {
			if (burst_time[j] < burst_time[i]) {
				temp = burst_time[i];
				burst_time[i] = burst_time[j];
				burst_time[j] = temp;
				// Updating schedule
				temp = schedule[i];
				schedule[i] = schedule[j];
				schedule[j] = temp;
			}
		}
	}
	
	// Calculate wait time for each process
	wait_time[0] = 0; // Wait time is 0 for the first process
	for (i=1; i<n; i++) {
		wait_time[i] = 0;
		for (j=0; j<i; j++)  
			wait_time[i] += burst_time[j];
	}
	
	// Calculate the turnaround time 
	for (i=0; i<n; i++) 
		turnaround_time[i] = wait_time[i] + burst_time[i];
		
	printf("Process\t\tBurst Time\t\tWait Time\t\tTurnaround Time\n");
	for (i=0; i<n; i++) {
		printf("%d\t\t%d\t\t\t%d\t\t\t%d\n", schedule[i], burst_time[i], wait_time[i], turnaround_time[i]);
	}
}
