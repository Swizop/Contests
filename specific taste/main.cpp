#include <iostream>

using namespace std;
struct
{
    int ok,val;
}a[104][104];
int vi[5]={0,0,1,0,-1};
int vj[5]={0,1,0,-1,0};
void verific(int i,int j)
{
    for(int k=1;k<=4;k++)
        if(a[i][j].val==a[i+vi[k]][j+vj[k]].val&&a[i+vi[k]][j+vj[k]].ok==0)
            {
                a[i][j].ok=1;
                a[i][j].val++;
                for(int k=1;k<=4;k++)
                    if(a[i][j].val==a[i+vi[k]][j+vj[k]].val&&a[i+vi[k]][j+vj[k]].ok==1)
                    {
                        a[i+vi[k]][j+vj[k]].ok=0;
                        a[i+vi[k]][j+vj[k]].val--;
                    }
            }
        else

}
int main()
{
    int t,n,m,i,j;
    cin>>t;
    for(int it=1;it<=t;it++)
    {
        cin>>n>>m;
        for(i=0;i<=n+1;i++)
            a[i][0].val=a[i][m+1].val=a[i][0].ok=a[i][m+1].ok=0;
        for(j=0;j<=m+1;j++)
            a[0][j].val=a[n+1][j].val=a[0][j].ok=a[n+1][j].ok=0;


        for(i=1;i<=n;i++)
            for(j=1;j<=m;j++)
                cin>>a[i][j].val;
        for(i=1;i<=n;i++)
            for(j=1;j<=m;j++)
                verific(i,j);
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
                cout<<a[i][j].val<<" ";
            cout<<endl;
        }
    }
    return 0;
}
