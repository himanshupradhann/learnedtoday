#include <stdio.h>


int main(void) {
  
  char final[20];
  int count =-1;
  int n ;
  printf("Enter the size of array");
  scanf("%d",&n);

  char str [n][20];
    

  printf("Enter strings\n");

  for(int i=0;i<n;i++){ 
    scanf("%s",str[i]);
  }
    
  for(int j=0;str[0][j]!='\0';j++){
    for(int k=0;str[1][k]!='\0';k++){
      if(str[0][j]==str[1][k]){
        final[++count]=str[0][j];
      }
    }
  }
-1


}
