#include <stdio.h>
#include <stdlib.h>

#define MAX 1000


struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};


struct Pair {
    struct Node* node;
    int hd;
};

struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->left = newNode->right = NULL;
    return newNode;
}


struct Node* buildTree(int arr[], int n) {
    if (arr[0] == -1) return NULL;

    struct Node* root = createNode(arr[0]);
    struct Node* queue[MAX];
    int front = 0, rear = 0;

    queue[rear++] = root;
    int i = 1;

    while (front < rear && i < n) {
        struct Node* curr = queue[front++];

        if (arr[i] != -1) {
            curr->left = createNode(arr[i]);
            queue[rear++] = curr->left;
        }
        i++;

        if (i < n && arr[i] != -1) {
            curr->right = createNode(arr[i]);
            queue[rear++] = curr->right;
        }
        i++;
    }
    return root;
}


void verticalOrder(struct Node* root) {
    if (!root) return;

    struct Pair queue[MAX];
    int front = 0, rear = 0;

    int hd[MAX];          
    int values[MAX][MAX]; 
    int count[MAX] = {0};

    int offset = MAX / 2;  

    queue[rear++] = (struct Pair){root, 0};

    while (front < rear) {
        struct Pair temp = queue[front++];
        struct Node* node = temp.node;
        int h = temp.hd + offset;

        values[h][count[h]++] = node->data;

        if (node->left)
            queue[rear++] = (struct Pair){node->left, temp.hd - 1};
        if (node->right)
            queue[rear++] = (struct Pair){node->right, temp.hd + 1};
    }


    for (int i = 0; i < MAX; i++) {
        if (count[i] > 0) {
            for (int j = 0; j < count[i]; j++) {
                printf("%d ", values[i][j]);
            }
            printf("\n");
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct Node* root = buildTree(arr, n);
    verticalOrder(root);

    return 0;
}