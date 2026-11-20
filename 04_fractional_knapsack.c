#include <stdio.h>
#include <stdlib.h>
typedef struct { double weight, profit, ratio; } Item;
int compare(const void *a, const void *b) {
    double x = ((const Item *)a)->ratio, y = ((const Item *)b)->ratio;
    return (x < y) - (x > y); /* descending ratio */
}
int main(void) {
    int n;
    double capacity, total = 0;
    Item a[1000];
    printf("Enter number of items and capacity: ");
    scanf("%d%lf", &n, &capacity);
    if (n < 0 || n > 1000 || capacity < 0) return 1;
    for (int i = 0; i < n; i++) {
        printf("Profit and weight of item %d: ", i + 1);
        scanf("%lf%lf", &a[i].profit, &a[i].weight);
        if (a[i].weight <= 0) return 1;
        a[i].ratio = a[i].profit / a[i].weight;
    }
    qsort(a, n, sizeof(Item), compare);
    for (int i = 0; i < n && capacity > 0; i++) {
        double take = a[i].weight < capacity ? a[i].weight : capacity;
        total += take * a[i].ratio;
        capacity -= take;
    }
    printf("Maximum profit = %.2f\n", total);
    return 0;
}
