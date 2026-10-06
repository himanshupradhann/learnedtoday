#include <stdio.h>

void initilise(int *freq,int max){
    for(int i=0;i<=max;i++){
        *(freq+i)=0;
    }
}

void populate(int *arr,int n,int freq[]){
    for(int i=0;i<n;i++){
        freq[arr[i]]++;
    }
}

int maxvalue(int *arr,int n){
    int max=0;
    for(int i=0;i<n;i++){
        if(*(arr+i)>max){
            max=*(arr+i);
        }
    }
    return max;
}

int secoundhighest(int max,int freq[]){
    int highest=0;
    int sec=0;
    int high_element=0;
    int sec_element=0;

    for(int i=1;i<=max;i++){
        if(freq[i]>highest){
            sec=highest;
            highest=freq[i];
            sec_element=high_element;
            high_element=i;
        }
        else if(freq[i] > sec && freq[i] < highest){ 
            sec = freq[i]; 
            sec_element=i;
        }
    }
    int sum=sec_element+high_element;
    return sum;
}

int main(void){
    int arr[]={1,1,2,3,4,1,2,4,5,6,6,4,4};
    int n=sizeof(arr)/sizeof(arr[0]);
    int max=maxvalue(arr,n);
    int freq[max+1];
    initilise(freq,max);
    populate(arr,n,freq);
    int sec=secoundhighest(max,freq);

    printf("%d \n",sec);

    for(int j=1;j<=max;j++)
     {printf("%d ",freq[j]);
     }
}