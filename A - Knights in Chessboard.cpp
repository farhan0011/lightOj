#include<bits/stdc++.h>
using namespace std;
/*
n==2||m==2
HH
HH
AA
AA

HHAA
HHAA
that's mean 4ta kore 
sajabo
OR
HAHAHA
AHAHAH
HAHAHA
*/
int res(int m,int n)
{
    if(n==1||m==1)
        return n*m;
    int c,m1,m2,n1,n2,ans;
    int mn = m*n;
    if(n==2||m==2)
    {
        if(n==2)
            c=m;
        else
            c=n;
        if(c%4==0)
            ans=c;
        else if(c%4==1)
            ans=c+1;
        else if(c%4==2)
            ans=c+2;
        else if(c%4==3)
            ans=c+3;
    }
    else if(mn%2==0)
        ans=mn/2;
    else
        ans=1+mn/2;
    return ans;


}
int main()
{
    int t;
    cin>>t;
    for(int tc=1;tc<=t;tc++)
    {
        int m,n,m1,m2,n1,n2;
        cin>>m>>n;
        cout<<"Case "<<tc<<": "<<res(m,n)<<endl;
    }
}
/*25
1 2
1 1
2 1
2 2
2 3
2 4
2 5
2 6
2 7
2 8
2 9
2 2
3 2
4 2
5 2
6 2
7 2
8 2
9 2
10 2
6 3
200 200
101 3
2 103
*/
