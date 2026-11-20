#include <stdio.h>
#include <stdlib.h>
typedef struct { int start, finish, id; } Activity;
int compare(const void *a, const void *b) {
    const Activity *x = a, *y = b;
    if (x->finish != y->finish) return (x->finish > y->finish) - (x->finish < y->finish);
    return (x->start > y->start) - (x->start < y->start);
}
int main(void) {
    int n, lastFinish = -2147483647, count = 0;
    Activity a[1000];
    printf("Enter number of activities: ");
    scanf("%d", &n);
    if (n < 0 || n > 1000) return 1;
    for (int i = 0; i < n; i++) {
        a[i].id = i + 1;
        printf("Start and finish of activity %d: ", i + 1);
        scanf("%d%d", &a[i].start, &a[i].finish);
    }
    qsort(a, n, sizeof(Activity), compare);
    printf("Selected activities: ");
    for (int i = 0; i < n; i++)
        if (a[i].start >= lastFinish) {
            printf("%d ", a[i].id);
            lastFinish = a[i].finish; count++;
        }
    printf("\nMaximum number = %d\n", count);
    return 0;
}
