#include <iostream>
using namespace std;

// 1
// 2 3
// 4 5 6
// 7 8 9 10
// 11 12 13 14 15

int main(){
    int n,t=1;
    cin>>n;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            if (i>=j){
                cout<<t++<<" ";
            }
            else{
                cout<<"  ";
            }
        }
        cout<<endl;
    }
    return 0;
}