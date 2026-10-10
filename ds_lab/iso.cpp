#include <iostream>
#include <string>
using namespace std;

int main(void){

    string a="egg";
    string b="add";

    if(a.length()!=b.length()){
        printf("Not possible");
        return 0;
    }
    
    int freqA[256]={0};
    int freqB[256]={0};

    for(int i=0;i<a.length();i++){
        freqA[a[i]]=i+1;
        freqB[b[i]]=i+1;

        if(freqA[a[i]]!=freqB[b[i]]){
            printf("NOT ISOMETRIC");
            return 0;
        }

    }
    printf("ISOMETRIC");

    return 0;
}