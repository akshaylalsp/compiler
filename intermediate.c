#include <stdio.h>
#include <string.h>

int main() {
    int j = 0, i = 0, n = 0, d = 0;
    char a[20], c = 'A';

    printf("Enter the code: ");
    scanf("%s", a);

    // Calculate the length of the input code
    while (a[i] != '\0') {
        n = n + 1;
        i = i + 1;
    }

    // Process the code for operators
    for (j = 0; j < n; j++) {
        for (i = 0; i < n; i++) {
            if (a[i] == '*' || a[i] == '/') {
                d = i - 1;
                while (a[d] == ' ') {
                    d = d - 1;
                }
                if (d != (i - 1)) {
                    printf("%c = %c %c %c\n", c, a[d], a[i], a[i + 1]);
                    a[d] = c;
                    a[i] = ' ';
                    a[i + 1] = ' ';
                    c = c + 1;
                    continue;
                } else if (d == (i - 1)) {
                    printf("%c = %c %c %c\n", c, a[i - 1], a[i], a[i + 1]);
                    a[i - 1] = c;
                    a[i] = ' ';
                    a[i + 1] = ' ';
                    c = c + 1;
                    continue;
                }
            }
        }
        
        for (i = 0; i < n; i++) {
            if (a[i] == '+' || a[i] == '-') {
                d = i - 1;
                while (a[d] == ' ') {
                    d = d - 1;
                }
                if (d != (i - 1)) {
                    printf("%c = %c %c %c\n", c, a[d], a[i], a[i + 1]);
                    a[d] = c;
                    a[i] = ' ';
                    a[i + 1] = ' ';
                    c = c + 1;
                    continue;
                } else if (d == (i - 1)) {
                    printf("%c = %c %c %c\n", c, a[i - 1], a[i], a[i + 1]);
                    a[i - 1] = c;
                    a[i] = ' ';
                    a[i + 1] = ' ';
                    c = c + 1;
                    continue;
                }
            }
        }
    }

    return 0;
}
