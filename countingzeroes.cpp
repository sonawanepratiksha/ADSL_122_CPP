#include <iostream>
using namespace std;

int count_zero(int a[], int n)
{
    int low = 0, high = n - 1;
    int firstZero = -1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

     
        if (mid < n - 1 && a[mid] == 0 && a[mid + 1] == 1)
        {
            return -1; 
        }

        if (a[mid] == 0)
        {
            firstZero = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    if (firstZero == -1)
        return 0;

    return n - firstZero;
}

int main()
{
    int a[20], n;

    cout << "Enter the size of array: ";
    cin >> n;

    cout << "Enter array elements followed 1 by 0: ";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for(int i=0;i<n;i++){
        if(a[i]!=1 && a[i]!=0){
            cout << "Invalid input: only 0 and 1 are allowed!" << endl;
            return 1;
        
        }
    }
        
            int count = count_zero(a, n);

            if (count == -1)
            {
                cout << "\nInvalid array: 0 is followed by 1!" << endl;
            }
            else
            {
                cout << "\n Number of zeros = " << count << endl;
            }
        
    

   
    return 0;
}