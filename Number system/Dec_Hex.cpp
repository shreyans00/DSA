#include <bits/stdc++.h>
using namespace std;

string dec_hex(int n){
    int x=1;
    string ans = "";        // initialise
    while (x<=n){           // to know what maxm power of 16 required
        x*=16;
    }
    x/=16;          // x multiplied with 16 one extra times
    while (x>0){
        int lastDigit = n/x;       // lastDigit from last i.e. firstDigit
        n-=lastDigit*x;
        x/=16;
        
        if (lastDigit<=9)
            ans+= to_string(lastDigit);        // to_string to convert int to string
        else{
            char c = 'A' + lastDigit - 10;
            ans.push_back(c);                  // used to push elements into a vector from the back 
            // can also write this-  ans+=c;
        }
    }
    return ans;
}

int32_t main(){
    int n;
    cin>>n;

    cout<< dec_hex(n)<< endl;
    return 0;
}