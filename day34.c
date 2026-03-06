#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct node {
    int data;
    struct node *next;
};

struct node *top = NULL;

void push(int x) {
    struct node *temp;
    temp = (struct node*)malloc(sizeof(struct node));
    temp->data = x;
    temp->next = top;
    top = temp;
}

int pop() {
    struct node *temp;
    int x;
    temp = top;
    x = temp->data;
    top = top->next;
    free(temp);
    return x;
}

int main() {
    char exp[100];
    int i = 0, op1, op2, result;

    printf("Enter postfix expression: ");
    fgets(exp, sizeof(exp), stdin);

    while (exp[i] != '\0') {

        if (isdigit(exp[i])) {
            push(exp[i] - '0');
        }

        else if (exp[i]=='+' || exp[i]=='-' || exp[i]=='*' || exp[i]=='/') {
            op2 = pop();
            op1 = pop();

            switch(exp[i]) {
                case '+': result = op1 + op2; break;
                case '-': result = op1 - op2; break;
                case '*': result = op1 * op2; break;
                case '/': result = op1 / op2; break;
            }

            push(result);
        }

        i++;
    }

    printf("%d", pop());

    return 0;
}