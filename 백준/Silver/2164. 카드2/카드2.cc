#include <iostream>
using namespace std;


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int size;
    cin>>size;
    
    int i{1};
    while(i<size)
        i<<=1;
    
    cout<<(size<<1)-i;
    
    
}