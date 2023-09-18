#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    long t, x;
    int n;
    cin >> n >> t >> x;
    long d[n], p[n];
    for (int i = 0; i < n; i++)
    {
        cin >> d[i] >> p[i];
    }
    if (x < d[0])
    {
        cout << "-1";
    }
    else
    {
        int sum = x - d[0], c = 0;
        for (int i = 0; i <= n; i++)
        {
            if (unsigned(x - d[i]) < d[i + 1] - d[i])
            {
                sum += p[i];
                c++;
            }
            x = d[i];
        }
        cout << c;
    }
    return 0;
}

int main1()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n, t, x;
    cin >> n >> t >> x;

    int *dvalue = new int[n];
    int *pvalue = new int[n];
    for (int i = 0; i < n; i++)
    {

        int d, p;
        cin >> d >> p;
        dvalue[i] = d;
        pvalue[i] = p;
    }

    if (x == 0 && dvalue[0] != 0)
    {
        cout << "-1";
        return 0;
    }

    // syntax for sorting a array in c++
    int rem = x;
    int i = 0;
    int p = t;
    int k = 0;

    while (i < n)
    {

        x = x - dvalue[i];

        if (x < 0 && i > 0)
        {
            k++;
            x = x + pvalue[i - 1];
        }

        else if (x == 0)
        {
            x = x + pvalue[i];
            k++;
        }

        else
        {
            x = x + dvalue[i];
        }

        i++;
    }

    if (k == 0 && rem == p)
    {

        cout << "0";
    }

    else if (k == 0 && rem != p)
    {
        cout << "-1";
    }

    else
    {
        cout << k;
    }
    return 0;
}
