#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *intinarray(int *arr, int i, int len) {
    int j;
    int *r = malloc((len+1) * sizeof(int));
    int l = 0;
    for (j = 0; j < len; j++) {
        if (arr[j] == i) r[(l++)+1] = j;
    }
    if (l == 0) {
        free(r);
        return NULL;
    } else {
        r[0] = l;
        return r;
    }
}

int traverse(int *somelist, int i, int len) {
    fprintf(stderr, "%d\n", i);
    int begin = i;
    int prev = i;
    int *visited = malloc(len * sizeof(int));
    visited[0] = i;
    int l = 1;
    i = somelist[i];
    while (i != begin) {
        fprintf(stderr, "%d\n", i);
        if (i == prev) {
            i = visited[l-1];
            int f = l;
            int *h;
            while ((h=intinarray(somelist, i, l)) != NULL) {
                fprintf(stderr, "sup\n");
                int x = (h++)[0];
                int j;
                int z = 0;
                for (j = 0; j < x; j++) {
                    int *m = intinarray(visited, h[j], l);
                    if (m == NULL) {
                        z = 1;
                        visited[l++] = h[j];
                        i = h[j];
                        break;
                    }
                    free(m);
                }
                if (z) {
                    f++;
                } else {
                    return f;
                }
            }
            return f;
        }
        int *t = intinarray(visited, i, l);
        if (t != NULL) {
            return l-t[1];
        }
        prev = visited[l-1];
        visited[l++] = i;
        i = somelist[i];
    }
    return l;
}

void dothedo(int case_number) {
    int kids;
    scanf("%d\n", &kids);
    int *somelist = malloc(kids * sizeof(int));
    int i;
    for (i = 0; i < kids; i++) {
        int n;
        scanf("%d", &n);
        somelist[i] = n-1;
    }

    int max = 0;
    for (i = 0; i < kids; i++) {
        int a = traverse(somelist, i, kids);
        fprintf(stderr, "-%d\n", a);
        if (a > max) max = a;
    }

    printf("Case #%d: %d\n", case_number+1, max);
}

int main() {
    int test_cases;
    scanf("%d\n", &test_cases);

    int i;
    for (i = 0; i < test_cases; i++) {
        dothedo(i);
    }

    return 0;
}
