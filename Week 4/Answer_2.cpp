/*Q2: Given an unsorted array of integers, design an algorithm and implement it using a program to sort
an array of elements by partitioning the array into two subarrays based on a pivot element such
that one of the sub array holds values smaller than the pivot element while another sub array holds
values greater than the pivot element. Pivot element should be selected randomly from the array.
Your program should also find number of comparisons and swaps required for sorting the array.*/

#include <bits/stdc++.h>
using namespace std;

int cmp, swp;

void swap(int *a, int *b)
{
    swp++;
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int a[], int l, int r)
{
    int pivot = a[r];
    int i = (l - 1);

    for (int j = l; j <= r - 1; j++)
    {
        cmp++;
        if (a[j] < pivot)
        {
            i++;
            swap(&a[i], &a[j]);
        }
    }
    swap(&a[i + 1], &a[r]);

    return (i + 1);
}

void quickSort(int a[], int l, int r)
{
    if (l < r)
    {
        int pi = partition(a, l, r);
        quickSort(a, l, pi - 1);
        quickSort(a, pi + 1, r);
    }
}

void display(int a[], int s)
{
    int i;
    for (i = 0; i < s; i++)
        cout << a[i] << " ";
    cout << endl;
    cout << "Comparisons = " << cmp;
    cmp = 0;
    cout << endl;
    cout << "Swaps = " << swp;
    swp = 0;
    cout << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        quickSort(a, 0, n - 1);
        display(a, n);
    }
    return 0;
}
