#include<bits/stdc++.h>

using namespace std;

char getBinary(string str)
{
    if (str == "0000")
        return '0';
    else if (str == "0001")
        return '1';
    else if (str == "0010")
        return '2';
    else if (str == "0011")
        return '3';
    else if (str == "0100")
        return '4';
    else if (str == "0101")
        return '5';
    else if (str == "0110")
        return '6';
    else if (str == "0111")
        return '7';
    else if (str == "1000")
        return '8';
    else if (str == "1001")
        return '9';
    else if (str == "1010")
        return 'A';
    else if (str == "1011")
        return 'B';
    else if (str == "1100")
        return 'C';
    else if (str == "1101")
        return 'D';
    else if (str == "1110")
        return 'E';
    else if (str == "1111")
        return 'F';
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
        int dotIndex;
        string res;

        for (int i = 0; str[i] != '\0'; i++)
        {
            if (str[i] == '.')
            {
                dotIndex = i;
                break;
            }
        }

        for (int j = dotIndex - 1; j >= 0; j = j - 4)
        {
            int k = j;
            string tmpStr;
            for (int i = 0; i < 4 && k >= 0 ; i++)
            {
                tmpStr.push_back(str[k--]);
            }
            int size = tmpStr.size();
            if (size != 4)
            {
                while (size != 4)
                {
                    tmpStr.push_back('0');
                    size++;
                }
            }
            reverse(tmpStr.begin(), tmpStr.end());
            res.push_back(getBinary(tmpStr));
        }
        reverse(res.begin(), res.end());
        res.push_back('.');
        for (int j = dotIndex + 1; str[j] != '\0'; j = j + 4)
        {
            int k = j;
            string tmpStr;
            for (int i = 0; i < 4 && str[k] != '\0'; i++)
            {
                tmpStr.push_back(str[k++]);
            }
            int size = tmpStr.size();
            if (size != 4)
            {
                while (size != 4)
                {
                    tmpStr.push_back('0');
                    size++;
                }
            }
            res.push_back(getBinary(tmpStr));
        }
        cout<<res;


        cout<<endl;
    }

    return 0;
}