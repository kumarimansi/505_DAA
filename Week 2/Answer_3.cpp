/* Q3: Given an array of nonnegative integers, design an algorithm and a program 
to count the number of pairs of integers such that their difference is equal to a given key, K.
*/
#include <iostream>
#include <math.h>
using namespace std;

int Lsearch(int arr[], int n, int key)
{

    int flag = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (fabs(arr[j] - arr[i]) == key)
            {
                flag++;
            }
        }
    }
    return flag;
}

int main()
{
    int t, n, key, res;
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
        res = Lsearch(arr, n, key);
        cout << res << "\n";
    }

    return 0;
}
