#include<bits/stdc++.h>
using namespace std;

int main()
{
    cout << "Enter the number of frames" << endl;
    int frames;
    cin >> frames;
    vector<int>v[frames+1];
    cout << "Enter the number of bits in each frame" << endl;
    int bits;
    cin >> bits;
    cout << "Performing for even parity " << endl;
    for(int i=0 ; i<frames ; ++i)
    {
        for(int j=0 ; j<bits ; j++)
        {
            int x;
            cin >> x;
            v[i].push_back(x);
        }
    }

    for(int i=0 ; i<frames ; i++)
    {
        int count=0;
        for(int j=0 ; j<bits ; j++)
        {
            if(v[i][j]==1)
            {
                count++;
            }
        }
        if(count & 1)
        {
            v[i].push_back(1);
        }
        else
        {
            v[i].push_back(0);
        }
    }

    vector<int>vert;
    for(int j=0 ; j<=bits ; j++)
    {
        int count_one=0;
        for(int i=0 ; i<frames ; i++)
        {
            if(v[i][j]==1)
            {
                count_one++;
            }
        }
        if(count_one & 1)
        {
            vert.push_back(1);
        }
        else
        {
            vert.push_back(0);
        }
    }
    for(int i=0 ; i<vert.size() ; i++)
    {
        v[frames].push_back(vert[i]);
    }
    cout << endl;
    cout << "The final matrix to be send is" << endl;
    for(int i=0 ; i<=frames ; i++)
    {
        for(int j=0 ; j<=bits ; j++)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl << "enter the receiver side matrix " << endl;
    vector<int>receiver[frames+1];
    for(int i=0 ; i<frames ; i++)
    {
        vector<int>temp;
        for(int j=0 ; j<bits ; j++)
        {
            int x;
            cin >> x;
            receiver[i].push_back(x);
        }
        
    }
    cout << endl;
    //for printing the matrices
    for(int i=0 ; i<frames ; i++)
    {
        for(int j=0 ; j<bits ; j++)
        {
            cout << receiver[i][j] << " ";
        }
        cout << endl;
    }
    //calculating the parity of the receiver's side matrix
    for(int i=0;i<frames;i++)
    {
        int count_one1=0;
        for(int j=0;j<bits;j++)
        {
            if(receiver[i][j]==1)
            {
                count_one1++;
            }
        }
        if(count_one1 & 1)
        {
            receiver[i].push_back(1);
        }
        else
        {
            receiver[i].push_back(0);
        }
    }
    vector<int>temp;
    for(int j=0 ; j<=bits ; j++)
    {
        int count_one=0;
        for(int i=0 ; i<frames ; i++)
        {
            if(receiver[i][j]==1)
            {
                count_one++;
            }
        }
        if(count_one & 1)
        {
            temp.push_back(1);
        }
        else
        {
            temp.push_back(0);
        }
    }
    for(int i=0 ; i<temp.size() ; i++)
    {
        receiver[frames].push_back(temp[i]);
    }

    cout << endl << endl;
    cout << "Printing the Receiver's Side Matrix " << endl;
    for(int i=0;i<frames+1;i++)
    {
        for(int j=0;j<bits+1;j++)
        {
            cout << receiver[i][j] << " ";
        }
        cout << endl;
    }

    int pos_i=-1;
    int pos_j=-1;

    for(int i=0;i<=frames;i++)
    {
        if(v[i][bits] != receiver[i][bits])
        {
            pos_i=i;
            break;
        }
    }

    for(int j=0;j<=bits;j++)
    {
        if(v[frames][j] != receiver[frames][j])
        {
            pos_j=j;
            break;
        }
    }
    cout << "The Error Occured at position : (" << pos_i+1 << "," << pos_j+1 << ")" << endl;
    if(receiver[pos_i][pos_j]==1)
    {
        receiver[pos_i][pos_j]=0;
    }
    else
    {
        receiver[pos_i][pos_j]=1;
    }
    cout << endl << "The matrix obtained after correction is" << endl;
    for(int i=0 ; i<frames ; i++)
    {
        for(int j=0 ; j<bits; j++)
        {
            cout << receiver[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}