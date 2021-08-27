#include <iostream>
#include <cmath>
using namespace std;

int verif(int a ,int b,int &c)
{
    if ( (int)(log10(a))<(int)(log10(b)))
        return -1;
    int x=a,k=1,y;
    while(x)
    {
        k*=10;
        x/=10;
    }
    while (k)
    {
        x= a/k*k+ 9*(k/10)+a%(k/10);
        if(x>b)
        {
            c=1;
            return x;
        }
        if(k>b)
            y= b/k*k+ 1*(k/10)+b%(k/10);
        else
            y= b/k*k+b%(k/10);
        if(a>y)
        {
            c=2;
            return y;
        }
        k/=10;
    }
    return -1;
}
int main()
{
    int n,v[105],i,c,w[105],ok=0;
    cin>>n;
    cin>>v[1];
    w[1]=v[1];
    for(i=2;i<=n;i++)
    {
        cin>>v[i];
        w[i]=v[i];
        if(ok==0)
        {
            int q=verif(v[i-1],v[i],c);
            if (q!=-1)
            {
                ok=1;
                if(c==1)
                    w[i-1]=q;
                else
                    w[i]=q;
            }
        }
    }
    if(ok==0)
        cout<<"impossible";
    else
        for(i=1;i<=n;i++)
            cout<<w[i]<<" ";
    return 0;
}
