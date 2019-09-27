#include <bits/stdc++.h>

using namespace std;

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
}

int getCount(vector<int> &vect, int num)
{
    int count = 0;
    int i, m = 0;
    for (i = 0; i < vect.size(); i++)
    {
        if (vect[i] != num)
            break;

        count++;
    }  
    vect.erase(m, i);

    return count;
}

void printPattern(vector<int> &vect, int n)
{
    vector<int> tempVect;
    tempVect = vect;

    for (int i = 3; i <= n; i++)
    {
        cout<<"i:"<<i;
        for (int j = 0; j < vect.size(); j++)
        {
            int count = getCount(tempVect, vect[j]);
            cout<<count<<vect[j];
            tempVect.push_back(count);
            tempVect.push_back(vect[j]);
        }
        cout<<endl;
        // vect.clear();
        // for (auto k = vect.begin(); k != vect.end(); k++)
        //     cout<<*k<<endl;
        // vect = tempVect;
        // for (auto k = vect.begin(); k != vect.end(); k++)
        //     cout<<*k<<endl;
        // tempVect.clear();
        // cout<<endl;
    }

    // for (auto i  = vect.begin(); i != vect.end(); i++)
    //     cout<<*i;
}

int main()
{
    int t;
    cin>>t;
    cin.ignore();
    
    while (t--)
    {
        int n;
        cin>>n;

        int numArr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        vector<int> vect{2, 1};

        if (n == 1)
            cout<<1;
        else if (n == 2)
            cout<<vect[0]<<vect[1];
        else 
            printPattern(vect, n);       

        cout<<"\n";
    }

    return 0;
}