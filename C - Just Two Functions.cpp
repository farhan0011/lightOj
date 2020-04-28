#include<bits/stdc++.h>
using namespace std;
#define ll long long
/**
a1  b1  0  0  0  c1
1   0   0  0  0   0
0   1   0  0  0   0
0   0  c2 a2 b2   0
0   0   0  1  0   0
0   0   0  0  1   0
*/
ll a1,b1,c1,a2,b2,c2,mod,f0,f1,f2,g0,g1,g2,n;
struct matrix
{
    ll mat[6][6];
    matrix (int type)
    {
        memset(mat,0,sizeof mat);
        if(type == 1)
        {
            for(int i=0,j=0;i<6,j<6;i++,j++)
                mat[i][j] = 1;
//            cout<<"unit matrix :"<<endl;
//            for(int i=0;i<6;i++)
//            {
//                for(int j=0;j<6;j++)
//                    cout<<mat[i][j]<<" ";
//                cout<<endl;
//            }
        }
        if(type == 2)
        {
            mat[0][0] = a1;
            mat[0][1] = b1;
            mat[0][5] = c1;
            mat[1][0] = 1;
            mat[2][1] = 1;
            mat[3][2] = c2;
            mat[3][3] = a2;
            mat[3][4] = b2;
            mat[4][3] = 1;
            mat[5][4] = 1;
        }
    }
};
matrix mulMat(matrix a,matrix b)
{
    ///cout<<"MUL"<<endl;
    matrix ans = matrix(0);
    for(int i=0; i<6; i++)
    {
        for(int j=0; j<6; j++)
        {
            for(int k=0; k<6; k++)
            {
                ans.mat[i][j] = (ans.mat[i][j] + a.mat[i][k] * b.mat[k][j])% mod;
            }
        }
    }
    return ans;
}
matrix matBigMod(matrix x,int y)
{
    if(!y)return matrix(1);
    if(y%2)
        return mulMat(matBigMod(x,y-1),x);
    matrix ans = matBigMod(x,y/2);
    return mulMat(ans,ans);
}
int main()
{
    int T;
    cin>>T;
    for(int t=1; t<=T; t++)
    {
        cin>>a1>>b1>>c1;
        cin>>a2>>b2>>c2;
        cin>>f0>>f1>>f2;
        cin>>g0>>g1>>g2;
        cin>>mod;
//        matrix test(2);
//        for(int i=0;i<6;i++)
//        {
//            for(int j=0;j<6;j++)
//                cout<<test.mat[i][j]<<" ";
//                cout<<endl;
//        }
        int q;
        cin>>q;
        cout<<"Case "<<t<<": "<<endl;;
        while(q--)
        {
            cin>>n;
            if(n == 0)
                cout<<f0%mod<<" "<<g0%mod<<endl;
            else if(n == 1)
                cout<<f1%mod<<" "<<g1%mod<<endl;
            else if(n == 2)
                cout<<f2%mod<<" "<<g2%mod<<endl;
            else
            {
                matrix tmp = matrix(2);
                tmp = matBigMod(tmp,n-2);
//                for(int i=0;i<6;i++)
//                {
//                    for(int j=0;j<6;j++)
//                        cout<<tmp.mat[i][j]<<" ";
//                    cout<<endl;
//                }
                //cout<<endl;
                ll f = ( (tmp.mat[0][0]*f2)%mod + (tmp.mat[0][1]*f1)%mod + (tmp.mat[0][2]*f0)%mod + (tmp.mat[0][3]*g2)%mod + (tmp.mat[0][4]*g1)%mod +(tmp.mat[0][5]*g0)%mod )%mod;
                ll g = ( (tmp.mat[3][0]*f2)%mod +(tmp.mat[3][1]*f1)%mod+ (tmp.mat[3][2]*f0)%mod + (tmp.mat[3][3]*g2)%mod+ (tmp.mat[3][4]*g1)%mod + (tmp.mat[3][5]*g0)%mod )%mod;
                cout<<f<<" "<<g<<endl;
            }
        }
    }
}
