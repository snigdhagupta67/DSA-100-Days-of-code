//Problem: Implement linear search to find key k in an array. Count and display the number of comparisons performed.
#include <stdio.h>
#define MAX_SIZE 100

int main() {
    int arr[MAX_SIZE];
    int n, k;
    int i;
    int comparisons;
    int found_index;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    scanf("%d", &k);
    comparisons = 0;
    found_index = -1; 

    for (i = 0; i < n; i++) {
        comparisons++; 
        
        if (arr[i] == k) {
            found_index = i;
            break;
        }
    }
    if (found_index != -1) {
        printf("Found at index %d\n", found_index);
    } else {
        printf("Not Found\n");
    }

    printf("Comparisons = %d\n", comparisons);

    return 0;
}