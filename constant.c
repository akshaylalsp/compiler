#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    int n, i, j, k;
    char s[10][10], t, f;

    printf("Enter the number of statements: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter statement %d: ", i + 1);
        scanf("%s", s[i]);
    }

    for (i = 0; i < n; i++) {
        if (isdigit(s[i][2]) && s[i][3] == '\0') { // Check if third character is a digit and statement length is 3
            f = s[i][2];   // Store the constant value
            t = s[i][0];   // Store the variable name
            s[i][0] = '\0'; // Mark the statement as processed

            for (j = i + 1; j < n; j++) {
                if (s[j][0] == t) { // If another statement with the same variable is found
                    break;
                }
                k = 2;
                while (s[j][k] != '\0') { // Replace occurrences of 't' with 'f'
                    if (s[j][k] == t) {
                        s[j][k] = f;
                    }
                    k++;
                }
            }
        }
    }

    printf("\nStatements after removing constant propagation:\n");
    for (i = 0; i < n; i++) {
        if (s[i][0] != '\0') { // Print only non-processed statements
            printf("%s\n", s[i]);
        }
    }

    return 0;
}