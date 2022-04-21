#include<bits/stdc++.h>

using namespace std;

bool validateCash(int n, vector<int> &vect, int arr[])
{
    for (int i = 0; i < vect.size(); i++)
    {
        if ((n / arr[i]) >= 0)
        {
            int x = n / arr[i];
            if (x > 0 && vect[i] > 0)
            {   
                int note = x >= vect[i] ? vect[i] : x; 
                n = n - (note * arr[i]);
            }
        }
    }
    
    if (n != 0)
        return false;

    return true;
}

void getCash(int n, vector<int> &vect, int arr[])
{
    for (int i = 0; i < vect.size(); i++)
    {
        if ((n / arr[i]) >= 0)
        {
            int x = n / arr[i];

            if (x > 0 && vect[i] > 0)
            {   
                int note = x >= vect[i] ? vect[i] : x; 
                n = n - (note * arr[i]);
                vect[i] = vect[i] - note;
                cout<<arr[i]<<" : "<<note<<" ";
            }
        }
    }
    cout<<endl;
}

void displayCurrency(int arr[], vector<int> &vect)
{
    for (int i = 0; i < vect.size(); i++)
    {
        cout<<arr[i]<<" : "<<vect[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    int t;
    cin>>t;
    cin.ignore();

    while (t--)
    {
        int arr[] = {2000, 500, 200, 100, 50, 20, 10, 5, 1};
        vector<int> vect;
        int atmBalance = 0, amount;

        for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++)
        {
            int count;
            cout<<"Number of "<<arr[i]<<endl;
            cin>>count;
            vect.push_back(count);
        }    

        for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++)
        {
            atmBalance = atmBalance + (arr[i] * vect[i]);
        }

        while (atmBalance)
        {
            cout<<"Enter amount"<<endl;
            cin>>amount;

            if (amount <= atmBalance)
            {
                if (!validateCash(amount, vect, arr))
                {
                    cout<<"Notes not available"<<endl;
                }
                else 
                {
                    getCash(amount, vect, arr);
                    atmBalance = atmBalance - amount;
                }
            }
            else 
            {
                cout<<"insufficient balance"<<endl;
            }

            cout<<"Balance: "<<atmBalance<<endl;
            displayCurrency(arr, vect);
        }        

        cout<<endl;
    }

    return 0;
}
