#include <stdio.h>

int main(void){
    int n,m;
    printf("Enter Size :");
    scanf("%d",&n);
    m=n;
    char str[n+1];
    printf("Enter String :");
    scanf("%s",str);
    int i=0;
    n-=1;
    while(i!=m/2){
        if(*(str+i)!=*(str+n)){
            printf("Not a Palindrome ");
            return 0;
        }
        else{
            printf("Palindrome ");
            return 0;
        }
        i++;
        n--;
    }

    for(int j=0;j<=m;j++){
        printf("%c ",str[j]);
    }
}