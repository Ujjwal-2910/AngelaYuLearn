#include <bits/stdc++.h>
using namespace std;

// int solve(int ind, vector<int> &arr, long max_sub, vector<int> &dp1, vector<int> &dp2)
// {
//     if(ind == n)
//         return 0;
//     if(dp1[ind] != -1)
//         return dp1[ind] + dp2[ind];

// }

// int getMaxSubsequenceLen(vector<int> arr, long max_sub)
// {
//     int n = arr.size();
//     vector<int> dp1(n, -1);
//     vector<int> dp2(n, -1);
//     return solve(0, arr, max_sub, dp1, dp2);
// }

int find(vector<int> &arr, int k)
{
    int result = INT_MAX;

    for (int i = 0; i < arr.size(); ++i)
    {
        int sum = 0;
        for (int j = i; j < arr.size(); j++)
        {
            sum += arr[j];
            if (sum == k)
            {
                result = min(result, (j - i + 1));
            }
        }
    }

    // Return result
    return result;
}

long solve(vector<int> &arr, int k)
{
    int sum = 0;
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    if (k % sum == 0)
    {
        return n * (k / sum);
    }
    if (k < sum)
    {
        arr.insert(arr.end(), arr.begin(), arr.end());
        int ans = find(arr, k);
        return ans >= (arr.size() + 1) ? -1 : ans;
    }
    int s = n * (k / sum);
    int r = k - sum * (k / sum);
    arr.insert(arr.end(), arr.begin(), arr.end());
    int ans = find(arr, r);
    return ans >= (arr.size() + 1) ? -1 : ans + s;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int k;
    cin >> k;
    cout << solve(arr, k) << endl;
    return 0;
}