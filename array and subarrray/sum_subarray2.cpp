#include <iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int a[n];
    for (int i=0; i<n; i++){
        cin>>a[i];
    }
    int key;     // whose value to be matched with sum of subarray
    cin>>key;

    int s=0,e,sum = 0;
    bool flag = 0;
    for (int i=0; i<=n; i++){
        e=i;
        if (sum==key){
            cout<<s+1<<" "<<e<<endl;
            flag=1;
            return 0;
        }
        if (sum>key && s<e){
            sum-=a[s];
            s++;
            i--;
        }
        else{
            sum+=a[i];
        }
    }
    if (flag==0){
        cout<<"No such combination exist"<<endl;
    }
    return 0;
}