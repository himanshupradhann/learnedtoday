#include <stdio.h>

void* sum (void *a,void *b){

    void* sum=*a+*b;
    return sum;


}

int main (void){
    double x=10;
    double y=20;
    void* s =sum(&x,&y);
    printf("%f ",*(double*)s);
    return 0;
}