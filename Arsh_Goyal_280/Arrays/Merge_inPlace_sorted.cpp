#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    void merge(vector<int> &A, int m, vector<int> &B, int n)
    {

        int a = m - 1;
        int b = n - 1;
        int i = m + n - 1; // calculate the index of the last element of the merged array

        // go from the back by A and B and compare and put to the A element which is larger
        while (a >= 0 && b >= 0)
        {
            if (A[a] > B[b])
                A[i--] = A[a--];
            else
                A[i--] = B[b--];
        }

        // if B is longer than A just copy the rest of B to A location, otherwise no need to do anything
        while (b >= 0)
            A[i--] = B[b--];
    }
};

// GFG
// #include <bits/stdc++.h>
// using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to merge the arrays.
    void merge(long long arr1[], long long arr2[], int n, int m)
    {
        // code here
        int i, j;
        i = n - 1;
        j = 0;

        while (i >= 0 && j < m)
        {
            if (arr1[i] > arr2[j])
            {
                int t = arr1[i];
                arr1[i] = arr2[j];
                arr2[j] = t;
            }

            i--;
            j++;
        }

        sort(arr1, arr1 + n);
        sort(arr2, arr2 + m);
    }
};

// { Driver Code Starts.

int main()
{

    int T;
    cin >> T;

    while (T--)
    {
        int n, m;
        cin >> n >> m;

        long long arr1[n], arr2[m];

        for (int i = 0; i < n; i++)
        {
            cin >> arr1[i];
        }

        for (int i = 0; i < m; i++)
        {
            cin >> arr2[i];
        }
        Solution ob;
        ob.merge(arr1, arr2, n, m);

        for (int i = 0; i < n; i++)
            cout << arr1[i] << " ";

        for (int i = 0; i < m; i++)
            cout << arr2[i] << " ";

        cout << endl;
    }

    return 0;
}
// } Driver Code Ends