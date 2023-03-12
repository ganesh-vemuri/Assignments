#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[] = {1, 5, 8, 9, 6, 7, 3, 4, 2, 0};
    int n = sizeof(arr) / sizeof(arr[0]), target = 6;
    sort(arr, arr + n);
    int i = 0, j = n - 1;
    while (i < j)
    {
        if (arr[i] + arr[j] == target)
        {
            cout << i << "  " << j;
            break;
        }
        else if (arr[i] + arr[j] < target)
        {
            i++;
        }
        else
        {
            j--;
        }
    }
    return 0;
}
