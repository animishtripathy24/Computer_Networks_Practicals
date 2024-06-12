#include<bits/stdc++.h>
using namespace std;

string compare(string &ans,string &generator)
{
    string res;
    for(int i=0;i<generator.size();i++)
    {
        int n1=ans[i]-'0';
        int n2=generator[i]-'0';
        int temp=n1^n2;
        res.push_back((temp+'0'));
    }
    // cout << res << endl;
    return res;
}
int to_decimal(string str)
{
    int sum=0;
    int number=0;
    for(int i=str.size()-1;i>=0;i--)
    {
        sum=sum+(pow(2,number)*(str[i]-'0'));
        number++;
    }
    // cout << sum << endl;
    return sum;
}
string calRem(string &frame ,string &generator,int i,string &quotient)
{
    string zero(generator.size(),'0');
    int key=to_decimal(generator);
    cout << key << endl;

    string ans=frame.substr(0,generator.size());
    // cout << ans << endl;
    string res;
    while(i<frame.size())
    {
        // cout << ans << endl;
        int number=to_decimal(ans);
        if(number >= key)
        {
            string check=compare(ans,generator);
            res+=check;
            quotient.push_back('1');
        }
        else
        {
            string check=compare(ans,zero);
            res+=check;
            quotient.push_back('0');
        }
        string temp=res.substr(1,generator.size()-1);
        cout << temp << endl; 
        temp.push_back(frame[i]);
        i++;
        ans.clear();
        res.clear();
        ans=temp;
    }
    return ans;

}

int main()
{
    cout << "Enter the number of bits " << endl;
    int bits;
    cin >> bits;

    //input to the frame
    string frame;
    for(int i=0;i<bits;i++)
    {
        char ch;
        cin >> ch;
        frame.push_back(ch);
    }

    cout << "The frame is :" << endl;
    for(auto &value:frame)
    {
        cout << value << " ";
    }
    cout << endl;
    //taking input the crc
    cout << "Enter the crc value" << endl;
    int crc;
    cin >> crc;

    //taking input the generator
    cout << "Enter the generator " << endl;
    string generator;
    for(int i=1;i<=crc+1;i++)
    {
        char ch;
        cin >> ch;
        generator.push_back(ch);
    }
    cout << "The generator is : " << endl;
    for(auto &value:generator)
    {
        cout << value << " ";
    }
    cout << endl;
    //appending zeroes to the tailer of the frame
    for(int i=0;i<crc;i++)
    {
        frame.push_back('0');
    }

    cout << "The frames after adding zeroes is " << endl;
    for(auto &value:frame)
    {
        cout << value << " ";
    }
    cout << endl;
    int i=generator.size();
    string quotient;
    string last;
    string rem=calRem(frame,generator,i,quotient);
    string temp1=rem.substr(1,generator.size()-1);
    cout << endl << "The quotient obtained is " << endl;
    for(auto &value:quotient)
    {
        cout << value << " ";
    }
    cout << endl << "The last Remainder is " << endl;
    for(auto &value:temp1)
    {
        cout << value << " ";
    }
    for(int i=0;i<crc;i++)
    {
        frame.pop_back();
    }
    for(auto &value:temp1)
    {
        frame.push_back(value);
    }
    cout << endl << "The frames to be send is " << endl;
    for(auto &value : frame)
    {
        cout << value <<  " ";
    }

    cout << endl << "Enter the Frames on receivers side " << endl;
    string receiver;
    for(int i=0;i<frame.size();i++)
    {
        char ch;
        cin >> ch;
        receiver.push_back(ch);
    }
    int j=generator.size();
    string quotient1;
    string temp2=calRem(receiver,generator,j,quotient1);
    bool flag=false;
    for(auto &ch:temp2)
    {
        if(ch == '1')
        {
            flag=true;
            break;
        }
    }
    if(flag)
    {
        cout << "Error detected " << endl;
    }
    else
    {
        cout << "No error" << endl;
    }

    return 0;
}