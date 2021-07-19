/* 
Q3: Given an already sorted array of positive integers, design an algorithm and implement 
it using a program to find whether a given key element is present in the sorted array or not.
For an array arr[n], search at the indexes arr[0], arr[2], arr[4],. ,arr[2k] and so on. 
Once the interval (arr[2k] < key < arr[ 2k+1] ) is found, perform a linear search operation from the index 2k to find the element key.
(Complexity < O(n), where n is the number of elements need to be scanned for searching): Jump Search
*/
#include <iostream>
#include <cmath>
using namespace std;
int jumpsearch(int arr[], int n, int *comp)
{
    int i, key, prev, block;
    cin >> key;
    prev = 0;
    block = sqrt(n);

    while (arr[min(block, n) - 1] < key) //block search
    {
        (*comp)++;

        prev = block;
        block = block + sqrt(n);
        if (prev >= n)
            return -1;
    }

    while (arr[prev] < key) //linear search
    {
        (*comp)++;
        prev++;
        if (prev == min(block, n))
            return -1;
    }
    (*comp)++;
    if (arr[prev] == key)
    {

        return prev;
    }
    else
        return -1;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, i, comp;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        int index = jumpsearch(arr, n, &comp);

        if (index != -1)
        {
            cout << "Present " << comp << endl;
        }
        else
        {
            cout << "Not Present " << comp << endl;
        }
    }

    return 0;
}