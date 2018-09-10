#include<stdio.h>
#include<math.h>

void main() {
    int n, i, seek, disk_queue[50], head, previous_head;
    printf("Enter the current position of the head: ");
    scanf("%d", &head);
    printf("Enter the number of elements in disk queue: ");
    scanf("%d", &n);
    printf("Enter the elements of disk queue: ");
    seek = 0;
    previous_head = head;
    for (i=0; i<n; i++) {
        scanf("%d", &disk_queue[i]);
        seek += fabs(previous_head - disk_queue[i]);
        previous_head = disk_queue[i];
    }
    printf("\nAverage head movement: %d", seek/n);
}
