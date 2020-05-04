#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
int main()
{
    int T;
    cin>>T;
    for(int t=1; t<=T; t++)
    {
        ull n;
        cin>>n;
        if(n%2!=0)
            cout<<"Case "<<t<<": Impossible"<<endl;
        else{
            ull p = 1;
            while(n%2==0)
            {
                p*=2;
                n/=2;
            }
            cout<<"Case "<<t<<": "<<n<<" "<<p<<endl;
        }
    }
}
