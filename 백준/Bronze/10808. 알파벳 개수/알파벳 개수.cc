#include <iostream>
#include <string>
using namespace std;

int main()
{
    string word;
    cin>>word;
    int arr[26]={0};
    
    for(char c:word)
    {
        arr[c - 'a']++;
    }
    
    for(int i{0};i<26;i++)
    {
        cout<<arr[i]<<' ';
    }
    
    return 0;
}