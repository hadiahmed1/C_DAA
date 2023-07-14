#include <stdio.h>
#define MAX 100
typedef struct Job {
char id[5];
int deadline;
int profit;
} Job;
void displayJobSequence(Job jobs[], int dmax, int timeslot[], int maxprofit)
{
    int i, j;
    //required jobs
    printf("\nRequired Jobs: ");
    for(i = 1; i <= dmax; i++)
    {
    printf("%s", jobs[timeslot[i]].id);
    if(i < dmax)
    {
    printf(" -->");
    }
    }
    printf("\nMax Profit: %d\n", maxprofit);
}