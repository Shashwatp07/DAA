#include <stdio.h>
int main(void)
{
    int n, target, a[100], dp[101][10001];
    printf("Enter number of elements and target sum: ");
    scanf("%d%d", &n, &target);
    if (n < 0 || n > 100 || target < 0 || target > 10000)
        return 1;
    for (int i = 1; i <= n; i++)
    {
        printf("Element %d: ", i);
        scanf("%d", &a[i]);
        if (a[i] < 0)
        {
            printf("This implementation requires non-negative values.\n");
            return 1;
        }
    }
    for (int i = 0; i <= n; i++)
        for (int s = 0; s <= target; s++)
        {
            if (s == 0)
                dp[i][s] = 1;
            else if (i == 0)
                dp[i][s] = 0;
            else
            {
                dp[i][s] = dp[i - 1][s];
                if (a[i] <= s && dp[i - 1][s - a[i]])
                    dp[i][s] = 1;
            }
        }
    printf("Subset with sum %d %s\n", target, dp[n][target] ? "exists" : "does not exist");
    if (dp[n][target])
    {
        int s = target;
        printf("One such subset: ");
        for (int i = n; i > 0 && s > 0; i--)
            if (!dp[i - 1][s])
            {
                printf("%d ", a[i]);
                s -= a[i];
            }
        printf("\n");
    }
    return 0;
}
