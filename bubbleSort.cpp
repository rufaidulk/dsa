#include <bits/stdc++.h>

using namespace std;
 
void swap(int *xp, int *yp)  
{  
    int temp = *xp;  
    *xp = *yp;  
    *yp = temp;  
}  
   
void bubbleSort(int arr[], int n)  
{  
    int i, j; 
    bool swapped; 
    for (i = 0; i < n-1; i++) 
    { 
        swapped = false; 
        for (j = 0; j < n-i-1; j++) 
        { 
            if (arr[j] < arr[j+1]) 
            { 
                swap(&arr[j], &arr[j+1]); 
                swapped = true; 
            } 
        } 
  
        // IF no two elements were swapped by inner loop, then break 
        if (swapped == false) 
            break; 
    } 
}  

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
}

int main()
{
    int t;
    cin>>t;
    cin.ignore();
    
    while (t--)
    {
        int n;
        cin>>n;
        int arr[n];

        for (int i = 0; i < n; i++)
            cin>>arr[i];
        
        bubbleSort(arr, n);
        printArray(arr, n);

        for (int i = 0, j = n-1; i <= j; i++ ,j--)
        {
            if (i == j)
            {
                cout<<arr[i];
                break;
            }
            cout<<arr[i]<<" "<<arr[j]<<" ";
        }

        cout<<"\n";

    }

    return 0;
}