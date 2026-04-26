#include <stdio.h>

int main() {
    int n, i;
    
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int pid[n], at[n], bt[n], wt[n], tat[n];

    // Input
    for(i = 0; i < n; i++) {
        pid[i] = i + 1;
        printf("Enter Arrival Time and Burst Time for Process %d: ", pid[i]);
        scanf("%d %d", &at[i], &bt[i]);
    }

    // Sort by Arrival Time (FCFS rule)
    for(i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            if(at[i] > at[j]) {
                // swap arrival time
                int temp = at[i];
                at[i] = at[j];
                at[j] = temp;

                // swap burst time
                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;

                // swap pid
                temp = pid[i];
                pid[i] = pid[j];
                pid[j] = temp;
            }
        }
    }

    // Calculate Waiting Time
    wt[0] = 0;

    for(i = 1; i < n; i++) {
        wt[i] = bt[i-1] + wt[i-1];

        // Adjust if CPU is idle
        if(wt[i] < at[i]) {
            wt[i] = at[i];
        }
    }

    // Calculate Turnaround Time
    for(i = 0; i < n; i++) {
        tat[i] = wt[i] + bt[i];
    }

    // Output
    printf("\nPID\tAT\tBT\tWT\tTAT\n");
    for(i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\n", pid[i], at[i], bt[i], wt[i], tat[i]);
    }

    return 0;
}