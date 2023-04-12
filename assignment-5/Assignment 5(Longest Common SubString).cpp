#include <iostream>
using namespace std;

int compute(string a, string b, int n, int m)
{

    if (m == 0 || n == 0)
    {
        return 0;
    }

    if (n == 1 && m == 1)
    {
        if (a[0] == b[0])
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    int dp[m + 1][n + 1];
    int final = 0;

    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < m + 1; j++)
        {
            if (a[i - 1] == b[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = 0;
            }
            final = max(final, dp[i][j]);
        }
    }
    return final;
}
int main()
{
    string a = "ababc";
    string b = "babac";
    int n = a.length();
    int m = b.length();
    cout << compute(a, b, n, m);
    return 0;
}