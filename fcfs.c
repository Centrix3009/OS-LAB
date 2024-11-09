#include <stdio.h>

struct Process {
    int id;
    int arrivalTime;
    int burstTime;
    int waitingTime;
    int turnaroundTime;
    int startTime;
    int completionTime;
};

int main() {
    int n, i;
    float totalWaitingTime = 0, totalTurnaroundTime = 0, avgWaitingTime, avgTurnaroundTime;

    // Step 2: Create the number of processes
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process processes[n];

    // Step 3: Get the ID, Arrival time, and Burst time for each process
    for (i = 0; i < n; i++) {
        printf("Enter the Process Name, Arrival Time & Burst Time: ");
        scanf("%d %d %d", &processes[i].id, &processes[i].arrivalTime, &processes[i].burstTime);
    }

    // Step 4, 5, 6: Calculate Start Time, Waiting Time, Turnaround Time, and Completion Time for each process
    for (i = 0; i < n; i++) {
        if (i == 0) {
            processes[i].startTime = processes[i].arrivalTime;
        } else {
            processes[i].startTime = processes[i - 1].completionTime > processes[i].arrivalTime 
                                     ? processes[i - 1].completionTime 
                                     : processes[i].arrivalTime;
        }
        processes[i].waitingTime = processes[i].startTime - processes[i].arrivalTime;
        processes[i].completionTime = processes[i].startTime + processes[i].burstTime;
        processes[i].turnaroundTime = processes[i].completionTime - processes[i].arrivalTime;

        totalWaitingTime += processes[i].waitingTime;
        totalTurnaroundTime += processes[i].turnaroundTime;
    }

    // Step 10, 11: Calculate Average Waiting Time and Average Turnaround Time
    avgWaitingTime = totalWaitingTime / n;
    avgTurnaroundTime = totalTurnaroundTime / n;

    // Step 12: Display the result
    printf("\nPName\tArrTime\tBurTime\tStart\tCompTime\tWaitTime\tTurnTime\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t\t%d\t\t%d\n", processes[i].id, processes[i].arrivalTime,
               processes[i].burstTime, processes[i].startTime, processes[i].completionTime,
               processes[i].waitingTime, processes[i].turnaroundTime);
    }

    printf("\nAverage Waiting Time: %f", avgWaitingTime);
    printf("\nAverage Turnaround Time: %f\n", avgTurnaroundTime);

    return 0;
}
