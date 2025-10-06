#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 6; 
    int k = 2;

    int S[6] = {1, 3, 5, 7, 9, 10};  
    int E[6] = {2, 4, 7, 11, 9, 15}; 


    int idx[100];
    for (int i = 0; i < n; i++)
        idx[i] = i;

    
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (E[idx[i]] > E[idx[j]])
            {
                swap(idx[i], idx[j]);
            }
        }
    }

    
    int personEnd[100];
    for (int i = 0; i < k; i++){
        personEnd[i] = -1; 
    }

    int count = 0;

   
    for (int t = 0; t < n; t++)
    {
        int i = idx[t]; 
        for (int j = 0; j < k; j++)
        {
            if (personEnd[j] < S[i])
            {
                personEnd[j] = E[i]; 
                count++;
                break; 
            }
        }
    }

    cout << "Maximum shops visited = " << count << endl;
    return 0;
}