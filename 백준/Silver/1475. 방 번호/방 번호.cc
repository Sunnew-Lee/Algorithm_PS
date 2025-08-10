#include <iostream>
#include <algorithm>

using namespace std;

int arr[9];    //arr[6] == arr[6]+arr[9]

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int N;
    cin>>N;
    
    while(N)
    {
        int temp = N%10;
        if(temp == 9)
        {
            arr[6]++;
        }
        else
            arr[temp]++;
        N/=10;
    }
    arr[6]=(arr[6]+1)>>1;
    
    cout << *max_element(arr,arr+9);
    
    return 0;
}