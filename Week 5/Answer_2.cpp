/* Q2: Given an unsorted array of integers, design an algorithm and implement it using a program 
to find whether two elements exist such that their sum is equal to the given key element. */

#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int i, j, flag = 0;

        int n;
        cin >> n;

        int a[n];
        for (i = 0; i < n; i++)
            cin >> a[i];

        int sum;
        cin >> sum;

        sort(a, a + n);

        i = 0;
        j = n - 1;
        while (i < j)
        {
            int s = a[i] + a[j];
            if (s == sum)
            {
                cout << a[i] << " " << a[j] << endl;
                flag = 1;
                break;
            }
            else if (s < sum)
                i++;
            else
                j--;
        }
        if (flag == 0)
            cout << "No Such Elements Exist\n";
    }
}