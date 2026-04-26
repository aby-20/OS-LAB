#include <stdio.h>

int main() {
    int n, tq, i, time = 0, remain;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    int pid[n], at[n], bt[n], rt[n], wt[n], tat[n];

    for(i = 0; i < n; i++) {
        pid[i] = i + 1;
        printf("Enter Arrival Time and Burst Time for P%d: ", pid[i]);
        scanf("%d %d", &at[i], &bt[i]);
        rt[i] = bt[i]; // remaining time
    }

    printf("Enter Time Quantum: ");
    scanf("%d", &tq);

    remain = n;

    while(remain > 0) {
        int done = 1;

        for(i = 0; i < n; i++) {
            if(rt[i] > 0 && at[i] <= time) {
                done = 0;

                if(rt[i] > tq) {
                    time += tq;
                    rt[i] -= tq;
                } else {
                    time += rt[i];
                    wt[i] = time - bt[i] - at[i];
                    rt[i] = 0;
                    remain--;
                }
            }
        }

        // If no process is ready, move time forward
        if(done == 1) {
            time++;
        }
    }

    // Turnaround Time
    for(i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
    }

    // Output
    printf("\nPID\tAT\tBT\tWT\tTAT\n");
    for(i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\n", pid[i], at[i], bt[i], wt[i], tat[i]);
    }

    return 0;
}