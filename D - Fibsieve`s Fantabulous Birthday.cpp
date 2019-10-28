
#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    int tc;
    cin>>tc;
    for(int t=1;t<=tc;t++)
    {
        ll n,r,c;
        cin>>n;
        ll s=sqrt(n);
        ll dif=n-(s*s);
        if(s*s==n)
        {
            if(n%2==0)
            {
                r=1;
                c=s;
            }
            else
                {
                    r=s;
                    c=1;
                }
        }
        else
        {
            if(s%2==0)
            {
                if(dif<=s+1)
                    {
                        r=dif;
                        c=s+1;
                    }
                else
                {
                    r=s+1;
                    c=(s+1)-dif%(s+1);
                }
            }
            else
            {
                if(dif<=s+1)
                {
                    r=s+1;
                    c=dif;
                }
                else{
                    r=(s+1)-dif%(s+1);
                    c=s+1;
                }
            }
        }
        cout<<"Case "<<t<<": "<<c<<" "<<r<<endl;
    }
}
