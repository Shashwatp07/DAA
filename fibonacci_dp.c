#include <stdio.h>
int main(void)
{
    int n;
    unsigned long long dp[94];
    printf("Enter n (0 to 93): ");
    scanf("%d", &n);
    if (n < 0 || n > 93)
        return 1;
    dp[0] = 0;
    if (n >= 1)
        dp[1] = 1;
    for (int i = 2; i <= n; i++)
        dp[i] = dp[i - 1] + dp[i - 2];
    printf("Fibonacci series: ");
    for (int i = 0; i <= n; i++)
        printf("%llu ", dp[i]);
    printf("\n");
    return 0;
}
