#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[] = {1, 5, 8, 9, 6, 7, 3, 4, 2, 0};
    int n = sizeof(arr) / sizeof(arr[0]), target = 6;
    for (int i=0; i < n; i++)
    {
        for(int j=i;j<n;j++){
            if (arr[i] + arr[j] == target and i!=j)
            {
                cout << i << "  " << j<<"\n";
                return 0;
            }
        }
    }
    return 0;
}
