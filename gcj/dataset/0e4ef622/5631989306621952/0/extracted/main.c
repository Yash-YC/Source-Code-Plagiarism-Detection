#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void dothedo(int case_number) {
    /* put code here */
    char *word;
    scanf("%ms\n", &word);
    char *word2 = malloc(strlen(word)+1);
    memset(word2, 0, strlen(word)+1);
    char *word3 = malloc(strlen(word)+1);
    int i;
    for (i = 0; i < strlen(word); i++) {
        word3[0] = word[i];
        word3[1] = 0;
        if (word[i] >= word2[0]) {
            char *tmp = strcat(word3, word2);
            word3 = word2;
            word2 = tmp;
        } else {
            word2 = strcat(word2, word3);
        }
    }

    printf("Case #%d: %s\n", case_number+1, word2);
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
