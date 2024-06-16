#include <iostream>
using namespace std;

//     * * * * * 
//    * * * * *
//   * * * * *
//  * * * * *
// * * * * *

int main(){
    int n, space;
    cin>>n;
    for (int i=1; i<=n; i++){
        space = n-i;
        for (int k=1; k<=space; k++){
            cout<<" ";
        }
        for (int j=1; j<=n; j++){
            cout<<"* ";
        }
        cout<<endl;
    }
    return 0;
}