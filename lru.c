#include<stdio.h>

int main() {
    int a[5], b[20], p=0, q=0, m=0, h, k, i, q1=1, j, u, n;
    char f='F'; // F stands for page fault indicator

    // Step 1: Input number of pages and page numbers
    printf("Enter the number of pages: ");
    scanf("%d", &n);
    
    printf("Enter %d Page Numbers: ", n);
    for(i=0; i<n; i++) {
        scanf("%d", &b[i]); // Read the page numbers into array b
    }

    // Step 2: Process each page in the sequence
    for(i=0; i<n; i++) {
        if(p==0) { // Page fault logic
            if(q>=3) // If 3 pages are already in memory, reset q to 0 (FIFO)
                q=0;
            a[q] = b[i]; // Add page to memory
            q++; // Increment the frame position
            if(q1 < 3) { // If the frame has less than 3 pages, increment the used slots
                q1 = q;
            }
        }

        printf("\n%d", b[i]); // Print the current page
        printf("\t");

        // Print the contents of frames
        for(h = 0; h < q1; h++) {
            printf("%d ", a[h]); // Print current frames
        }

        if((p==0) && (q <= 3)) { // Page fault check
            printf("--> %c", f);  // Indicate page fault
            m++; // Increment the page fault count
        }

        p = 0; // Reset page hit indicator to 0

        if(q1 == 3) { // If all frames are filled (3 pages in memory)
            for(k=0; k<q1; k++) { // Search if the current page is already in frames
                if(b[i+1] == a[k]) 
                    p = 1; // If found, mark as hit
            }

            // If the page is not found, find the least recently used (LRU) page to replace
            for(j = 0; j < q1; j++) {
                u = 0;
                k = i;  
                // Check future page references for each frame
                while(k >= 0 && k >= (i-1)) {
                    if(b[k] == a[j]) 
                        u++; // If page is found, increment usage count
                    k--;
                }

                if(u == 0) { // If the page was not used recently
                    q = j; // Replace this page
                }
            }
        }

        else {
            // If frames aren't full, just check if the current page exists in frames
            for(k = 0; k < q; k++) {
                if(b[i+1] == a[k]) {
                    p = 1; // Mark as hit if found
                }
            }
        }
    }

    // Step 3: Output the total number of page faults
    printf("\nNo of faults: %d", m);

    return 0;
}
