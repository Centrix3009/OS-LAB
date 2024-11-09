#include<stdio.h>
#include <stdlib.h>

int main() 
{ 
    int queue[20], n, head, i, j, k, seek = 0, max, diff; 
    float avg; 

    // Step 1: Input the max range of disk (disk size)
    printf("Enter the max range of disk: ");
    scanf("%d", &max); 

    // Step 2: Input the size of the queue request (number of disk requests)
    printf("Enter the size of queue request: ");
    scanf("%d", &n); 

    // Step 3: Input the disk positions to be read (queue of disk positions)
    printf("Enter the queue of disk positions to be read:\n"); 
    for(i = 1; i <= n; i++) 
    {
        scanf("%d", &queue[i]); // Read the disk positions into the queue array
    }

    // Step 4: Input the initial head position (current position of the disk head)
    printf("Enter the initial head position: ");
    scanf("%d", &head); 

    // Initialize the queue with the initial head position at the beginning
    queue[0] = head; 

    // Step 5: Process the disk queue and calculate the seek time
    for(j = 0; j < n; j++) 
    { 
        diff = abs(queue[j+1] - queue[j]); // Calculate difference in positions (seek time)
        seek += diff; // Accumulate the seek time
        // Print the movement from one disk position to the next
        printf("Disk head moves from %d to %d with seek time %d\n", queue[j], queue[j+1], diff); 
    } 

    // Step 6: Output the total seek time
    printf("Total seek time is %d\n", seek); 

    // Step 7: Calculate and output the average seek time
    avg = seek / (float)n; // Average seek time is the total seek time divided by the number of requests
    printf("Average seek time is %f\n", avg); 

    return 0; 
}
