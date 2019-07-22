#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        double a,b;
        char ch;
        cin>>a>>ch>>b;
        double r=sqrt(a*a+b*b)/2.0;
        //cout<<"r="<<r<<endl;
        double tetha=acos((r*r + r*r - b*b)/(2.0 * r * r));
        //cout<<"tetha="<<tetha<<endl;
        double s=r*tetha;
        //cout<<"s="<<s<<endl;
        double x=400.0/(2.0*s+2.0*a);
        cout<<setprecision(10)<<"Case "<<i<<": "<<x*a<<" "<<x*b<<endl;
    }
}
