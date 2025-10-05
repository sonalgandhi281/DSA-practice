#include <iostream>
using namespace std;

// 1. find largest element in an array

// Brute : sort the array, return last element
// TC-> O(nlogn) (if we use any sort like quick or merge), SC-> O(1) (for quick sort)

int largestElement(vector<int> &arr)
{
    int n = arr.size();
    sort(arr.begin(), arr.end());
    return arr[n - 1];
}

// Optimal : assume first element to be largest, traverse array and compare elements to update value of largest
// TC-> O(n), SC-> O(1)

int largestElementOptimal(vector<int> &arr)
{
    int n = arr.size();
    int largest = arr[0];
    for (int i = 0; i < n; i++)
    {
        largest = max(largest, arr[i]);
    }
    return largest;
}

int main()
{
    vector<int> arr1 = {2, 3, 5, 1, 7, 2};
    cout << "Largest Element is : " << largestElement(arr1);
    cout << endl;
    cout << "Largest Element is : " << largestElementOptimal(arr1);
    return 0;
}