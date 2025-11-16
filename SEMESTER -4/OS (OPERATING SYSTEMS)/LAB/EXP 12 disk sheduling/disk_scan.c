#include <stdio.h>
#include <stdlib.h>

// Function to sort the disk requests in ascending order
void sortRequests(int *requests, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (requests[j] > requests[j + 1]) {
                int temp = requests[j];
                requests[j] = requests[j + 1];
                requests[j + 1] = temp;
            }
        }
    }
}

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

    // Input the maximum cylinder number
    int maxCylinder;
    printf("Enter the maximum cylinder number: ");
    scanf("%d", &maxCylinder);

    // Sort the disk requests in ascending order
    sortRequests(requests, n);

    // Find the index of the current head position in the sorted requests
    int currentIndex = 0;
    while (currentIndex < n && requests[currentIndex] < currentHead) {
        currentIndex++;
    }

    // Calculate total head movement
    int totalHeadMovement = 0;
    printf("Order of disk service:\n");

    // Scan towards higher cylinder numbers
    for (int i = currentIndex; i < n; i++) {
        printf("%d ", requests[i]);
        totalHeadMovement += abs(currentHead - requests[i]);
        currentHead = requests[i];
    }

    // If there are requests at higher cylinder numbers, move to the maximum cylinder number
    if (currentIndex < n) {
        printf("%d ", maxCylinder);
        totalHeadMovement += abs(currentHead - maxCylinder);
        currentHead = maxCylinder;
    }

    // Scan towards lower cylinder numbers
    for (int i = currentIndex - 1; i >= 0; i--) {
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
