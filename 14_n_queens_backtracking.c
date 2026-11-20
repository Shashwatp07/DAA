#include <stdio.h>
#define MAX 20
int n, col[MAX], solutions = 0;
int safe(int row, int c) {
    for (int r = 0; r < row; r++)
        if (col[r] == c || (row - r) == (c - col[r]) || (row - r) == (col[r] - c))
            return 0;
    return 1;
}
void solve(int row) {
    if (row == n) {
        solutions++;
        printf("Solution %d:\n", solutions);
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) printf(col[r] == c ? "Q " : ". ");
            printf("\n");
        }
        printf("\n");
        return;
    }
    for (int c = 0; c < n; c++)
        if (safe(row, c)) { col[row] = c; solve(row + 1); }
}
int main(void) {
    printf("Enter N (1 to %d): ", MAX);
    scanf("%d", &n);
    if (n < 1 || n > MAX) return 1;
    solve(0);
    if (!solutions) printf("No solution exists.\n");
    else printf("Total solutions = %d\n", solutions);
    return 0;
}
