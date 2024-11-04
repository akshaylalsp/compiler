#include <stdio.h>
#include <ctype.h>
#include <string.h>

void Td();
void Ed();
void E();
void F();
void T();

char expr[10];
int c, flag;

int main() {
    c = 0;
    flag = 0;

    printf("\nEnter an Algebraic Expression:\t");
    scanf("%s", expr);

    E();

    if ((strlen(expr) == c) && (flag == 0)) {
        printf("\nThe Expression %s is Valid\n", expr);
    } else {
        printf("\nThe Expression %s is Invalid\n", expr);
    }

    return 0;
}

void E() {
    T();
    Ed();
}

void T() {
    F();
    Td();
}

void Td() {
    if (expr[c] == '*') {
        c++;
        F();
        Td();
    }
}

void F() {
    if (islower(expr[c])) {
        c++;
    } else if (expr[c] == '(') {
        c++;
        E();
        if (expr[c] == ')') {
            c++;
        } else {
            flag = 1;
        }
    } else {
        flag = 1;
    }
}

void Ed() {
    if (expr[c] == '+') {
        c++;
        T();
        Ed();
    }
}
