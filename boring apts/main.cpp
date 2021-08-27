#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int t,x,s,k;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        cin>>x;
        s=10*(x%10-1);
        k=0;
        while(x)
        {
            k++;
            s=s+k;
            x/=10;
        }
        cout<<s<<endl;
    }
    return 0;
}
