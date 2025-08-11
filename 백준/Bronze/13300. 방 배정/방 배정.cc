#include <iostream>
using namespace std;

int arr[7][2];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int size, k;
    cin >> size >> k;
    
    bool sex;
    int grade;
    for (int i{ 0 }; i < size; i++)
    {
        cin >> sex >> grade;
        arr[grade][sex]++;
    }
    
    int room{0};
    for (int i{ 1 }; i < 7; i++)
    {
        room+=(arr[i][0]+(k-1))/k;
        room+=(arr[i][1]+(k-1))/k;
    }
    
    cout<<room;
    return 0;
}