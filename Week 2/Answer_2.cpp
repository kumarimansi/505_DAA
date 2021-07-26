/* Q2: Given a sorted array of positive integers, design an algorithm and implement it using a program to
find three indices i, j, k such that arr[i] + arr[j] = arr[k].
*/

#include <iostream>
using namespace std;

int Lsearch(int arr[], int n, int key, int start)
{
    for (int i = start; i < n; i++)
    {
        if (arr[i] == key)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    int t, n, sum, res, flag = -1;
    cin >> t;
    while (t--)
    {
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        for (int i = 0; i < n - 2; i++)
        {
            for (int j = i + 1; j < n - 1; j++)
            {
                sum = arr[i] + arr[j];
                res = Lsearch(arr, n, sum, j + 1);
                if (res > 0)
                {
                    cout << ++i << "," << ++j << "," << ++res << "\n";
                    flag = 0;
                    break;
                }
            }
            if (res > 0)
                break;
        }

        if (flag == -1)
        {
            cout << "No sequence found\n";
        }
    }
    return 0;
}
