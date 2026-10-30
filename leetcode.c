#include <stdio.h>

#define MAX 100

int main()
{
    char s[MAX];
    char stack[MAX];
    int top = -1;
    int i, valid = 1;

    printf("Enter brackets: ");
    scanf("%s", s);

    for (i = 0; s[i] != '\0'; i++)
    {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{')
        {
            top++;
            stack[top] = s[i];
        }
        else
        {
            if (top == -1)
            {
                valid = 0;
                break;
            }

            if ((s[i] == ')' && stack[top] != '(') ||
                (s[i] == ']' && stack[top] != '[') ||
                (s[i] == '}' && stack[top] != '{'))
            {
                valid = 0;
                break;
            }

            top--;
        }
    }

    if (top != -1)
        valid = 0;

    if (valid == 1)
        printf("True");
    else
        printf("False");

    return 0;
}
