/*
Q2:	Given an already sorted array of positive integers, design an algorithm and implement it 
using a program to find whether given key element is present in the array or not.
Also, find total number of comparisons for each input case. 
(Time Complexity = O(logn), where n is the size of input).
*/
#include <iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        int key;
        cin >> key;
        int l = 0, r = n - 1, count = 0;
        int mid;
        int flag = 0;
        while (l <= r)
        {
            mid = (l + r) / 2;

            if (arr[mid] == key)
            {
                count++;
                flag = 1;
                break;
            }
            if (key > arr[mid])
            {
                l = mid + 1;
                count++;
            }
            else
            {
                count++;
                r = mid - 1;
            }
        }
        if (flag == 1)
            cout << "Present " << count << endl;
        else
            cout << "Not Present " << count << endl;
    }
    return 0;
}