#include <bits/stdc++.h>

using namespace std;

bool comp(pair<int, int> &a, pair<int, int> &b)
{
    if (a.first < b.first)
        return true;

    if (a.first == b.first)
    {
        return a.second <= b.second;
    }

    return a.first < b.first;
}

// void print(pair<int, int> p)
// {
//     cout << p.first << " , " << p.second << "\n";
// }

bool parallel(vector<pair<int, int>> &p, map<pair<int, int>, pair<int, int>> &mp, vector<vector<int>> &lines)
{
    auto p1 = p[0];
    auto p2 = p[1];

    bool isSameLine = false;

    for (auto l : lines)
    {
        if (isSameLine)
            break;

        if (l[0] == p1.first && l[1] == p1.second && l[2] == p2.first && l[3] == p2.second)
        {
            isSameLine = true;
        }

        if (l[0] == p2.first && l[1] == p2.second && l[2] == p1.first && l[3] == p1.second)
        {
            isSameLine = true;
        }

        if (isSameLine)
            break;
    }

    if (!isSameLine)
        return false;

    auto p3 = p[2];
    auto p4 = p[3];

    isSameLine = false;

    for (auto l : lines)
    {
        if (isSameLine)
            break;

        if (l[0] == p3.first && l[1] == p3.second && l[2] == p4.first && l[3] == p4.second)
        {
            isSameLine = true;
        }

        if (l[0] == p4.first && l[1] == p4.second && l[2] == p3.first && l[3] == p3.second)
        {
            isSameLine = true;
        }

        if (isSameLine)
            break;
    }

    if(!isSameLine)
        return false;

    isSameLine = false;

    for(auto l : lines)
    {
        if(isSameLine)
        break;

        if(l[0] == p1.first && l[1] == p1.second && l[2] == p3.first && l[3] == p3.second)
        isSameLine = true;

        if(l[0] == p3.first && l[1] == p3.second && l[2] == p1.first && l[3] == p1.second)
        isSameLine = true;
    }

    if(!isSameLine)
    return false;

    isSameLine = false;

    for(auto l : lines)
    {
        if(isSameLine)
        break;

        if(l[0] == p2.first && l[1] == p2.second && l[2] == p4.first && l[3] == p4.second)
        isSameLine = true;

        if(l[0] == p4.first && l[1] == p4.second && l[2] == p2.first && l[3] == p2.second)
        isSameLine = true;
    }

    if(!isSameLine)
    return false;    

    if (p1.first != p2.first)
    {
        //cout << "p1 - p2 parallel to y\n";
        return false;
    }

    if (p3.first != p4.first)
    {
       // cout << "p3 - p4 parallel to y\n";
       return false;
    }
    if (p2.second != p4.second)
    {
        //cout << "p2 - p4 parallel to x\n";
        return false;
    }

    if (p1.second != p3.second)
    {
        //cout << "p1 - p3 parallel to x\n";
        return false;
    }

    return true;
}
int main()
{
    vector<pair<int, int>> points;

    vector<vector<int>> lines;

    map<pair<int, int>, pair<int, int>> mp;

    for (int i = 0; i < 4; i++)
    {
        int a, b, c, d;
        pair<int, int> p1, p2;

        cin >> a >> b;
        p1.first = a;
        p1.second = b;

        points.push_back({a, b});
        cin >> c >> d;
        p2.first = c;
        p2.second = d;
        points.push_back({c, d});

        lines.push_back({a, b, c, d});

        mp[p1] = p2;
        mp[p2] = p1;
    }

    sort(points.begin(), points.end(), comp);

    int pts = 1;
    vector<pair<int, int>> p;
    p.push_back(points[0]);

    for (int i = 1; i < 8; i++)
    {
        if (points[i].first == points[i - 1].first && points[i].second == points[i - 1].second)
            continue;
        else
        {
            pts++;
            p.push_back(points[i]);
        }
    }
    bool flag = true;

    if (pts != 4)
    {
        flag = false;
        cout << "NO\n";
        return 0;
    }

    // for (auto it : p)
    // {
    //     cout << it.first << " - " << it.second << "\n";
    // }
    if (parallel(p, mp, lines))
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }
}