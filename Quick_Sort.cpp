#include <iostream>
using namespace std;

int partition1(int arr[], int l, int h)
{
    int p = arr[l]; // Pivot element
    int i = l + 1;  // Start i from l+1 because l is the pivot element
    int j = h;

    while (i <= j)
    {
        // Move i to the right until an element larger than or equal to the pivot is found
        while (i <= h && arr[i] <= p)
            i++;
        // Move j to the left until an element smaller than or equal to the pivot is found
        while (j >= l && arr[j] > p)
            j--;
        // If i and j have not crossed, swap them
        if (i < j)
            swap(arr[i], arr[j]);
    }
    // Place the pivot in the correct position
    swap(arr[l], arr[j]);
    return j; // Return the pivot index
}

void QuickSort1(int arr[], int l, int h)
{
    if (l < h)
    {
        int piv = partition1(arr, l, h); // Get the partition index
        QuickSort1(arr, l, piv - 1);     // Sort the left sub-array
        QuickSort1(arr, piv + 1, h);     // Sort the right sub-array
    }
}
int partition2(int arr[], int begin, int end)
{
    int i = begin;
    int j = end;
    int pivloc = begin; // Start pivloc at the beginning

    while (true)
    {
        // Move j to the left until an element smaller than the pivot is found
        while (arr[pivloc] <= arr[j] && pivloc != j)
        {
            j--;
        }
        // If pivloc meets j, break out of the loop
        if (pivloc == j)
            break;

        // Swap the pivot with the element at j if needed
        if (arr[pivloc] > arr[j])
        {
            swap(arr[j], arr[pivloc]);
            pivloc = j; // Update pivot location
        }

        // Move i to the right until an element larger than the pivot is found
        while (arr[pivloc] >= arr[i] && pivloc != i)
        {
            i++;
        }
        // If pivloc meets i, break out of the loop
        if (pivloc == i)
            break;

        // Swap the pivot with the element at i if needed
        if (arr[pivloc] < arr[i])
        {
            swap(arr[i], arr[pivloc]);
            pivloc = i; // Update pivot location
        }
    }
    return pivloc; // Return the final pivot location
}
void QuickSort2(int arr[], int l, int h)
{
    if (l < h)
    {
        int piv = partition2(arr, l, h); // Get the pivot index
        QuickSort2(arr, l, piv - 1);     // Sort left subarray
        QuickSort2(arr, piv + 1, h);     // Sort right subarray
    }
}

void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[] = { 2, -1, 4, 7, 0, 9, 5 };
    int n = sizeof(arr) / sizeof(arr[0]);

    QuickSort2(arr, 0, n - 1);
    cout << "Sorted array : ";
    print(arr, n);
}
