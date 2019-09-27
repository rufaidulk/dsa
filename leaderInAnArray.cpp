#include <iostream>

using namespace std;

int main()
{
    
    int t;
    cin>>t;

    while(t--)
    {
        int n;
        cin>>n;

        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin>>arr[i];
        }

        int temp;
        int j;
        bool flag = true;
        for (int i = 0; i < n; i++)
        {
            temp = arr[i];
            j = i+1;
            flag = true;
            while (j < n)
            {
                if (temp < arr[j]) {
                    flag = false;
                    break;
                }
                j++;
            }
            if (flag) {
                cout<<temp<<" ";
            }
            
        }

        cout<<"\n";
    }

    return 0;
}
