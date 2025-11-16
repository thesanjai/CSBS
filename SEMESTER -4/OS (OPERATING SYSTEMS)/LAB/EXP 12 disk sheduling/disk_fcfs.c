#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;  // Number of requests
    printf("Enter the number of requests: ");
    scanf("%d", &n);

    int *requests = (int *)malloc(n * sizeof(int));
    if (requests == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    // Input disk requests
    printf("Enter the disk requests:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &requests[i]);
    }

    // Input current head position
    int currentHead;
    printf("Enter the current head position: ");
    scanf("%d", &currentHead);

    // Calculate total head movement
    int totalHeadMovement = 0;
    printf("Order of disk service:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", requests[i]);
        totalHeadMovement += abs(currentHead - requests[i]);
        currentHead = requests[i];
    }
    printf("\n");

    // Display total head movement
    printf("Total head movement: %d\n", totalHeadMovement);

    // Free dynamically allocated memory
    free(requests);

    return 0;
}
