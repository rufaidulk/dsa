#include <iostream>

using namespace std;

int main()
{
    
    int t;
    cin>>t;

    while(t--)
    {
        int input[2];
        for (int i = 0; i < 2; i++)
        {
            cin>>input[i];
        }
        int n = input[0];
        // cin>>n;
        int k = input[1];

        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin>>arr[i];
        }
        int l = 0;
        int x = n%k;
        for (int j = k - 1; j < 2*n; j += k) 
        {
            if (j >= n) {
                while (l < n) {
                    cout<<arr[l++]<<" ";
                }
                break;
            }

            for (int i = j; i >= l; i--)
            {                
                cout<<arr[i]<<" ";    
            }
            l = j+1;
        }

        cout<<"\n";
    }

    return 0;
}
