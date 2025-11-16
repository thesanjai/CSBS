#include <stdio.h>
#include <stdbool.h>

#define MAX_PROCESSES 6
#define TIME_QUANTUM 2

int main() {
    // Process details
    int processIds[MAX_PROCESSES] = {1, 2, 3, 4, 5,6};
    int arrivalTimes[MAX_PROCESSES] = {0, 1, 2, 3, 4,5};
    int burstTimes[MAX_PROCESSES] = {4,5,2,1,6,3};;
    int remainingTimes[MAX_PROCESSES];
    int completionTimes[MAX_PROCESSES];
    bool executed[MAX_PROCESSES] = {false};

    int n = MAX_PROCESSES;
    int time = 0;
    int completedProcesses = 0;

    printf("Time\tProcess\n");

    // Initialize remaining times
    for (int i = 0; i < n; i++) {
        remainingTimes[i] = burstTimes[i];
    }

    // Round Robin Scheduling
    while (completedProcesses < n) {
        for (int i = 0; i < n; i++) {
            if (!executed[i] && arrivalTimes[i] <= time) {
                if (remainingTimes[i] > TIME_QUANTUM) {
                    printf("%d\tP%d\n", time, processIds[i]);
                    time += TIME_QUANTUM;
                    remainingTimes[i] -= TIME_QUANTUM;
                    if (remainingTimes[i] == 0) {
                        executed[i] = true;
                        completionTimes[i] = time;
                        completedProcesses++;
                    }
                } else {
                    printf("%d\tP%d\n", time, processIds[i]);
                    time += remainingTimes[i];
                    executed[i] = true;
                    completionTimes[i] = time;
                    completedProcesses++;
                }
            }
        }
    }

    // Calculate Turnaround Time and Waiting Time
    int totalTurnaroundTime = 0;
    int totalWaitingTime = 0;
    printf("\nProcess\tTurnaround Time\tWaiting Time\n");
    for (int i = 0; i < n; i++) {
        int turnaroundTime = completionTimes[i] - arrivalTimes[i];
        int waitingTime = turnaroundTime - burstTimes[i];
        totalTurnaroundTime += turnaroundTime;
        totalWaitingTime += waitingTime;
        printf("P%d\t%d\t\t%d\n", processIds[i], turnaroundTime, waitingTime);
    }

    // Print Average Turnaround Time and Average Waiting Time
    printf("\nAverage Turnaround Time: %.2f\n", (float)totalTurnaroundTime / n);
    printf("Average Waiting Time: %.2f\n", (float)totalWaitingTime / n);

    return 0;
}
