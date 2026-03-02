#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {
    int n, k;
    scanf("%d", &n);

    if(n == 0) return 0;

    struct Node *head = NULL, *temp = NULL, *newNode = NULL;

    
    for(int i = 0; i < n; i++) {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        scanf("%d", &newNode->data);
        newNode->next = NULL;

        if(head == NULL) {
            head = newNode;
            temp = head;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    scanf("%d", &k);

    
    k = k % n;
    if(k == 0) {
        temp = head;
        while(temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        return 0;
    }

    
    temp->next = head;

    
    int steps = n - k;
    struct Node* current = head;
    for(int i = 1; i < steps; i++) {
        current = current->next;
    }

    head = current->next;
    current->next = NULL;

    
    temp = head;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}