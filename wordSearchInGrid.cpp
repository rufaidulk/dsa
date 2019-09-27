#include<bits/stdc++.h>

using namespace std;

int xDir[] = {0, 0, 1, -1, 1, -1, 1, -1};
int yDir[] = {1, -1, 1, -1, 0, 0, -1, 1};

bool stringCheck(vector<vector<char>>vect, int x, int y, int m, int n, string str)
{
    if (str[0] != vect[x][y])
        return false;

    int len = str.length();

    for (int dir = 0; dir < 8; dir++)
    {
        int k, r = x + xDir[dir], c = y + yDir[dir];

        for (int k = 1; k < len; k++)
        {
            if (r > m || r < 0 || c > n || c < 0)
                break;

            if (vect[r][c] != str[k])
                break;

            r += xDir[dir];
            c += yDir[dir];
        }
        if (k == len)
            return true;
    }
    return false;
}

void findPattern(vector<vector<char>>vect, int m, int n, string str)
{
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (stringCheck(vect, i, j, m, n, str))
                cout<<i<<" "<<j<<", ";
}

int main()
{
    int t;
    cin>>t;

    while (t--)
    {
        int m, n;
        int input[2];
        for (int i = 0; i < 2; i++)
            cin>>input[i];
        m = input[0];
        n = input[1];
        vector<vector<char>>vect(m,vector<char>(n));
        
        // int arr[m][n];
        for (int i = 0 ; i < m; i++)
            for (int j = 0; j < n; j++)
                cin>>vect[i][j];
        for (int i = 0 ; i < m; i++)
            for (int j = 0; j < n; j++)
                cout<<vect[i][j];

        cin.ignore();
        string str;
        cin>>str;
cout<<str;
        findPattern(vect, m, n, str);

        cout<<endl;

    }
}