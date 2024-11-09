#include <stdio.h>

struct process {
    int burst, wait, comp, f; // burst time, waiting time, completion time, flag to track if process is completed
} p[20] = {0, 0}; // initialize all the process values to 0

int main() {
    int n, i, j, totalwait = 0, totalturn = 0, quantum, flag = 1, time = 0; // variables for process count, time, etc.

    // Step 1: Get the number of processes
    printf("\nEnter The No Of Process:");
    scanf("%d", &n); // number of processes

    // Step 2: Get the quantum time (time slice for Round Robin)
    printf("\nEnter The Quantum time (in ms) :");
    scanf("%d", &quantum); // time slice for each process

    // Step 3: Get the burst time for each process
    for (i = 0; i < n; i++) {
        printf("Enter The Burst Time (in ms) For Process #%2d:", i + 1);
        scanf("%d", &p[i].burst); // input burst time for process
        p[i].f = 1; // initialize the flag for each process
    }

    // Step 4: Print the header for process execution
    printf("\nOrder Of Execution \n");
    printf("\nProcess Starting Ending Remaining");
    printf("\n\t\tTime \tTime \t Time");

    // Step 5: Round Robin scheduling
    while (flag == 1) { // Loop until all processes are finished (flag becomes 0)
        flag = 0; // Reset flag in each iteration to check if any process is left to execute

        for (i = 0; i < n; i++) {
            // If process is not finished, execute it
            if (p[i].f == 1) {
                flag = 1; // Set flag to 1, indicating there are unfinished processes

                j = quantum; // set the time slice for each process

                // If remaining burst time is greater than quantum time, process executes for quantum time
                if ((p[i].burst - p[i].comp) > quantum) {
                    p[i].comp += quantum; // add quantum time to completion time
                }
                else {
                    // If burst time left is less than or equal to quantum, finish the process
                    p[i].wait = time - p[i].comp; // calculate waiting time for process
                    j = p[i].burst - p[i].comp; // update the remaining burst time
                    p[i].comp = p[i].burst; // mark the process as completed
                    p[i].f = 0; // set the flag to 0 (process completed)
                }

                // Display the process execution information
                printf("\nprocess # %-3d %-10d %-10d %-10d", i + 1, time, time + j, p[i].burst - p[i].comp);
                time += j; // increment time by the amount of time the process executed
            }
        }
    }

    // Step 6: Display waiting time and turnaround time
    printf("\n\n------------------");
    printf("\nProcess \t Waiting Time TurnAround Time ");
    for (i = 0; i < n; i++) {
        printf("\nProcess # %-3d\t %-10d\t %-10d", i + 1, p[i].wait, p[i].wait + p[i].burst);

        totalwait = totalwait + p[i].wait; // accumulate total waiting time
        totalturn = totalturn + p[i].wait + p[i].burst; // accumulate total turnaround time
    }

    // Step 7: Calculate and display average waiting and turnaround times
    printf("\n\nAverage\n-- ");
    printf("\nWaiting Time: %fms", totalwait / (float)n);
    printf("\nTurn Around Time: %fms\n\n", totalturn / (float)n);

    return 0;
}
