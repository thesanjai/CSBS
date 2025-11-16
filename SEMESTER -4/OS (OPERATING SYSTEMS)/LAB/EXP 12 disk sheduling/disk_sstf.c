#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include<limits.h>

// Function to find the closest request to the current head position
int findClosestRequest(int *requests, bool *visited, int n, int currentHead) {
    int minDistance = 9999;
    int minIndex = -1;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            int distance = abs(currentHead - requests[i]);
            if (distance < minDistance) {
                minDistance = distance;
                minIndex = i;
            }
        }
    }

    return minIndex;
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

    bool *visited = (bool *)calloc(n, sizeof(bool));
    if (visited == NULL) {
        printf("Memory allocation failed\n");
        free(requests);
        return 1;
    }

    // Calculate total head movement
    int totalHeadMovement = 0;
    printf("Order of disk service:\n");
    for (int i = 0; i < n; i++) {
        int closestIndex = findClosestRequest(requests, visited, n, currentHead);
        printf("%d ", requests[closestIndex]);
        totalHeadMovement += abs(currentHead - requests[closestIndex]);
        currentHead = requests[closestIndex];
        visited[closestIndex] = true;
    }
    printf("\n");

    // Display total head movement
    printf("Total head movement: %d\n", totalHeadMovement);

    // Free dynamically allocated memory
    free(requests);
    free(visited);

    return 0;
}
