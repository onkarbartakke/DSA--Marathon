#include<bits/stdc++.h>

using namespace std;


bool comp(vector<int>&a, vector<int>&b)
{
    return a[1] < b[1];
}

char findLongestSingleSlot(vector<vector<int>>leaveTimes)
{
    int n = leaveTimes.size();

    sort(leaveTimes.begin() , leaveTimes.end() , comp);

    int maxTime = leaveTimes[0][1] , emp = leaveTimes[0][0];

    for(int i = 1; i < n ; i++)
    {
        int workTime = leaveTimes[i][1] - leaveTimes[i-1][1];

        if(workTime > maxTime)
        {
            maxTime = workTime;
            emp = leaveTimes[i][0];
        }
        else if(workTime == maxTime)
        {
            emp = min(emp , leaveTimes[i][0]);
        }
    }

    char ans = 'a'+emp;

    return ans;
}

int main()
{
    int n;

    vector<vector<int>>lt;

    cin>>n;

    for(int i = 0 ; i < n ; i++)
    {
        int a,b;
        cin>>a>>b;

        lt.push_back({a,b});
    }


    cout<<"\n"<<findLongestSingleSlot(lt);
}

string findOdd(vector<string>series)
{
    int n = series.size();

    unordered_map<string,int>mp1;
    unordered_map<string,string>mp2;

    for(auto &s : series)
    {
        int ns = s.length();

        string seq = "";
        for(int i = 1 ; i < ns ; i++)
        {
            seq += to_string(s[i] - s[i-1]);
        }

        mp1[seq]++;
        mp2[seq] = s;
    }


    for(auto it : mp1)
    {
        if(it.second == 1)
        {
            return mp2[it.first];
        }
    }

    return "";
}