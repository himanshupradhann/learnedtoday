#include <stdio.h>

#define MAX_VAL 100000 // Constraint: 1 to 10^5

// Global or static arrays are automatically initialized to 0 and avoid stack overflow
int freq[MAX_VAL + 1]; 

int main(void) {
    int arr[] = {1, 2, 3, 3,2, 3, 4, 3, 2, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    // 1. Populate frequencies instantly in O(1) per element
    for (int i = 0; i < n; i++) {
        freq[arr[i]]++;
    }

    // 2. Scan the frequency table to find the maximum occurrence
    int max_freq = 0;
    int most_frequent_num = 0;
    int secound=1;

    for (int i = 1; i <= MAX_VAL; i++) {
        if (freq[i] > max_freq) {
            max_freq = freq[i];
            most_frequent_num = i;
        }
        secound=i;
    }

    // Note: This logic picks '2' because it's the first to hit frequency 4.
    printf("NUMBER :%d ", most_frequent_num);
    printf("occurance :%d %d\n", max_freq,secound);

    return 0;
}
