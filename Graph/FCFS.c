#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define NO_PROCESS 99                   // constant to use when there is no available process to be executed
#define MAX_ORDER_OR_PRIORITY 99999     // constant to represent the maximum order or priority

// Author: Prof. Jyotiprakash Mishra
// Assistant Professor (II)
// Kalinga Institute of Industrial Technology, Deemed to be University
// Copyright (c) 2021 Jyotiprakash Mishra

typedef struct {
    int process_order;              // order of process arrival. lower numbers mean earlier arrival. must be unique.
    int process_arrival_time;       // arrival time
    int how_much_left;              // CPU time left to complete the process
    int waiting_time;               // how much the process has waited without attention from the CPU
    int response_time;              // how much the process has waited until first attention from the CPU
    int turnaround_time;            // process finish time - process arrival time
    int has_run_at_least_once;      // used to track if the process has already run at least once. used for calculating response times.
    int has_terminated;             // used to track if a process has terminated.
} pinfo;

pinfo **allocate_mem_for_process_list(int length, int only_outer) {
    pinfo **pinfos = malloc(sizeof(pinfo *) * length);
    if (!only_outer) {
        for (int i = 0; i < length; ++i) {
            pinfos[i] = (pinfo *) malloc(sizeof(pinfo));
        }
    }
    return pinfos;
}

void deallocate_mem_for_process_list(pinfo **pinfos, int length, int only_outer) {
    if (!only_outer) {
        for (int i = 0; i < length; ++i) {
            free(pinfos[i]);
        }
    }
    free(pinfos);
}

void take_input(pinfo ***pinfos_out/*Contains Pointers to structures*/, int *pinfos_len/*Stores NO. of Processes*/) {
    int nprocs;//Variable to take input for no. of Processes
    pinfo **pinfos = NULL;//here we created a new array of pointers to structures

    printf("Enter the number of processes: ");
    scanf("%d", &nprocs);
    *pinfos_len = nprocs;

    pinfos = allocate_mem_for_process_list(nprocs, 0);
    /*After Memory Allocation pinfos will have the array of pointers to structure of the size of no. of Processes*/
    for (int i = 0; i < nprocs; ++i) {
        printf("\n");
        pinfos[i]->waiting_time = 0;
        pinfos[i]->response_time = 0;
        pinfos[i]->turnaround_time = 0;
        pinfos[i]->has_run_at_least_once = 0;
        pinfos[i]->has_terminated = 0;

        printf("Enter order of P%d: ", i);
        scanf("%d", &pinfos[i]->process_order);

        printf("Enter time of arrival of P%d: ", i);
        scanf("%d", &pinfos[i]->process_arrival_time);

        printf("Enter burst time of P%d: ", i);
        scanf("%d", &pinfos[i]->how_much_left);
    }//In this loop we are taking input for all the processes a/c to no. of processes we have given as input

    *pinfos_out = pinfos;
    printf("\n");
}

void display_output(pinfo **pinfos, int pinfos_len, int context_switches) {
    printf("\n");
    for (int i = 0; i < pinfos_len; ++i) {
        printf("\nP%d response time: %d\n", i, pinfos[i]->response_time);
        printf("P%d waiting time: %d\n", i, pinfos[i]->waiting_time);
        printf("P%d turnaround time: %d\n", i, pinfos[i]->turnaround_time);
    }
    printf("\nNumber of Context Switches: %d\n", context_switches);
}

int has_process_arrived(pinfo **pinfos, int process, int time) {
    if (process == NO_PROCESS)
        return 1;
    return pinfos[process]->process_arrival_time <= time;
}

int has_process_finished(pinfo **pinfos, int process) {
    if (process == NO_PROCESS)
        return 1;
    return pinfos[process]->has_terminated;
}

int is_process_available_to_run(pinfo **pinfos, int process, int time) {
    return has_process_arrived(pinfos, process, time) && !has_process_finished(pinfos, process);
}

int next_process_to_be_executed(pinfo **pinfos,int pinfos_len,int time,int last_process)
{
    int check=0;
    int process_with_min_order=MAX_ORDER_OR_PRIORITY;
    int process=NO_PROCESS;
    int process_running=last_process;
    for(int check=0;check<pinfos_len;check++)
    {
        process_running=(process_running+1)%pinfos_len;
        if(is_process_available_to_run(pinfos,process_running,time)==1&& pinfos[process_running]->process_order<process_with_min_order){
            process_with_min_order=pinfos[process_running]->process_order;
            process=process_running;
        }
    }
    return process;
}

int fcfs(int last_process_running, pinfo **pinfos, int pinfos_len, int time) {
    // To be filled up by the student
    if(has_process_finished(pinfos,last_process_running)==1)
        return next_process_to_be_executed(pinfos,pinfos_len,time,last_process_running);
    else
        return last_process_running;
}



int next_process_to_run(int last_process_running, pinfo **pinfos, int pinfos_len, int time) {
    return fcfs(last_process_running, pinfos, pinfos_len, time);
}

void run_process_and_update_structs(int process_to_run, pinfo **pinfos, int pinfos_len, int *time) {
    if (process_to_run != NO_PROCESS) {
        --pinfos[process_to_run]->how_much_left;
        pinfos[process_to_run]->has_run_at_least_once = 1;
        if (pinfos[process_to_run]->how_much_left <= 0) {
            pinfos[process_to_run]->has_terminated = 1;
            pinfos[process_to_run]->turnaround_time = *time - pinfos[process_to_run]->process_arrival_time + 1;
        }
    }

    for (int i = 0; i < pinfos_len; ++i) {
        if (i == process_to_run)
            continue;

        if (has_process_arrived(pinfos, i, *time) && (!pinfos[i]->has_run_at_least_once)) {
            ++pinfos[i]->response_time;
        }

        if (has_process_arrived(pinfos, i, *time) && (!pinfos[i]->has_terminated)) {
            ++pinfos[i]->waiting_time;
        }
    }
    ++*time;
}

int all_processes_have_finished(pinfo **pinfos, int pinfos_len) {
    for (int i = 0; i < pinfos_len; ++i) {
        if (!pinfos[i]->has_terminated)
            return 0;
    }
    return 1;
}

int main() {
    pinfo **pinfos = NULL;
    int pinfos_len, time = 0, next_process = NO_PROCESS, context_switches = 0, previous_process;

    take_input(&pinfos, &pinfos_len);

    while (!all_processes_have_finished(pinfos, pinfos_len)) {
        previous_process = next_process;
        next_process = next_process_to_run(next_process, pinfos, pinfos_len, time);
        if (next_process == NO_PROCESS && previous_process != NO_PROCESS) {
            printf("Context switch from a concrete process to NO PROCESS\n");
            ++context_switches;
        } else if (next_process != NO_PROCESS && previous_process == NO_PROCESS) {
            printf("Context switch from NO PROCESS to a concrete process\n");
            ++context_switches;
        } else if (next_process != NO_PROCESS && previous_process != NO_PROCESS && next_process != previous_process) {
            printf("Context switch from one process to another\n");
            ++context_switches;
        }
        if (next_process == NO_PROCESS)
            printf("From time = %d to time = %d. No Process\n", time, time + 1);
        else
            printf("From time = %d to time = %d. Running P%d\n", time, time + 1, next_process);
        run_process_and_update_structs(next_process, pinfos, pinfos_len, &time);
    }

    display_output(pinfos, pinfos_len, context_switches);
    deallocate_mem_for_process_list(pinfos, pinfos_len, 0);
}
