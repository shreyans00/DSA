#include <iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int a[n];
    for (int i=0; i<n; i++){
        cin>>a[i];
    }

    for (int i=0; i<n; i++){
        int loc=i;
        for (int j=i+1; j<n; j++){
            if(a[j]<a[i] && a[j]<a[loc]){
                loc = j;
            }
        }
        int temp = a[i];
        a[i] = a[loc];
        a[loc] = temp;
    }
    for (int i=0; i<n; i++){
        cout<<a[i]<<" ";
    }
    return 0;
}