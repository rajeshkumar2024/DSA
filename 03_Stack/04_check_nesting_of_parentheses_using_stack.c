#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX 10

int top = -1;
int stack[MAX];

void push(char item) {
    if(top == MAX-1) {
        printf("Stack Overflow!\n");
        return;
    }
    stack[++top] = item;
}

char pop() {
    if(top == -1) {
        printf("Stack Underflow!\n");
        exit(1);
    }
    return stack[top--];
}

int match(char a, char b) {
    if(a == '(' && b == ')')
        return 1;
    if(a == '{' && b == '}')
        return 1;
    if(a == '[' && b == ']')
        return 1;
    
    return 0;
}

int check(char exp[]) {
    int i;
    char temp;

    for(i=0; i<strlen(exp); i++) {
        
        if(exp[i] == '(' || exp[i] == '{' || exp[i] == '[') {
            push(exp[i]);
        }

        if(exp[i] == ')' || exp[i] == '}' || exp[i] == ']') {

            if(top == -1) {
                printf("Right parentheses are more than left\n");
                return 0;
            } else {
                temp = pop();
                
                if(!match(temp, exp[i])) {
                    printf("Mismatched parentheses are: ");
                    printf("%c and %c\n", temp, exp[i]);
                    return 0;
                }
            }
        }
    }

    if(top == -1) {
        printf("Balanced Parentheses\n");
        return 1;
    } else {
        printf("Unbalanced Parentheses\n");
        return 0;
    }
}

int main() {
    char str[MAX];
    int isValid;

    printf("Enter the expression: ");
    scanf("%s", str);

    isValid = check(str);

    if(isValid) {
        printf("Valid Expression\n");
    } else {
        printf("Invalid Expression\n");
    }

    return 0;
}