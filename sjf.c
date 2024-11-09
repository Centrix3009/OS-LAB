#include <stdio.h>

struct Process {
    int id;
    int bt; // Burst Time
    int wt; // Waiting Time
    int tat; // Turnaround Time
};

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    
    struct Process processes[n];
    
    // Input burst times for each process
    printf("Enter the burst time of each process:\n");
    for (int i = 0; i < n; i++) {
        printf("Process p%d: ", i);
        processes[i].id = i;
        scanf("%d", &processes[i].bt);
    }
    
    // Sort processes by burst time (along with process IDs)
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (processes[j].bt > processes[j + 1].bt) {
                // Swap both burst time and process ID
                struct Process temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }
    
    // Calculate waiting time and turnaround time
    int totalWaitingTime = 0, totalTurnaroundTime = 0;
    
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            processes[i].wt = 0;
        } else {
            processes[i].wt = processes[i - 1].wt + processes[i - 1].bt;
        }
        processes[i].tat = processes[i].wt + processes[i].bt;
        
        totalWaitingTime += processes[i].wt;
        totalTurnaroundTime += processes[i].tat;
    }
    
    float avgWaitingTime = (float) totalWaitingTime / n;
    float avgTurnaroundTime = (float) totalTurnaroundTime / n;
    
    // Display results
    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("p%d\t%d\t\t%d\t\t%d\n", processes[i].id, processes[i].bt, processes[i].wt, processes[i].tat);
    }
    
    printf("\nAverage Waiting Time: %f\n", avgWaitingTime);
    printf("Average Turnaround Time: %f\n", avgTurnaroundTime);
    
    return 0;
}
