#include<bits/stdc++.h>

using namespace std;

/**
 * Input : aaaavvvrrr
 * Output : a4v3r3
 */

int getCount(char ch, string str, int k)
{
    int count = 0;
    for (int i = k; str[i] == ch; i++)
        count++;

    return count;
}

int main()
{
    int t;
    cin>>t;
    cin.ignore();

    while (t--)
    {
        string str;
        cin>>str;
        vector<char> vect;
        vector<int> vect2;

        for (int i = 0, j = 0; str[i] != '\0'; i++)
        {
            int count = getCount(str[i], str, i);
            vect.push_back(str[i]);
            vect2.push_back(count);
            i = i + (count - 1);
        }

        for (int i = 0; i < vect.size(); i++)
            cout<<vect[i]<<vect2[i];

        cout<<endl;
    }

    return 0;
}