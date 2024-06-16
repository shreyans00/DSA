// Got no idea what is being asked in the program

#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    // Method 1
    int ans = 2, pd = a[1] - a[0], i = 2, curr = 2;
    while (i < n)
    {
        if (pd == a[i] - a[i - 1])
        {
            curr++;
        }
        else
        {
            pd = a[i] - a[i - 1];
            curr = 2;
        }
        ans = max(ans, curr);
        i++;
    }
    cout << ans << endl;

    // Method 2
    // int max=0,c=2;
    // for (int i=1; i<=n; i++){
    //     if (a[i]-a[i-1] == a[i+1]-a[i]){
    //         c+=1;
    //     }
    //     else{
    //         if (max<c)
    //             max = c;
    //         c=2;
    //         continue;
    //     }
    // }
    // cout<<max;
    return 0;
}