#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[] = {3, 2, 4};
    int n = sizeof(arr) / sizeof(arr[0]), target = 6;
    map<int, int> mp;
    int i = 0;
    for (int i = 0; i < n; i++)
    {
        if (mp[target - arr[i]] == 0)
        {
            mp[target - arr[i]] = i + 1;
        }
        if (mp[arr[i]] && i != 0)
        {
            cout << mp[arr[i]] - 1 << "," << i << endl;
            break;
        }
    }
    return 0;
}
