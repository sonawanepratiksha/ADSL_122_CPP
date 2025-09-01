#include <iostream>
using namespace std;

// Function to check if tasks can be finished in D days with given limit
bool canFinish(int task[], int n, int D, int limit)
{
    int days = 1; // start with day 1
    int work = 0; // work done in current day

    for (int i = 0; i < n; i++)
    {
        if (work + task[i] > limit)
        { // need a new day
            days++;
            work = 0;
        }
        work += task[i];
        if (days > D)
            return false; // too many days
    }
    return true; // possible
}

int minWorkPerDay(int task[], int n, int D)
{
    // find lower bound (largest task) and upper bound (sum of all tasks)
    int low = task[0], high = 0;
    for (int i = 0; i < n; i++)
    {
        if (task[i] > low)
            low = task[i]; // max task
        high += task[i];   // sum of tasks
    }

    int ans = high;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (canFinish(task, n, D, mid))
        {
            ans = mid; // feasible → try smaller
            high = mid - 1;
        }
        else
        {
            low = mid + 1; // not feasible → increase limit
        }
    }
    return ans;
}

int main()
{
    int n, D;

    cout << "Enter number of tasks: ";
    cin >> n;

    int task[n]; // array of tasks

    cout << "Enter work units for each task: ";
    for (int i = 0; i < n; i++)
    {
        cin >> task[i];
    }

    cout << "Enter number of days: ";
    cin >> D;

    int result = minWorkPerDay(task, n, D);
    cout << "Minimum work per day: " << result << endl;

    return 0;
}