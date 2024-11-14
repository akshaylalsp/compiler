#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char input[] = "a+b*c+d";
    char temp = 'A';
    

    int i = 0;
    while (input[i] != '\0') {
        if (input[i] == '*' || input[i] == '/') {
            printf("\n%c = %c %c %c", temp, input[i - 1], input[i], input[i + 1]);
            input[i - 1] = temp;  // Replace the left operand with the temporary variable
            int j = i + 2;  // Skip the right operand and operator
            
            // Shift the rest of the string left
            while (input[j] != '\0') {
                input[i] = input[j];
                i++;
                j++;
            }
            input[i] = '\0';  // Null-terminate the string after shifting
            
            temp++;  // Move to the next temporary variable
            i = 0;  // Reset index to re-scan from the beginning
        }
        else {
            i++;
        }
    }

    i = 0;  // Reset index for the next pass
    while (input[i] != '\0') {
        if (input[i] == '+' || input[i] == '-') {
            printf("\n%c = %c %c %c", temp, input[i - 1], input[i], input[i + 1]);
            input[i - 1] = temp;  // Replace the left operand with the temporary variable
            int j = i + 2;  // Skip the right operand and operator
            
            // Shift the rest of the string left
            while (input[j] != '\0') {
                input[i] = input[j];
                i++;
                j++;
            }
            input[i] = '\0';  // Null-terminate the string after shifting
            
            temp++;  // Move to the next temporary variable
            i = 0;  // Reset index to re-scan from the beginning
        }
        else {
            i++;
        }
    }

    return 0;
}