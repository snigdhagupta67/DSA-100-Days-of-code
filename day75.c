#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int sum = 0, maxLen = 0;

    // Hashing using array (for simplicity)
    // Assuming sum range is limited
    int hash[1000];
    for(int i = 0; i < 1000; i++) {
        hash[i] = -2; // -2 means not visited
    }

    hash[0] = -1; // Important: sum 0 at index -1

    for(int i = 0; i < n; i++) {
        sum += arr[i];

        int index = sum + 500; // shift to avoid negative index

        if(hash[index] != -2) {
            int length = i - hash[index];
            if(length > maxLen) {
                maxLen = length;
            }
        } else {
            hash[index] = i;
        }
    }

    printf("%d\n", maxLen);

    return 0;
}