#include <iostream>
#include <string>
using namespace std;

int main(void){

    string str;
    cout << "enter the STRING"<<endl;
    cin >> str;
    int left=0;
    int right=str.length()-1;
    
    while(left<=right){
        char temp=str[left];
        str[left]=str[right];
        str[right]=temp;
        left++;
        right--;
    }
    cout<< str;
    return 0;
}