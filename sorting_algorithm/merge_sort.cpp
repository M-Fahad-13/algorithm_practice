#include<bits/stdc++.h>
using namespace std;

void merge(int *a, int lb, int mid, int ub)
{
    int i = lb;
    int j  = mid+1;
    int k = lb;
    int temp[ub+1];

    while(i <= mid && j <= ub)
    {
        if (a[i] <= a[j])
        {
            temp[k] = a[i];
            i++;
        }
        else
        {
            temp[k] = a[j];
            j++;
        }
        k++;
    }
	while (i <= mid)
	{
		temp[k] = a[i];
		k++;
		i++;
	}
	while (j <= ub)
	{
		temp[k] = a[j];
		k++;
		j++;
	}

    for (k = lb; k <= ub; k++)
    {
        a[k] = temp[k];
    }
}

void mergeSort(int *a, int lb, int ub)
{
    if (lb < ub)
    {
        int mid = (lb + ub)/2;
        mergeSort(a, lb, mid);
        mergeSort(a, mid+1, ub);
        merge(a, lb, mid, ub);

    }
}

int main()
{

    int size;
    cout<<"Enter array size: ";
    cin>>size;
    int a[size];
    cout<<"Enter array elements: ";
    for (int i = 0; i < size; i++)
    {
        cin>>a[i];
    }
    mergeSort(a, 0, size-1);
    cout<<"After merge sort: ";
    for (int i = 0; i < size; i++)
    {
        cout << a[i]<<" ";
    }
}
