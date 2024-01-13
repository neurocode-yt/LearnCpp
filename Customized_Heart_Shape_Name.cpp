#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

int main() {
    system("color C");
    string name = "NeuroCode";
    int n = name.length();
    int i,j;

    for(i = n/2; i<=n; i+=2)
    {
        for(j=1; j<n-i; j+=2)
        {
            cout<<" ";
        }
        for(j=1; j<=i; j++)
        {
            cout<<name[(j-1)%n];
        }
        for(j=1; j<=n-i; j++)
        {
            cout<<" ";
        }
        for(j=1;j<=i; j++)
        {
            cout<<name[(j-1)%n];
        }
        cout<<endl;
    }
    for(i=n; i>=1; i--)
    {
        for(j=i; j<n; j++)
        {
            cout<<" ";
        }
        for(j=1; j<=(i*2)-1; j++)
        {
            cout<<name[(j-1)%n];
        }
        cout<<endl;
    }
    return 0;
}
