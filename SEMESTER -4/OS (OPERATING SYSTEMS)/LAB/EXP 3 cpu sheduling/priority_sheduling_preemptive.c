#include <stdio.h>

#define MAX_PROCESSES 10

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int arrivalTime[MAX_PROCESSES];
    int burstTime[MAX_PROCESSES];
    int priority[MAX_PROCESSES];
    int completionTime[MAX_PROCESSES];

    // Input process details
    printf("Enter arrival time, burst time, and priority for each process:\n");
    for (int i = 0; i < n; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d %d %d", &arrivalTime[i], &burstTime[i], &priority[i]);
    }

    // Sort processes based on arrival time
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arrivalTime[j] > arrivalTime[j + 1]) {
                int temp = arrivalTime[j];
                arrivalTime[j] = arrivalTime[j + 1];
                arrivalTime[j + 1] = temp;

                temp = burstTime[j];
                burstTime[j] = burstTime[j + 1];
                burstTime[j + 1] = temp;

                temp = priority[j];
                priority[j] = priority[j + 1];
                priority[j + 1] = temp;
            }
        }
    }

    // Calculate completion times
    int currentTime = 0;
    for (int i = 0; i < n; i++) {
        if (arrivalTime[i] > currentTime) {
            currentTime = arrivalTime[i];
        }
        completionTime[i] = currentTime + burstTime[i];
        currentTime = completionTime[i];
    }

    // Display process details and completion times
    printf("\nProcess\tArrival Time\tBurst Time\tPriority\tCompletion Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", i + 1, arrivalTime[i], burstTime[i], priority[i], completionTime[i]);
    }

    return 0;
}
