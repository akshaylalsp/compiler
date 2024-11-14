#include <stdio.h>
#include <string.h>

int i = 0, j = 0, c = 0;
char input[16], stack[15];

// Function to perform reductions based on grammar rules
void check() {
    const char *reduce_msg = "REDUCE TO E -> ";
    for (int z = 0; z < c; z++) {
        // Rule: E -> a
        if (stack[z] == 'a') {
            printf("%s a\n", reduce_msg);
            stack[z] = 'E';
            stack[z + 1] = '\0';
            printf("$%s\t%s$\n", stack, input);
        }
    }
    for (int z = 0; z < c; z++) {
        // Rule: E -> (E)
        if (stack[z] == '(' && stack[z + 1] == 'E' && stack[z + 2] == ')') {
            printf("%s (E)\n", reduce_msg);
            stack[z] = 'E';
            stack[z + 1] = '\0';
            stack[z + 2] = '\0';
            printf("$%s\t%s$\n", stack, input);
            i -= 2;
        }
    }
    for (int z = 0; z < c; z++) {
        // Rule: E -> E*E
        if (stack[z] == 'E' && stack[z + 1] == '*' && stack[z + 2] == 'E') {
            printf("%s E*E\n", reduce_msg);
            stack[z] = 'E';
            stack[z + 1] = '\0';
            stack[z + 2] = '\0';
            printf("$%s\t%s$\n", stack, input);
            i -= 2;
        }
    }
    for (int z = 0; z < c; z++) {
        // Rule: E -> E+E
        if (stack[z] == 'E' && stack[z + 1] == '+' && stack[z + 2] == 'E') {
            printf("%s E+E\n", reduce_msg);
            stack[z] = 'E';
            stack[z + 1] = '\0';
            stack[z + 2] = '\0';
            printf("$%s\t%s$\n", stack, input);
            i -= 2;
        }
    }
    for (int z = 0; z < c; z++) {
        // Rule: E -> E-E
        if (stack[z] == 'E' && stack[z + 1] == '-' && stack[z + 2] == 'E') {
            printf("%s E-E\n", reduce_msg);
            stack[z] = 'E';
            stack[z + 1] = '\0';
            stack[z + 2] = '\0';
            printf("$%s\t%s$\n", stack, input);
            i -= 2;
        }
    }
    for (int z = 0; z < c; z++) {
        // Rule: E -> E/E
        if (stack[z] == 'E' && stack[z + 1] == '/' && stack[z + 2] == 'E') {
            printf("%s E/E\n", reduce_msg);
            stack[z] = 'E';
            stack[z + 1] = '\0';
            stack[z + 2] = '\0';
            printf("$%s\t%s$\n", stack, input);
            i -= 2;
        }
    }
}

int main() {
    printf("GRAMMAR is -\nE->a \nE->E*E \nE->E+E \nE->E-E \nE->E/E \nE->(E)\n");
    printf("Enter the string:\n");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0'; // Remove trailing newline character
    c = strlen(input);

    printf("\nStack\tInput\t\tAction\n");
    printf("\n$\t%s$\n", input);

    for (i = 0, j = 0; j < c; i++, j++) {
        printf("SHIFT\n");
        stack[i] = input[j];
        stack[i + 1] = '\0';
        input[j] = ' ';
        printf("$%s\t%s$\n", stack, input);
        check();
    }

    if (stack[0] == 'E' && stack[1] == '\0') {
        printf("Accept\n");
    } else {
        printf("Reject\n");
    }

    return 0;
}