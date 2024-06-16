#include <iostream>
using namespace std;

//         1 
//       2 1 2
//     3 2 1 2 3
//   4 3 2 1 2 3 4
// 5 4 3 2 1 2 3 4 5

int main(){
    int n;
    cin>>n;
    for (int i=1; i<=n; i++){
        for (int k=1; k<=n-i; k++){
            cout<<"  ";
        }
        int temp = i;
        for (int j=1; j<=i; j++){
            cout<<temp--<<" ";
        }
        for (int m=2; m<=i; m++){
            cout<<m<<" ";
        }
        cout<<endl;
    }
    return 0;
}