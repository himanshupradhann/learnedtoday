#include <iostream>
#include <string>
using namespace std;

int main (void){

    string s1,s2;
    printf("ENTER STRING 1 :");
    cin >> s1;
    printf("ENTER STRING S2 :");
    cin >> s2;
    int freq[256]={0};

    if(s1.length()!=s2.length()){
        printf("Not possible");
        return 0;
    }

    for(int i=0;i<s1.length();i++){
        freq[s1[i]]++;
        freq[s2[i]]--;
    }

    for(int j=0;j<256;j++){
        if(freq[j]!=0){
            cout << "Not possible";
            return 0;
        }
    }

    cout<< "possible";

    return 0;
}