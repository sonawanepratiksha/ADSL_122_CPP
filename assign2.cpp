#include <iostream>
using namespace std;

void merge(int arr[], int start, int end, int mid)
{
    int temp[20];
    int i = start;
    int j = mid + 1;
    int k = 0;
    while (i <= mid && j <= end)
    {
        if (arr[i] >= arr[j])
        {
            temp[k] = arr[i];
            i++;
            k++;
        }
        else
        {
            temp[k] = arr[j];
            j++;
            k++;
        }
    }

    while (i <= mid)
    {
        temp[k] = arr[i];
        i++;
        k++;
    }
    while (j <= end)
    {
        temp[k] = arr[j];
        j++;
        k++;
    }

    for (int m = 0; m < k; m++)
    {
        arr[start + m] = temp[m];
    }
}

void mergesort(int arr[20], int start, int end)
{
    
    int mid = (start + end) / 2;
    mergesort(arr, start, mid);
    mergesort(arr, mid + 1, end);
    merge(arr, start, end, mid);
}

int main()
{

    int arr[20], n;
    cout << "ENter the size of array:";
    cin >> n;
    cout << "Enter array Elements:";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "array elemnts are :";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    mergesort(arr, 0, n - 1);
    cout << "Sorted array is :";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}