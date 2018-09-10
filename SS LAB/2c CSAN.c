#include<stdio.h>

void  main() {
    int n, i, j, head, max_head, disk_queue[50], temp, head_index;
    printf("Enter the current head position: ");
    scanf("%d", &head);
    printf("Enter the max head position: ");
    scanf("%d", &max_head);
    printf("Enter the number of elements in disk queue: ");
    scanf("%d", &n);
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
        if (disk_queue[i] == head) head_index = i;
    }

    // Towards right
    for (i=head_index; i<n; i++) printf("%d->", disk_queue[i]);

    // Go back to 0
    printf("0->");

    // Towards right
    for (i=0; i<head_index; i++) printf("%d->", disk_queue[i]);

}

