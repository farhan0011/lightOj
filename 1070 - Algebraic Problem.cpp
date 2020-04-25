#include<bits/stdc++.h>
#define ll  long long int
#define ull unsigned long long int
using namespace std;
int n;
struct matrix
{
    ull mat[2][2];
    matrix (int type)
    {
        memset(mat,0,sizeof mat);
        if(type == 1)
            mat[0][0] = mat[1][1] = 1;
        if(type == 2)
            {
                //cout<<"p = "<<p<<" q = "<<q<<endl;
                mat[0][0] = 1;
                mat[0][1] = 1;
                mat[1][0] = 1;
            }
    }
};
matrix matMul(matrix a,matrix b)
{
    matrix ans = matrix(0);
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<2;j++)
        {
            for(int k=0;k<2;k++)
                ans.mat[i][j] = (ans.mat[i][j]+a.mat[i][k] *b.mat[k][j]);
        }
    }
//    for(int i=0;i<2;i++)
//        {
//            for(int j=0;j<2;j++)
//                cout<<ans.mat[i][j]<<" ";
//            cout<<endl;
//        }
    return ans;
}
ull p,q;
matrix matBigMod(matrix x,int y)
{
    if(!y)
        return matrix(1);
    if(y%2)
        return matMul(matBigMod(x,y-1),x);
    matrix ans = matBigMod(x,y/2);
    return matMul(ans,ans);
}
int main()
{
    int T;
    cin>>T;
    for(int t=1; t<=T; t++)
    {
        cin>>p>>q>>n;
        if(abs(n)<1)
            cout<<"Case "<<t<<": "<<2<<endl;
        else if(n == 1)
            cout<<"Case "<<t<<": "<<p<<endl;
        else
        {
            matrix temp = matrix(0);
            temp.mat[0][0] = (ull) p;
            temp.mat[0][1] = -q;
            temp.mat[1][0] = 1;
            temp.mat[1][1] = 0;
        temp = matBigMod(temp,n-1);
        /**
        a^n+b^n
        if n=0,base = 2;
        if n = 1 ,base = (a+b) = p;
        */
//        for(int i=0;i<2;i++)
//        {
//            for(int j=0;j<2;j++)
//                cout<<temp.mat[i][j]<<" ";
//            cout<<endl;
//        }
        cout<<"Case "<<t<<": "<<temp.mat[0][0]*p+2*temp.mat[0][1]<<endl;
        }
    }
}
