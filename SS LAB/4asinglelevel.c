// Single level directory structure

#include<stdio.h>
#include<string.h>
/*
void main() {
    int N, i, j, memory_index, memory_requirement[100], memory_locations[100];

    // Get the number of files to be stored
    printf("Enter the number of files: ");
    scanf("%d", &N);

    // Get the memory requirement for each file
    for (i=0; i<N; i++) {
        printf("Memory requirement for process %d: ", i+1);
        scanf("%d", &memory_requirement[i]);
    }

    memory_index = 0;
    printf("The allocation is: \n");
    // Allocating memory in sequential order
    for (i=0; i< N; i++) {
        printf("Process %d: ", i+1);
        // Set the file number in memory location for each file
        for (j=0; j<memory_requirement[i]; j++) {
            memory_locations[memory_index] = i;
            printf("%d\t", memory_index);
            memory_index++;
        }
        printf("\n");
    }
}*/

#define SIZE 10

void main() {
    int n, i, j, c;
    char files[SIZE][10];
    char fname[10];

    printf("Enter the number of files: ");
    scanf("%d", &n);

    for (i=0; i<n; i++) {
        printf("Enter file %d name: ", i+1);
        scanf("%s", files[i]);
    }

    printf("1. Search\n2. Delete\n3. Display\n");
    scanf("%d", &c);
    if (c == 1) {
        printf("Enter file to search: ");
        scanf("%s", fname);
        for (i=0; i<n; i++) if (strcmp(fname, files[i]) == 0) printf("Found at position %d", i+1);
    }
    else if (c == 2){

        printf("Enter file to delete: ");
        scanf("%s", fname);

        for (i=0; i<n; i++) {
            if (strcmp(fname, files[i]) == 0) {
                for (j=i; j<n-1; j++) strcpy(files[j], files[j+1]);
                break;
            }
        }

        for (i=0; i<n; i++) {
            printf("%s\n", files[i]);
        }
    }
    else {
        for (i=0; i<n; i++) {
            printf("%s\n", files[i]);
        }
    }
}