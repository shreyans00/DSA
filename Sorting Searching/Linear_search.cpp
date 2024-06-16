#include <iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int a[n];
    for (int i=0; i<n; i++){
        cin>>a[i];
    }
    int key;
    cin>>key;
    
    bool flag=0;
    for (int i=0; i<n; i++){
        if (a[i]==key){
            flag=1;
            break;
        }
        else
            flag=0;
    }
    if (flag==1)
        cout<<"found";
    else
        cout<<"not found";
    return 0;
}