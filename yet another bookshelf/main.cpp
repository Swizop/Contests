#include <iostream>

using namespace std;

int main()
{
    int t,n,a,nr,j,fin;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        cin>>n>>a;
        j=2;
        while(j<=n&&a!=1)
        {
            cin>>a;
            j++;
        }
        nr=fin=0;
        while(j<=n)
        {
            cin>>a;
            if(a==1)
            {
                fin=fin+nr;
                nr=0;
            }
            else
                nr++;
            j++;
        }
        cout<<fin<<endl;
    }
    return 0;
}
