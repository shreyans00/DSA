#include <iostream>
using namespace std;

//       * 
//     * * *
//   * * * * *
// * * * * * * *
// * * * * * * *
//   * * * * *
//     * * *
//       *

int main(){
    int n;
    cin>>n;
    for (int i=1; i<=n; i++){
        for (int k=1; k<=n-i; k++){
            cout<<"  ";
        }
        for (int j=n; j>=n-i+1; j--){
            cout<<"* ";
        }
        int temp = i-1;
        while(temp){
            cout<<"* ";
            temp--;
        }
        cout<<endl;
    }
    for (int i=n; i>=1; i--){          // only change required in this line to reflect it along x-axis
        for (int k=1; k<=n-i; k++){
            cout<<"  ";
        }
        for (int j=n; j>=n-i+1; j--){
            cout<<"* ";
        }
        int temp = i-1;
        while(temp){
            cout<<"* ";
            temp--;
        }
        cout<<endl;
    }
    return 0;
}