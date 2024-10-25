// MASHRUF's work

// Here I Have n number of elements and needed to find if I can make s using those n elements
// if possible then output should be YES or else NO

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define ff first
#define mp make_pair
#define no cout<<"NO"<<'\n'
#define yes cout<<"YES"<<'\n'
#define endl '\n'
#define fast() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)



int main()
{
    int n;
    cin>>n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    int s;
    cin>>s;

    bool dp[n+1][s+1];
    dp[0][0] = true;

    for (int i = 1; i <= s; i++)
    {
        dp[0][i]=false;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= s; j++)
        {
            if(a[i-1] <= j){
                dp[i][j] = dp[i-1][j-a[i-1]] || dp[i-1][j];
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    if(dp[n][s])yes;
    else no;
    return 0;
}