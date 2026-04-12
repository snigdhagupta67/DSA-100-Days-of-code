#include <stdio.h>
#include <string.h>

#define EMPTY -1

int table[100];  


int hash(int key, int m) {
    return key % m;
}


void insert(int key, int m) {
    int i = 0;
    int index;

    while (i < m) {
        index = (hash(key, m) + i * i) % m;

        if (table[index] == EMPTY) {
            table[index] = key;
            return;
        }
        i++;
    }
    printf("Hash Table Full\n");
}


void search(int key, int m) {
    int i = 0;
    int index;

    while (i < m) {
        index = (hash(key, m) + i * i) % m;

        if (table[index] == key) {
            printf("FOUND\n");
            return;
        }
        if (table[index] == EMPTY) {
            break; // not present
        }
        i++;
    }
    printf("NOT FOUND\n");
}

int main() {
    int m, q;
    scanf("%d", &m);   
    scanf("%d", &q);   

    
    for (int i = 0; i < m; i++) {
        table[i] = EMPTY;
    }

    char op[10];
    int key;

    for (int i = 0; i < q; i++) {
        scanf("%s %d", op, &key);

        if (strcmp(op, "INSERT") == 0) {
            insert(key, m);
        } else if (strcmp(op, "SEARCH") == 0) {
            search(key, m);
        }
    }

    return 0;
}