// Program to find the smallest positive number missing in the array

#include <iostream>
#include <climits>
using namespace std;

int main(){
    int n;
    cin>>n;
    int a[n];
    for (int i=0; i<n; i++){
        cin>>a[i];
    }
    int N = 1e6+2;
    bool b[N];
    for (int i=0; i<n; i++){
        b[i] = false;
    }
    for (int i=0; i<n; i++){
        if (a[i]>0){
            int m = a[i];
            b[m] = true;
        }
    }
    for (int i=1; i<=N; i++){
        if (b[i]==false){
            cout<<i<<endl;
            return 0;
        }
    }
    return 0;
}