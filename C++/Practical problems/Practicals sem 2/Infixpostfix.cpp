#include <iostream>
using namespace std; 
#include <cstring>ABA
#define MAX 50
char stack[MAX];
int top = -1;
void push(char c)
{
    stack[++top] = c;
}
char pop()
{
    return stack[top--];
}
int prec(char c)
{
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return 0;
}
void infixToPostfix(char infix[])
{
    char postfix[MAX];
    int i, k = 0;
    char c;

    for(i = 0; infix[i] != '\0'; i++)
    {
        c = infix[i];

        if((c >= 'a' && c <= 'z') ||
           (c >= 'A' && c <= 'Z') ||
           (c >= '0' && c <= '9'))
        {
            postfix[k++] = c;
        }

        else if(c == '(')
        {
            push(c);
        }
        else if(c == ')')
        {
            while(stack[top] != '(')
            {
                postfix[k++] = pop();
            }
            pop(); 
        }
        else
        {
            while(top != -1 && prec(stack[top]) >= prec(c))
            {
                postfix[k++] = pop();
            }
            push(c);
        }
    }
    while(top != -1)
    {
        postfix[k++] = pop();
    }
    postfix[k] = '\0';
    cout << "\nPostfix Expression: " << postfix;
}
int main()
{
    char infix[MAX];
    cout << "Enter Infix Expression: ";
    cin >> infix;
    infixToPostfix(infix);
    return 0;
}