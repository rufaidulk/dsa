#include<bits/stdc++.h>

using namespace std;

/**
 * Eg 1: Input: a1b10
 * Output: abbbbbbbbbb
 * Eg: 2: Input: b3c6d15
 * Output: bbbccccccddddddddddddddd
 * The number varies from 1 to 99.
 */

bool isChar(char ch)
{
    if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
        return true;

    return false;
}

void findNum(vector<char> &vect, vector<int> &count)
{
    int num = 0;
    for (int i = 0, j = vect.size(); i < vect.size(); i++)
    {
        int x = (int)vect[i] - '0';
        num = num + (pow(10, --j) * x);
    }
    count.push_back(num);
    vect.clear();
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
        vector<char> ch;
        vector<char> vect;
        vector<int> count;

        
        for (int i = 0; str[i] != '\0'; i++)
        {
            if (isChar(str[i]))
            {
                ch.push_back(str[i]);
                if (vect.size() > 0)
                    findNum(vect, count);
            }
            else 
            {
                vect.push_back(str[i]);
            }
        }
        
        if (vect.size() > 0)
            findNum(vect, count);
        
        for (int i = 0; i < ch.size(); i++)
        {
            while (count[i]--)
            {
                cout<<ch[i];
            }
        }

        cout<<endl;
    }

    return 0;
}