#include <iostream>
using namespace std;

//     1 
//    1 2
//   1 2 3
//  1 2 3 4
// 1 2 3 4 5

int main(){
    int n;
    cin>>n;
    for (int i=1; i<=5; i++){
        int space = n-i;
        for (int k=1; k<=space; k++){
            cout<<" ";
        }
        for (int j=1; j<=i; j++){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}