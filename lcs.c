#include <stdio.h>
#include <string.h>
#define MAX 500
int main(void)
{
    char a[MAX + 1], b[MAX + 1], lcs[MAX + 1];
    int dp[MAX + 1][MAX + 1];
    printf("Enter first string: ");
    scanf("%500s", a);
    printf("Enter second string: ");
    scanf("%500s", b);
    int m = (int)strlen(a), n = (int)strlen(b);
    for (int i = 0; i <= m; i++)
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (a[i - 1] == b[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = dp[i - 1][j] > dp[i][j - 1] ? dp[i - 1][j] : dp[i][j - 1];
        }
    int i = m, j = n, k = dp[m][n];
    lcs[k] = '\0';
    while (i > 0 && j > 0)
    {
        if (a[i - 1] == b[j - 1])
            lcs[--k] = a[--i], j--;
        else if (dp[i - 1][j] >= dp[i][j - 1])
            i--;
        else
            j--;
    }
    printf("LCS length = %d\nLCS = %s\n", dp[m][n], lcs);
    return 0;
}
