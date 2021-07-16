/*
Given an array of nonnegative integers, design a linear algorithm and implement it using a program to find whether a given key element is present in the array or not. Also, find the total number of comparisons for each input case. (Time Complexity = O(n), where n is the size of input).

For this problem you are free to choose programming language, no. of test cases, input and output format.
If you feel ambitious about problem solving, keep the input inside a text file, read that using a program to generate the output in another file.

 */

#include <iostream>
using namespace std;

void LinearSearch(int key, int arr[], int n)
{
    int count = 0, flag = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == key)
        {
            flag = 1;
            count++;
            break;
        }
        else
            count++;
    }
    if (flag == 1)
        cout << "Present " << count << endl;
    else
        cout << "Not Present " << count << endl;
}

int main()
{

    freopen("LinearSearch_Input.txt", "r", stdin);
    freopen("LinearSearch_Output.txt", "w", stdout);
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
        LinearSearch(key, arr, n);
    }
    return 0;
}
