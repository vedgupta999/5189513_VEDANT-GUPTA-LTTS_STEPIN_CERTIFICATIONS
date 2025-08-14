#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


#define MAX_LEN 1000000 // total sum of lengths possible

// Stack to store previous states of S for undo
char *history[100000];
int history_top = -1;

void push_history(const char *s) {
    history[++history_top] = strdup(s); // store a copy
}

char* pop_history() {
    if (history_top < 0) return NULL;
    return history[history_top--];
}

int main() {
    int Q;
    scanf("%d", &Q);

    char S[MAX_LEN + 1] = ""; // initial empty string

    for (int i = 0; i < Q; i++) {
        int type;
        scanf("%d", &type);

        if (type == 1) {
            // append W
            char W[MAX_LEN + 1];
            scanf("%s", W);
            push_history(S);
            strcat(S, W);

        } else if (type == 2) {
            // delete k
            int k;
            scanf("%d", &k);
            push_history(S);
            int len = strlen(S);
            S[len - k] = '\0';

        } else if (type == 3) {
            // print k-th char
            int k;
            scanf("%d", &k);
            printf("%c\n", S[k - 1]);

        } else if (type == 4) {
            // undo
            char *prev = pop_history();
            if (prev) {
                strcpy(S, prev);
                free(prev);
            }
        }
    }

    // Free any remaining history
    while (history_top >= 0) {
        free(history[history_top--]);
    }

    return 0;
}
