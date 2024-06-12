#include<bits/stdc++.h>
using namespace std;

bool check(vector<int>&arr)
{
    for(auto &value:arr)
    {
        if(value==0 || value ==1 )
        {
            continue;
        }
        else
        {
            return false;
        }
    }
    return true;
}

vector<int> bitStuffing(vector<int>&payload)
{
    vector<int>stuffed;
    int count=0;
    for(auto &value:payload)
    {
        if(value==1)
        {
            count++;
            if(count==6)
            {
                stuffed.push_back(0);
                count=0;
            }
        }
        else
        {
            count=0;
        }
        stuffed.push_back(value);
    }
    return stuffed;
}

int main()
{
    cout << "Enter the size of the information field" << endl;
    int n;
    cin >> n;
    vector<int>payload;
    for(int i=0 ;i<n ;i++)
    {
        int x;
        cin >> x;
        payload.push_back(x);
    }
    if(check(payload))
    {
        vector<int>arr=bitStuffing(payload);
        cout << "The bit stuffed vector is" << endl;
        for(auto &value:arr)
        {
            cout << value << " ";
        }
        cout << endl;
        exit(0);
    }
    else
    {
        cout << "The information or payload entered is incorrect" << endl;
        exit(0);
    }
}