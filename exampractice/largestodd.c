#include <stdio.h>

int main(void){

    printf("Enter Size of string: ");
    int n;
    scanf("%d", &n);

    char s[n + 1];
    printf("Enter the string: ");
    scanf("%s", s);
    
    int left = 0;
    int right = n - 1; // FIX 1: Set right to the last valid index (n-1)

    while (left <= right) { // FIX 2: Allowed left == right to process the last character
        if (s[left] - '0' == 0) {
            left++;
        }
        else if ((s[right] - '0') % 2 == 0) { // FIX 3: Cleaned up even check
            right--;
        }
        else {
            // FIX 4: If left is not '0' and right is odd, your code stuck.
            // Breaking out prevents the infinite loop.
            break; 
        }
    }
    
    // Print the remaining substring
    for (int i = left; i <= right; i++) {
        printf("%c", s[i]);
    }
    printf("\n");

    return 0;
}
