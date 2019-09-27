#include<bits/stdc++.h>

using namespace std;

string getBinary(char ch)
{
    switch (ch)
    {
        case '0' :
            return "0000";
            break;
        case '1' :
            return "0001";
            break;
        case '2' :
            return "0010";
            break;
        case '3' :
            return "0011";
            break;
        case '4' :
            return "0100";
            break;
        case '5' :
            return "0101";
            break;
        case '6' :
            return "0110";
            break;
        case '7' :
            return "0111";
            break;
        case '8' :
            return "1000";
            break;
        case '9' :
            return "1001";
            break;
        case 'a' :
        case 'A' :
            return "1010";
            break;
        case 'b' :
        case 'B' :
            return "1011";
            break;
        case 'c' :
        case 'C' :
            return "1100";
            break;
        case 'd' :
        case 'D' :
            return "1101";
            break;
        case 'e' :
        case 'E' :
            return "1110";
            break;
        case 'f' :
        case 'F' :
            return "1111";
            break;
    }
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

        for (int i = 0; str[i] != '\0'; i++)
        {
            cout<<getBinary(str[i]);
        }

        cout<<endl;
    }

    return 0;
}