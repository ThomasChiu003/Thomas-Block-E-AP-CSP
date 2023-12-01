#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int convert(string input);

int main(void)
{
    string input = get_string("Enter a positive integer: ");

    for (int i = 0, n = strlen(input); i < n; i++)
    {
        if (!isdigit(input[i]))
        {
            printf("Invalid Input!\n");
            return 1;
        }
    }

    // Convert string to int
    printf("%i\n", convert(input));
}

int convert(string input)
{
    int length = strlen(input);
    if (length == 0)
    {
        return 0;
    }
    int final = strlen(input) - 1;
    int output = (int) input[final] - '0';
    input[final] = '\0';
    return (convert(input) * 10) + output;
}


// I collaborated with Geoffrey
