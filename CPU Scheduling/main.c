#include <stdio.h>
#include "Process.h"

int main() {
    int i, n = 2; // Number of processes

    Process processes[2] = {
        {'A', 5, 0, 0, 0},
        {'B', 2, 1, 0, 0}
    };

    calculateWaitingTime(processes, n);
    calculateTurnaroundTime(processes, n);

    int total_wt = 0, total_tt = 0;
    for (i = 0; i < n; i++) {
        total_wt += processes[i].waiting_time;
        total_tt += processes[i].turnaround_time;
    }

    printf("INPUT PROCESS\n");
    printf("Total Number: %d\n", n);

    printProcessTable(processes, n, total_wt, total_tt);
    printGanttChart(processes, n);

    return 0;
}

