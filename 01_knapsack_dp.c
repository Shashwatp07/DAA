#include <stdio.h>
int main(void)
{
    int n, W, wt[100], val[100], dp[101][1001];
    printf("Enter number of items and capacity: ");
    scanf("%d%d", &n, &W);
    if (n < 0 || n > 100 || W < 0 || W > 1000)
        return 1;
    for (int i = 1; i <= n; i++)
    {
        printf("Weight and value of item %d: ", i);
        scanf("%d%d", &wt[i], &val[i]);
    }
    for (int i = 0; i <= n; i++)
        for (int w = 0; w <= W; w++)
        {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (wt[i] <= w)
            {
                int take = val[i] + dp[i - 1][w - wt[i]];
                dp[i][w] = take > dp[i - 1][w] ? take : dp[i - 1][w];
            }
            else
                dp[i][w] = dp[i - 1][w];
        }
    printf("Maximum value = %d\n", dp[n][W]);
    printf("Selected item indices: ");
    int w = W;
    for (int i = n; i > 0; i--)
        if (dp[i][w] != dp[i - 1][w])
        {
            printf("%d ", i);
            w -= wt[i];
        }
    printf("\n");
    return 0;
}
