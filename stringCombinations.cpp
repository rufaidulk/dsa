#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin>>t;
    
    while (t--)
    {
        char str[1000];
        cin>>str;
        int r;
        cin>>r;
        int n = strlen(str);
        if (r == 1)
        {
            for (int i = 0; i < n; i++)
                cout<<str[i]<<endl;
        }
        else
        {
            for (int i = 0; i <= n-r; i++)
            {
                
                for (int j = i+1; j < n - (r-2); j++)
                {
                    string tmp = "";
                    tmp += str[i];
                    int m = j, k = r-2;
                    
                    while (k--)
                        tmp += str[m++];
                        
                    while (m < n)
                        cout<<tmp<<str[m++]<<endl;
                        
                    
                }
            }
        }
        
        cout<<"\n";
    }
    
    return 0;
}

/*
Sample Input:
1
12345
4
Sample Output:
1234
1235
1345
2345
*/
