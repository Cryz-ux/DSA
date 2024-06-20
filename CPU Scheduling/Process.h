#ifndef PROCESS_H
#define PROCESS_H

typedef struct {
    char process_id;
    int burst_time;
    int arrival_time;
    int waiting_time;
    int turnaround_time;
} Process;

void calculateWaitingTime(Process processes[], int n);
void calculateTurnaroundTime(Process processes[], int n);
void printGanttChart(Process processes[], int n);
void printProcessTable(Process processes[], int n, int total_wt, int total_tt);

#endif

