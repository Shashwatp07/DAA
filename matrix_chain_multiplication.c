#include <stdio.h>
#define MAX 100
#define INF 1000000000000000LL
int main(void)
{
    int n, p[MAX];
    long long m[MAX][MAX];
    printf("Enter number of matrices: ");
    scanf("%d", &n);
    if (n <= 0 || n >= MAX)
        return 1;
    printf("Enter %d dimensions: ", n + 1);
    for (int i = 0; i <= n; i++)
        scanf("%d", &p[i]);
    for (int i = 1; i <= n; i++)
        m[i][i] = 0;
    for (int len = 2; len <= n; len++)
        for (int i = 1; i <= n - len + 1; i++)
        {
            int j = i + len - 1;
            m[i][j] = INF;
            for (int k = i; k < j; k++)
            {
                long long q = m[i][k] + m[k + 1][j] + (long long)p[i - 1] * p[k] * p[j];
                if (q < m[i][j])
                    m[i][j] = q;
            }
        }
    printf("Minimum scalar multiplications = %lld\n", m[1][n]);
    return 0;
}
