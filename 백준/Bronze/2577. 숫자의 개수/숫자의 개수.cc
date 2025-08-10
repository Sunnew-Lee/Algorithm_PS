#include <iostream>

using namespace std;

int arr[10];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int a,b,c{1};
    cin>>a>>b>>c;
    c*=a*b;
    
    while(c)
    {
        arr[c%10]++;
        c/=10;
    }
    
    for(int& num:arr)
    {
        cout<<num<<'\n';
    }
    
    return 0;
}