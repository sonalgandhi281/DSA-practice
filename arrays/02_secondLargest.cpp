#include <iostream>
using namespace std;

// 2. find second largest element in an array

// Brute : sort the array, largest is at n-1, traverse backwards from n-2 to first element and as soon as u find element not equal to largest, return that
// TC-> O(nlogn+n), SC-> O(1)

int secondLargest(vector<int> &arr)
{
    int n = arr.size();
    sort(arr.begin(), arr.end());
    for (int i = n - 2; i >= 0; i--)
    {
        if (arr[i] != arr[n - 1])
            return arr[i];
    }
    return -1;
}

// Better : find largest element first, then traverse again and compare with largest to find second largest
// TC-> O(2n), SC-> O(1)

int secondLargestBetter(vector<int> &arr)
{
    int n = arr.size();
    int largest = arr[0], sl = -1; // if array has -ves, take sl as INT_MIN
    for (int i = 0; i < n; i++)
    {
        largest = max(largest, arr[i]);
    }
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > sl && arr[i] != largest)
        {
            sl = arr[i];
        }
    }
    return sl;
}

// Optimal : we find both largest and sl in a single loop
// intuition is based on the fact that when we encounter a no. greater than largest, largest becomes second largest.
// TC-> O(n), SC-> O(1)

int secondLargestOptimal(vector<int> &arr)
{
    int n = arr.size();
    int largest = arr[0], sl = -1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > largest)
        {
            sl = largest;
            largest = arr[i];
        }
        else if (arr[i] > sl && arr[i] < largest)
        {
            sl = arr[i];
        }
    }
    return sl;
}

int main()
{
    vector<int> arr1 = {2, 3, 5, 1, 7, 2};
    cout << "Second Largest Element is : " << secondLargest(arr1) << endl;
    cout << "Second Largest Element is : " << secondLargestBetter(arr1) << endl;
    cout << "Second Largest Element is : " << secondLargestOptimal(arr1);
    return 0;
}