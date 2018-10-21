#include<stdio.h>
#include<math.h>
void  main() {
    int n, i, j, head, disk_queue[50], temp, head_index, left_right, max_head, seek, last_head;
    printf("Enter the current head position: ");
    scanf("%d", &head);
    printf("Enter the number of elements in disk queue: ");
    scanf("%d", &n);
    printf("Enter the max head position: ");
    scanf("%d", &max_head);
    printf("Enter the elements of disk queue: ");
    for (i=0; i<n; i++) {
        scanf("%d", &disk_queue[i]);
    }
    disk_queue[n] = head;
    n++;
    disk_queue[n] = max_head;
    n++;

    // Sorting the disk_queue
    for (i=0; i<n-1; i++) {
        for (j=i+1; j<n; j++) {
            if (disk_queue[i] > disk_queue[j]) {
                temp = disk_queue[i];
                disk_queue[i] = disk_queue[j];
                disk_queue[j] = temp;
            }
        }
    }

    // Get the index of current head position
    for (i=0; i<n; i++) {
        if (disk_queue[i] == head) {
            head_index = i;
            if (fabs(disk_queue[head_index] - disk_queue[i-1]) < fabs(disk_queue[i+1] - disk_queue[head_index])) left_right = 0; // left
            else left_right = 1; // right
        }
    }

    last_head = disk_queue[head_index];
    seek = 0;
    if (left_right == 0) {
	seek = head + disk_queue[n-1];

        // Towards left
        for (i=head_index; i>=0; i--) {
            printf("%d->", disk_queue[i]);
            // seek += fabs(last_head - disk_queue[i]);
            // last_head = disk_queue[i];
        }
        // Reach 0
        printf("0->");
        // last_head = 0;
        // Towards right
        for (i=head_index+1; i<n; i++) {
            printf("%d->", disk_queue[i]);
            // seek += fabs(last_head - disk_queue[i]);
            last_head = disk_queue[i];
        }
    }
    else {
	seek = (100 - head) + (100 - disk_queue[0]);
	
        // Towards right
        for (i=head_index; i<n; i++) {
            printf("%d->", disk_queue[i]);
            // seek += fabs(last_head - disk_queue[i]);
            last_head = disk_queue[i];
        }
        // Reach 0
        // printf("0->");
        last_head = 0;
        // Towards left
        for (i=head_index-1; i>=0; i--) {
            printf("%d->", disk_queue[i]);  
            // seek += fabs(last_head - disk_queue[i]);
            last_head = disk_queue[i];
        }
    }
    
    printf("\nAvg seek: %d %d", seek, (seek / (n-2)));

}
