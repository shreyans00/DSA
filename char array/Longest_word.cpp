// Program to find and print the longest word in a sentence formed by group of character arrays 

#include <iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    cin.ignore();
    char arr[n+1];        // 1 for \0
    
    cin.getline(arr,n);    // used to take space as input also, otherwise we can simply use cin>>arr
    cin.ignore();          // used to remove buffer

    int i=0, currlen = 0, maxlen = 0, st = 0, maxst = 0;;
    while(1){
        if (arr[i] == ' ' || arr[i] == '\0'){
            if (currlen > maxlen){
                maxlen = currlen;
                maxst = st;
            }
            currlen = 0;
            st = i+1;
        }
        else{
            currlen++;
        }
        if (arr[i] == '\0')
            break;
        i++;
    }
    cout<<maxlen<<endl;
    for (int i=0; i<maxlen; i++){
        cout<<arr[i+maxst];
    }
    return 0;

}