#include <bits/stdc++.h>

using namespace std;

bool isSame(string s, string p)
{
    if (s.length() != p.length())
        return false;

    vector<int> cnt(26, 0);
    for (int i = 0; i < s.length(); i = i + 2)
    {
        cnt[s[i] - 'a']++;
        cnt[p[i] - 'a']--;
    }

    for (int i = 0; i < 26; i++)
    {
        if (cnt[i] != 0)
            return false;
    }

    for (int i = 1; i < s.length(); i = i + 2)
    {
        cnt[s[i] - 'a']++;
        cnt[p[i] - 'a']--;
    }

    for (int i = 0; i < 26; i++)
    {
        if (cnt[i] != 0)
            return false;
    }

    return true;
}

void check(string s, string a[], vector<bool> &vis, int j, int n)
{
    for (; j < n; j++)
    {
        if (isSame(s, a[j]))
        {
            vis[j] = false;
        }
    }
}

int distinctPasswords(int input1, string input2[])
{
    int n = input1;

    vector<bool> vis(n, true);
    for (int i = 0; i < n; i++)
    {
        if (vis[i])
            check(input2[i], input2, vis, i + 1, n);
    }

    int cnt = 0;

    for (int i = 0; i < n; i++)
    {
        if (vis[i])
            cnt++;
    }

    return cnt;
}

int main()
{
    int n;
    cin >> n;

    string a[n];

    for (int i = 0; i < n; i++)
        cin >> a[i];

    cout << "\n"
         << distinctPasswords(n, a);
}

int computeCost(int arr[], int N, int X)
{
    int cost = 0;
    for (int i = 0; i < N; i++)
        cost += abs(arr[i] - X);
    return cost;
}


int minCostToMakeElementEqual(int arr[], int N)
{
    int low, high;
    low = high = arr[0];

    for (int i = 0; i < N; i++)
    {
        if (low > arr[i])
            low = arr[i];
        if (high < arr[i])
            high = arr[i];
    }

    while ((high - low) > 2)
    {

        
        int mid1 = low + (high - low) / 3;
        int mid2 = high - (high - low) / 3;

        int cost1 = computeCost(arr, N, mid1);
        int cost2 = computeCost(arr, N, mid2);

        if (cost1 < cost2)
            high = mid2;

        
        else
            low = mid1;
    }

    return computeCost(arr, N, (low + high) / 2);
}

// Driver code to test above method
int main()
{
    int arr[] = {90, 30, 40};
    int N = sizeof(arr) / sizeof(int);
    cout << minCostToMakeElementEqual(arr, N);
    return 0;
}

int dist(int i, int j, string s, char c)
{
    vector<int>cnt(256,0);
    int ret = 0;
    for(int k = i + 1; k < j ; k++)
    {
        if(s[k] == ' ')
        continue;

        if(cnt[s[k]] == 0)
        ret++;

        cnt[s[k]]++;
    }

    return ret;
}
int SearchLetter(string input1, string input2)
{
    string s = input1, p = input2;

    char c = p[0];

    unordered_map<char, vector<int>>mp;


    for(int i = 0 ; i < s.length() ; i++)
    {
        mp[s[i]].push_back(i);
    }

    if(mp.find(c) == mp.end())
    return -1;


    vector<int>v = mp[c];

    if(v.size() == 1)
    return -1;
    int ans = 0;
    for(int i = 1 ; i < v.size() ; i++)
    {
        int left = v[i-1];
        int right = v[i];

        int curr = dist(left,right,s,c);

        ans = max(ans,curr);
    }

    return ans;
}