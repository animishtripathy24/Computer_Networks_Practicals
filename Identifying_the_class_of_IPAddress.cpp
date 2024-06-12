#include<bits/stdc++.h>
using namespace std;

vector<int> calBinary(vector<int>&v,int n)
{
    int i=0;
    while(n > 0)
    {
        v.push_back(n%2);
        n=n/2;
        i++;
    }
    reverse(v.begin(),v.end());
    return v;
}

char check(vector<int>&binary)
{
    if(binary[0]==0)
    {
        return 'a';
    }
    else if(binary[0]==1 && binary[1]==0)
    {
        return 'b';
    }
    else if(binary[0]==1 && binary[1]==1 && binary[2]==0)
    {
        return 'c';
    }
    else if(binary[0]==1 && binary[1]==1 && binary[2]==1 && binary[3]==0)
    {
        return 'd';
    }
    else
    {
        return '#'; //indication that it belongs to no class
    }
}

int main()
{
    cout << "Enter the IP Address" << endl;
    string str;
    cin >> str;
    cout << "The Inputted IP Address is " << endl;
    for(int i=0;i<str.size();i++)
    {
        cout << str[i];
    }
    cout << endl;
    
    //now we have to append a dot in the string
    // str.push_back('.');
    int j=0;
    int i=0;
    // int count=1;
    string temp;
    while(i<str.size())
    {
        if(str[i]=='.')
        {
            // string temp(str.begin()+j,str.begin()+i);
            for(auto it=str.begin()+j;it != str.begin()+i;++it)
            {
                temp.push_back(*(it));
            }
            break;
        }
        i++;
    }
    int first=stoi(temp);
    //cout << first << endl;
    vector<int>v;
    vector<int>binary=calBinary(v,first);
    cout << "The binary equivalent obtained after converting into binary is " << endl;
    for(auto &value:binary)
    {
        cout << value << " "; 
    }
    cout << endl;
    char ch=check(binary);
    if(ch == 'a')
    {
        cout << "It belongs to class A" << endl;
        exit(0);
    }
    if(ch == 'b')
    {
        cout << "It belongs to class B" << endl;
        exit(0);
    }
    if(ch == 'c')
    {
        cout << "It belongs to class C" << endl;
        exit(0);
    }
    if(ch == 'd')
    {
        cout << "It belongs to class D" << endl;
        exit(0);
    }
    if(ch == 'e')
    {
        cout << "It belongs to class E" << endl;
        exit(0);
    }
}