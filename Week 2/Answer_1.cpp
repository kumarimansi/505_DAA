/* Q1: Given a sorted array of positive integers containing few duplicate elements, design an algorithm
and implement it using a program to find whether the given key element is present in the array or
not. If present, then also find the number of copies of given key. (Time Complexity = O(log n))
*/

#include <iostream>
using namespace std;

int Bsearch(int arr[], int up, int low, int key, int flag)
{
    int inx = 0;
    while (up >= low)
    {
        int mid = low + ((up - low) / 2);
        if (arr[mid] == key)
        {
            inx = mid;
            if (flag == 1)
            {
                low = mid + 1;
            }
            else
            {
                up = mid - 1;
            }
        }
        else if (arr[mid] < key)
        {
            low = mid + 1;
        }
        else
        {
            up = mid - 1;
        }
    }
    return inx;
}

int main()
{
    int t, n, res, key;
    cin >> t;

    while (t--)
    {
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        cin >> key;
        res = Bsearch(arr, n - 1, 0, key, 1) - Bsearch(arr, n - 1, 0, key, 0); //Upper bound-lower bound
        if (res > 0)
        {
            cout << key << " - " << res + 1 << "\n";
        }
        else
            cout << "Key not found\n";
    }

    return 0;
}
