#include <stdio.h>
#include <string.h>

int main() {
    char a[10], ch;

    printf("Enter the three-address code:\n");
    gets(a);  // Reads the three-address code as input
    printf("\n%d",strlen(a));
    ch = a[3];  // Operator is expected at index 3

    switch (ch) {
        case '+':
            printf("\nMOV R0, %c", a[2]);
            printf("\nADD R0, %c", a[4]);
            printf("\nMOV %c, R0\n", a[0]);
            break;

        case '-':
            printf("\nMOV R0, %c", a[2]);
            printf("\nSUB R0, %c", a[4]);
            printf("\nMOV %c, R0\n", a[0]);
            break;

        case '*':
            printf("\nMOV R0, %c", a[2]);
            printf("\nMUL R0, %c", a[4]);
            printf("\nMOV %c, R0\n", a[0]);
            break;

        case '/':
            printf("\nMOV R0, %c", a[2]);
            printf("\nDIV R0, %c", a[4]);
            printf("\nMOV %c, R0\n", a[0]);
            break;

        default:
            printf("INVALID\n");
    }

    return 0;
}