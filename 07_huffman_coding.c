#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct Node {
    char ch;
    int freq;
    struct Node *left, *right;
} Node;
Node *newNode(char ch, int f) {
    Node *p = malloc(sizeof(Node));
    if (!p) exit(1);
    p->ch = ch; p->freq = f; p->left = p->right = NULL;
    return p;
}
void sortNodes(Node *a[], int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (a[i]->freq > a[j]->freq) {
                Node *t = a[i]; a[i] = a[j]; a[j] = t;
            }
}
void printCodes(Node *root, char code[], int depth) {
    if (!root) return;
    if (!root->left && !root->right) {
        if (depth == 0) code[depth++] = '0';
        code[depth] = '\0';
        printf("%c : %s\n", root->ch, code);
        return;
    }
    code[depth] = '0'; printCodes(root->left, code, depth + 1);
    code[depth] = '1'; printCodes(root->right, code, depth + 1);
}
void freeTree(Node *r) {
    if (r) { freeTree(r->left); freeTree(r->right); free(r); }
}
int main(void) {
    int n;
    Node *a[MAX];
    char code[MAX];
    printf("Enter number of characters: ");
    scanf("%d", &n);
    if (n <= 0 || n > MAX) return 1;
    for (int i = 0; i < n; i++) {
        char ch; int f;
        printf("Character and frequency: ");
        scanf(" %c%d", &ch, &f);
        a[i] = newNode(ch, f);
    }
    while (n > 1) {
        sortNodes(a, n);
        Node *left = a[0], *right = a[1];
        Node *parent = newNode('\0', left->freq + right->freq);
        parent->left = left; parent->right = right;
        a[0] = parent;
        for (int i = 1; i < n - 1; i++) a[i] = a[i + 1];
        n--;
    }
    printf("Huffman codes:\n");
    printCodes(a[0], code, 0);
    freeTree(a[0]);
    return 0;
}
