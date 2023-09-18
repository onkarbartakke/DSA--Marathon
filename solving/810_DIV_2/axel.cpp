
#include <bits/stdc++.h>

using namespace std;

int message(string s)
{
    int result = -404;

    result = 0;

    int len = s.length();

    for (int i = 0; i < len; i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
            result++;
        else if (s[i] >= 'A' && s[i] <= 'Z')
            result += 2;
    }

    return result;
}

int countOfKDivisibleSubstring(int N, int K, string s)
{
    int result = -404;

    result = 0;

    for (int i = 0; i < N; i++)
    {
        int consonent = 0;
        int vowel = 0;

        for (int j = i; j < N; j++)
        {
            if (s[j] == 'a' || s[j] == 'e' || s[j] == 'i' || s[j] == 'o' || s[j] == 'u')
                vowel++;
            else
                consonent++;

            if (vowel == consonent && (vowel * consonent) % K == 0)
                result++;
        }
    }
    return result;
}

string smallPair(int N, string S[])
{
    string result = "-404";

    string s1 = S[0], s2;

    for (int i = 0; i < N; i++)
    {
        if (s1.compare(S[i]))
    }

    return result;
}

int maxIndex(int A[], int N)
{
    int result = INT_MIN;
    int y = -1;
    for (int i = 1; i < N - 1; i++)
    {
        int left = 0, right = 0;

        for (int j = 0; j < i; j++)
        {
            if (A[j] > A[i])
                left++;
        }

        for (int j = i + 1; j < N; j++)
        {
            if (A[j] < A[i])
                right++;
        }

        int curr = (left * right);

        if (curr > result)
        {
            result = curr;
            y = i;
        }
    }

    return y;
}

int MinimumOperations(int n, vector<int> A)
{
    int minElemet = INT_MAX;
    int TotalSubarrays = 0, minSubarrays = 0;
    for (auto it : A)
    {
        minElemet = min(minElemet, it);
    }

    for (int i = 1; i < n; i++)
    {
        if (A[i] == A[i - 1])
            continue;
        else
        {
            TotalSubarrays++;
            if (A[i - 1] == minElemet)
                minSubarrays++;
        }
    }

    TotalSubarrays++;

    if (A[n - 1] == minElemet)
        minSubarrays++;

    return TotalSubarrays - minSubarrays;
}