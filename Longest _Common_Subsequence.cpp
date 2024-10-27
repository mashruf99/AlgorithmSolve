// Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence, return 0.
// A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.
// For example, "ace" is a subsequence of "abcde".
// A common subsequence of two strings is a subsequence that is common to both strings.

// MASHRUF's work

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define ff first
#define mp make_pair
#define no cout << "NO" << '\n'
#define yes cout << "YES" << '\n'
#define endl '\n'
#define fast() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

int ans(string &a, int n, string &b, int m, vector<vector<int>> &dp)
{
    if (n == 0 || m == 0)
        return 0;
    if (dp[n][m] != -1)
        return dp[n][m];

    if (a[n - 1] == b[m - 1])
    {
        dp[n][m] = 1 + ans(a, n - 1, b, m - 1, dp);
    }
    else
    {
        int ans1 = ans(a, n - 1, b, m, dp);
        int ans2 = ans(a, n, b, m - 1, dp);
        dp[n][m] = max(ans1, ans2);
    }

    return dp[n][m];
}

int longestCommonSubsequence(string a, string b)
{
    int n = a.size();
    int m = b.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    return ans(a, n, b, m, dp);
}

int main()
{
    fast();
    string a, b;
    cin >> a >> b;
    cout << longestCommonSubsequence(a, b);

    return 0;
}

// alternative bottom up solution'

int longestCommonSubsequence(string a, string b)
{
    int n = a.size();
    int m = b.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (a[i - 1] == b[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[n][m];
}
int main()
{
    fast();
    string a, b;
    cin >> a >> b;
    cout << longestCommonSubsequence(a, b);

    return 0;
}
