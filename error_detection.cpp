#include<bits/stdc++.h>
using namespace std;

bool checkSequence(vector<int>&v)
{
    for(int i=0;i<v.size();i++)
    {
        if(v[i]==1 || v[i]==0)
        {
            continue;
        }
        else
        {
            return true;
        }
    }
    return false;
}
bool check(vector<int>&v,vector<int>&receiver)
{
    // cout << v.size() << " " << receiver.size() << endl; 
    if(v.size() != receiver.size())
    {
        return true;
    }
    int count=0;
    for(int i=0;i<v.size();i++)
    {
        if((v[i] ^ receiver[i])==1)
        {
            count++;
        }
    }
    if(count > 0)
    {
        return true;
    }
    return false;
}

int main()
{
    cout << "Enter the size of payload" << endl;
    int n;
    cin >> n;
    cout << "Enter the payload" << endl;
    vector<int>v;
    for(int i=0;i<n;i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }
    bool res=checkSequence(v);

    if(res)
    {
        cout << "The input is invalid " << endl;
        return 0;
    }
    else
    {
        //at first we will count the number of ones in the array
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(v[i] == 1)
            {
                count++;
            }
        }
        cout << "Enter parity 1->odd Parity and 2->even parity" << endl;
        int p;
        cin >> p;
        if((p==1) && (count & 1))
        {
            v.push_back(0);
        }
        else if((p==2) && (count & 1==0))
        {
            v.push_back(0);
        }
        else
        {
            v.push_back(1);
        }
        cout << endl << "The final mesaage send to the receiver is" << endl;
        for(int i=0;i<v.size();i++)
        {
            cout << v.at(i) << " ";
        }
        cout << endl;
        cout << "Enter the size of the payload at the receivers end" << endl;
        int num;
        cin >> num;
        cout << "Enter the payload at receivers end" << endl;
        vector<int>receiver;
        for(int i=0;i<num;i++)
        {
            int x;
            cin >> x;
            receiver.push_back(x);
        }
        bool ch=check(v,receiver);
        if(ch)
        {
            cout << "Error in the message " << endl;
        }
        else
        {
            cout << "No error in the message " << endl;
        }

        
}
    
    return 0;
}