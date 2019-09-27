#include <bits/stdc++.h>

using namespace std;

/**
 * Array is sorted in ascending order.
 */
int binarySearch(int arr[], int l, int r, int num)
{
    while (l <= r)
    {
        int mid = l + (r - l) / 2;

        if (arr[mid] == num)
            return mid;

        if (arr[mid] < num)
            l = mid + 1;
        else
            r = mid - 1;

    }

    return -1;
}

int main()
{
    int arr[] = {1, 2, 4, 8, 22, 82, 7};
    int num = 99
    ;

    int index = binarySearch(arr, 0, sizeof(arr)/sizeof(arr[0]), num);

    if (index == -1)
        cout<<"not found";
    else 
        cout<<"found at index: "<<index;

    cout<<"\n";
    return 0;
}