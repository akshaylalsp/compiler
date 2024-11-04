#include <string.h>
#include <ctype.h>
#include <stdio.h>
void main()
{
    FILE *f;
    char c, str[10];
    int n = 0, i = 0;

    f = fopen("input.txt", "r");
    while ((c = getc(f)) != EOF)
    {
        if (c == '/')
        {
            c = getc(f);
            if (c == '/')
            {
                while (c != '\n')
                {
                    c = getc(f);
                }
            }
            else if (c == '*')
            {
                do
                {
                    while (c != '*')
                    {
                        c = getc(f);
                    }
                    c = getc(f);
                } while (c != '/');
            }
            else
            {
                ungetc(c, f);
                printf("\n/	operator");
            }
        }

        else if (isdigit(c))
        {
            n = c - 48;
            c = getc(f);
            while (isdigit(c))
            {
                n = n * 10 + (c - 48);
                c = getc(f);
            }
            printf("\n %d	number ", n);
            ungetc(c, f);
        }
        else if (isalpha(c))
        {
            str[i++] = c;
            c = getc(f);
            while (isdigit(c) || isalpha(c) || c == '_' || c == '$')
            {
                str[i++] = c;
                c = getc(f);
            }
            str[i++] = '\0';
            if (strcmp("auto", str) == 0 || strcmp("break", str) == 0 || strcmp("case", str) == 0 || strcmp("char", str) == 0 || strcmp("const", str) == 0 || strcmp("continue", str) == 0 || strcmp("default", str) == 0 || strcmp("do", str) == 0 || strcmp("double", str) == 0 || strcmp("else", str) == 0 || strcmp("enum", str) == 0 || strcmp("extern", str) == 0 || strcmp("float", str) == 0 || strcmp("for", str) == 0 || strcmp("goto", str) == 0 || strcmp("if", str) == 0 || strcmp("int", str) == 0 || strcmp("long", str) == 0 || strcmp("register", str) == 0 || strcmp("return ", str) == 0 || strcmp("short", str) == 0 || strcmp(" signed", str) == 0 || strcmp("sizeof", str) == 0 || strcmp("static", str) == 0 || strcmp("struct", str) == 0 || strcmp("switch", str) == 0 || strcmp("typedef", str) == 0 || strcmp("union", str) == 0 || strcmp(" unsigned", str) == 0 || strcmp("void", str) == 0 || strcmp("volatile", str) == 0 || strcmp("while", str) == 0)
            {
                printf("\n %s	keyword", str);
            }
            else
            {
                printf("\n %s	identifier", str);
            }
            ungetc(c, f);
            i = 0;
        }
        else if (c == ' ' || c == '\t' || c == '\n')
        {
            continue;
        }
        else if (c == '+' || c == '-' || c == '*' || c == '/' || c == ' ' || c == '=' || c == '>' || c == '<' || c == '!' || c == '&' || c == '|' || c == '^')
        {
            str[i++] = c;
            c = getc(f);
            while (c == '+' || c == '-' || c == '*' || c == '/' || c == ' ' || c == '=' || c == '>' || c == '<' || c == '!' || c == '&' || c == '|' || c == '^')
            {
                str[i++] = c;
                c = getc(f);
            }
            str[i++] = '\0';
            if (strcmp("+", str) == 0 || strcmp("-", str) == 0 || strcmp("", str) == 0 || strcmp("/", str) == 0 || strcmp(" ", str) == 0 || strcmp("=", str) == 0 || strcmp("!", str) == 0 || strcmp("&", str) == 0 || strcmp("|", str) == 0 || strcmp("^", str) == 0 || strcmp(">", str) == 0 || strcmp("<", str) == 0 || strcmp("+=", str) == 0 || strcmp("-=", str) == 0 || strcmp("=", str) == 0 || strcmp("/=", str) == 0 || strcmp(" =", str) == 0 || strcmp("==", str) == 0 || strcmp("!=", str) == 0 || strcmp(">=", str) == 0 || strcmp("<=", str) == 0 || strcmp("&&", str) == 0 || strcmp("||", str) == 0 || strcmp("<<", str) == 0 || strcmp(">>", str) == 0 || strcmp("++", str) == 0 || strcmp("--", str) == 0)
            {
                printf("\n %s	operator", str);
            }
            else
            {
                printf("\n %s	invalid operator", str);
            }
            ungetc(c, f);
            i = 0;
        }
        else
        {
            printf("\n %c	special symbol", c);
        }
    }
    printf("\n");
    fclose(f);
}