//Problem Link: https://practice.geeksforgeeks.org/problems/inversion-of-array-1587115620/1

public class CountInversions
{
    static int inversionCount = 0;
    public static void main(String[] args) {
        int[] arr= new int[]{2, 4, 1, 3, 5};
        mergeSort(arr, 0, arr.length - 1);
        // for (int x : arr) {
        //     System.out.print(x + " ");
        // }
        System.out.println(inversionCount);
        
    }
    
    static void mergeSort(int[] arr, int low, int high)
    {
        if (low < high)
        {
            int mid = (low + high) / 2;
            mergeSort(arr, low, mid);
            mergeSort(arr, mid + 1, high);
            
            merge(arr, low, mid, high);
        }
    }
    
    static void merge(int[] arr, int low, int mid, int high)
    {
        int n1 = mid - low + 1;
        int n2 = high - mid;
        int left[] = new int[n1];
        int right[] = new int[n2];
        
        for (int i = 0; i < n1; i++)
            left[i] = arr[low + i];
            
        for (int j = 0; j < n2; j++)
            right[j] = arr[mid + 1 + j];
            
        int i = 0, j = 0, k = low;
        while (i < n1 && j < n2)
        {
            if (left[i] < right[j]) {
                arr[k] = left[i];
                i++;
            }
            else {
                inversionCount += mid - low;
                arr[k] = right[j];
                j++;
            }
            k++;
        }
        while (i < n1) {
            arr[k++] = left[i++];
        }
        while (j < n2) {
            arr[k++] = right[j++];
        }
    }
}
