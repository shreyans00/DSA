#include <iostream>
using namespace std;

// *             * 
// * *         * * 
// * * *     * * * 
// * * * * * * * * 
// * * * * * * * * 
// * * *     * * * 
// * *         * *
// *             *

int main(){
    int n;
    cin>>n;
    for (int i=1; i<=n; i++){           // for upper half
        for (int j=1; j<=i; j++){
            cout<<"* ";
        }
        int space = 2*n - 2*i;          // number of spaces between 2 stars
        for (int j=1; j<=space; j++){
            cout<<"  ";
        }
        for (int j=1; j<=i; j++){
            cout<<"* ";
        }
        cout<<endl;
    }
    for (int i=n; i>=1; i--){           // for lower half
        for (int j=1; j<=i; j++){
            cout<<"* ";
        }
        int space = 2*n - 2*i;
        for (int j=1; j<=space; j++){
            cout<<"  ";
        }
        for (int j=1; j<=i; j++){
            cout<<"* ";
        }
        cout<<endl;
    }
    return 0;
}