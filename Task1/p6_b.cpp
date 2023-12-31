#include <iostream>
using namespace std;
void bubble(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
void selection(int arr[], int n)
{
    int i, j, k = 0;
    for (i = 0; i < n-1; i++)
    {
        k = i;
        for (j = i + 1; j < n; j++)
        {
            if (arr[k] > arr[j])
                k = j;
        }
        int temp = arr[i];
        arr[i] = arr[k];
        arr[k] = temp;
    }
}
int search(int arr[], int n, int target)
{
    int l = 0, r = n - 1, mid;
    while (l <= r)
    {
        mid = l + (r - l) / 2;
        if (target == arr[mid])
            return mid;
        else if (target > arr[mid])
            l = mid + 1;
        else
            r = mid - 1;
    }
    return -1;
}
int main()
{
    char ch;
    int i, n = 0, t;
    cout << "1)For Bubble sort select 'b'\n2)For Selection sort select 's'\n\nEnter the choice: ";
    cin >> ch;
    cout << "Enter size of array: ";
    cin>>n;
    int arr[n];
    cout << "Enter the elements: ";
    for (i = 0; i < n; i++)
        cin >> arr[i];
    switch (ch)
    {
    case 'b':
    {
        bubble(arr, n);
        break;
    }
    case 's':
    {
        selection(arr, n);
        break;
    }
    }
    cout<<"The sorted array is:\n";
    for(i=0;i<n;i++)
    cout<<arr[i]<<"\t";
    cout << "\nEnter the target: ";
    cin >> t;
    int pos = search(arr, n, t);
    if (pos == -1)
        cout << "Target not found.\n";
    else
    {
        pos++;
        cout << "The position is: " << pos << endl;
    }
}