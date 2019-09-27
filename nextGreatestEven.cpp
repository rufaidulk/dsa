#include<bits/stdc++.h>

using namespace std;

bool isSorted(vector<int> &vect)
{
    if (vect.size() == 0 || vect.size() == 1)
        return true;

    int asc = 1, desc = 1;
    for (auto i = vect.begin() + 1; i != vect.end(); i++)
        if (*i > *(i-1))
            asc++;

    for (auto i = vect.begin() + 1; i != vect.end(); i++)
        if (*i < *(i-1))
            desc++;

    if (asc == vect.size() || desc == vect.size())
        return true;

    return false;
}

void printVector(vector<int> &vect)
{
    for (auto i = vect.begin(); i != vect.end(); i++)
        cout<<*i;

}

void findEven(vector<int> &vect)
{
    int min = 8;
    auto k = vect.begin();
    for (auto i = vect.begin(); i != vect.end(); i++)
    {
        if (*i % 2 == 0 && min >= *i)
        {    
            min = *i;
            k = i;
        }

    }
    swap(*(vect.end() - 1), *k);

}

void findMin(vector<int> &vect)
{
    for (auto i = vect.end() - 1; i >= vect.begin(); i--)
    {
        if (*i < *(i+1))
        {
            int min = *(i+1);
            auto k = i + 1;
            for (auto j = i+1; j != vect.end(); j++)
            {   
                if (*i < *j && min > *j)
                {
                    min = *j;
                    k = j;
                }
            }
            swap(*i, *k);
            sort(i+1, vect.end());
            break;
        }
    }
    
    if (*(vect.end() - 1) % 2 != 0)
        findEven(vect);

    printVector(vect);
}

int main()
{
    int t;
    cin>>t;

    while (t--)
    {
        int n;
        cin>>n;
        vector<int> vect;

        // if (n%2 != 0)
        // {
        //     cout<<-1<<endl;
        //     continue;
        // }

        while (n > 0)
        {
            vect.push_back(n % 10);
            n = n / 10;
        }
        reverse(vect.begin(), vect.end());
        // bool flag = true;
        // for (auto i = vect.begin() + 1; i != vect.end(); i++)
        //     if (*(i -1) != *i)
        //         flag = false;
        
        // if (flag)
        // {
        //     cout<<-1<<endl;
        //     continue;
        // }

        if (isSorted(vect))
        {
            if (*vect.begin() > *(vect.end() - 1))
            { 
                cout<<-1;
            }
            else 
            {
                swap(*(vect.end()-1), *(vect.end()-2));
                printVector(vect);
            }
        }
        else
        { 
            findMin(vect);
        }
        
        cout<<endl;
    }

    return 0;
}