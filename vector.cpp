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

int main()
{
    int t;
    cin>>t;
    cin.ignore();
    
    while (t--)
    {
        int n, input;
        cin>>n;
        vector<int> v;
        vector<int> temp;

        for (int i = 0; i < n; i++)
        {
            cin>>input;
            v.push_back(input);
        }

        for (int i = 0; i < n; i++)
        {
            while (v[i] > 0)
            {
                int x = v[i] % 10;
                v[i] = v[i] / 10;
                
                if (count(temp.begin(), temp.end(), x) == 0)
                    temp.push_back(x);

            }
        }
        sort(temp.begin(), temp.end());
        for (auto i = temp.begin(); i != temp.end(); i++)
            cout<<*i<<" ";

        cout<<"\n";
    }

    return 0;
}