#include <stdio.h>
#include "Process.h"

void calculateWaitingTime(Process processes[], int n) {
    int i;
    processes[0].waiting_time = 0; // The first process has no waiting time

    for (i = 1; i < n; i++) {
        processes[i].waiting_time = processes[i-1].waiting_time + processes[i-1].burst_time;
        processes[i].waiting_time -= processes[i].arrival_time; // Adjust for arrival time
    }
}

void calculateTurnaroundTime(Process processes[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        processes[i].turnaround_time = processes[i].burst_time + processes[i].waiting_time;
    }
}

void printGanttChart(Process processes[], int n) {
    int i;
    printf("\nGantt Chart:\n ");
    for (i = 0; i < n; i++) {
        printf("----- ");
    }
    printf("\n|");
    for (i = 0; i < n; i++) {
        printf("  %c  |", processes[i].process_id);
    }
    printf("\n ");
    for (i = 0; i < n; i++) {
        printf("----- ");
    }
    printf("\n0");
    for (i = 0; i < n; i++) {
        printf("    %d", processes[i].turnaround_time);
    }
    printf("\n");
}

void printProcessTable(Process processes[], int n, int total_wt, int total_tt) {
    int i;
    printf("\nPROCESS TABLE\n");
    printf("------------------------------------------------------------\n");
    printf("| Process | Burst Time | Arrival Time | Waiting Time | Turnaround Time |\n");
    printf("------------------------------------------------------------\n");
    for (i = 0; i < n; i++) {
        printf("|    %c    |     %2d      |      %2d       |      %2d       |        %2d         |\n",
               processes[i].process_id, processes[i].burst_time, processes[i].arrival_time,
               processes[i].waiting_time, processes[i].turnaround_time);
    }
    printf("------------------------------------------------------------\n");
    printf("|   Total |             |              |      %2d       |        %2d         |\n", total_wt, total_tt);
    printf("------------------------------------------------------------\n");
    printf("| Average |             |              |    %.2f      |      %.2f      |\n", (float)total_wt / n, (float)total_tt / n);
    printf("------------------------------------------------------------\n");
}

