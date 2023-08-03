#include <bits/stdc++.h>
using namespace std;

void merge(int *value, int *weight, int *v_by_w, int lb, int mid, int ub)
{
    int i = lb;
    int j = mid + 1;
    int k = lb;
    int temp[ub + 1];
    int vtemp[ub + 1];
    int wtemp[ub + 1];

    while (i <= mid && j <= ub)
    {
        if (v_by_w[i] >= v_by_w[j])
        {
            vtemp[k] = value[i];
            wtemp[k] = weight[i];
            temp[k] = v_by_w[i];
            i++;
        }
        else
        {
            vtemp[k] = value[j];
            wtemp[k] = weight[j];
            temp[k] = v_by_w[j];
            j++;
        }
        k++;
    }
    while (i <= mid)
    {
        vtemp[k] = value[i];
        wtemp[k] = weight[i];
        temp[k] = v_by_w[i];
        k++;
        i++;
    }
    while (j <= ub)
    {
        vtemp[k] = value[j];
        wtemp[k] = weight[j];
        temp[k] = v_by_w[j];
        k++;
        j++;
    }

    for (k = lb; k <= ub; k++)
    {
        value[k] = vtemp[k];
        weight[k] = wtemp[k];
        v_by_w[k] = temp[k];
    }
}

void mergeSort(int *value, int *weight, int *v_by_w, int lb, int ub)
{
    if (lb < ub)
    {
        int mid = (lb + ub) / 2;
        mergeSort(value, weight, v_by_w, lb, mid);
        mergeSort(value, weight, v_by_w, mid + 1, ub);
        merge(value, weight, v_by_w, lb, mid, ub);
    }
}
void fractional(int *value, int *weight, int bag_size, int item)
{
    int profit = 0;
    for (int i = 0; i < item; i++)
    {
        if (bag_size == 0)
        {
            break;
        }
        else if (bag_size >= weight[i])
        {
            profit += value[i];
            bag_size -= weight[i];
        }
        else
        {
            profit += (value[i] / weight[i]) * bag_size;
            break;
        }
    }
    cout << "Maximum profit: " << profit;
}
int main()
{
    freopen("fractional.txt", "r", stdin);
    int item;
    int bag_size;
    cin >> bag_size >> item;
    int value[item];
    int weight[item];
    for (int i = 0; i < item; i++)
    {
        cin >> value[i] >> weight[i];
    }

    int v_by_w[item];
    for (int i = 0; i < item; i++)
    {
        v_by_w[i] = value[i] / weight[i];
    }
    // mergeSort(value, weight, v_by_w, 0, item - 1);
    for (int i = 0; i < item; i++)
    {
        for (int j = i + 1; j < item; j++)
        {
            if (v_by_w[i] <= v_by_w[j])
            {
                swap(v_by_w[i], v_by_w[j]);
                swap(value[i], value[j]);
                swap(weight[i], weight[j]);
            }
        }
    }
    fractional(value, weight, bag_size, item);
     
    return 0;
}
