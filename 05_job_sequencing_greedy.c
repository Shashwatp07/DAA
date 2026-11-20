#include <stdio.h>
#include <stdlib.h>
typedef struct { int id, deadline, profit; } Job;
int compare(const void *a, const void *b) {
    int x = ((const Job *)a)->profit, y = ((const Job *)b)->profit;
    return (x < y) - (x > y);
}
int main(void) {
    int n, maxD = 0, total = 0;
    Job jobs[1000];
    printf("Enter number of jobs: ");
    scanf("%d", &n);
    if (n < 0 || n > 1000) return 1;
    for (int i = 0; i < n; i++) {
        jobs[i].id = i + 1;
        printf("Deadline and profit for job %d: ", i + 1);
        scanf("%d%d", &jobs[i].deadline, &jobs[i].profit);
        if (jobs[i].deadline > maxD) maxD = jobs[i].deadline;
    }
    qsort(jobs, n, sizeof(Job), compare);
    if (maxD > n) maxD = n;
    int slot[1001] = {0};
    for (int i = 0; i < n; i++)
        for (int t = jobs[i].deadline < maxD ? jobs[i].deadline : maxD; t >= 1; t--)
            if (!slot[t]) { slot[t] = jobs[i].id; total += jobs[i].profit; break; }

    printf("Scheduled jobs by time slot:\n");
    for (int t = 1; t <= maxD; t++)
        if (slot[t]) printf("Slot %d: Job %d\n", t, slot[t]);
        else printf("Slot %d: empty\n", t);
    printf("Total profit = %d\n", total);
    return 0;
}
