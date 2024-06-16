// Here we have to find the number of local maxima in 20 sec time complexity
// 10^8 operations can be done in 1 sec

#include "iostream"
using namespace std;

// Time Complexity of the program should be smaller than O(n2), so we can't think of nested loops
// In this code, time complexity is O(n)
int main(){
    int n;
    cin>>n;
    int a[n+1];
    a[n] = -1;     // so that a[n-1] is always greater than a[n], since all elements of a are positive
    for (int i=0; i<n; i++){
        cin>>a[i];
    }
    if (n==1){
        cout<<"1"<<endl;
        return 0;
    }
    int ans = 0, mx = -1;
    for (int i=0; i<n; i++){
        if (a[i]>mx && a[i]>a[i+1]){
            ans++;
        }
        mx = max(mx,a[i]);
    }
    cout << ans << endl;
    return 0;
}