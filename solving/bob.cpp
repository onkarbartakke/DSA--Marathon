#include<bits/stdc++.h>

using namespace std;

vector<int> elements(int q, vector<vector<int>>query)
{
    vector<int>ans;
    unordered_map<int,int>freq;
    unordered_map<int, stack<int> >fst;
    int maxFreq = 0;

    for(auto v : query)
    {
        if(v[0] == 1)
        {
            int val = v[1];
            maxFreq = max(maxFreq, ++freq[val]);      
            fst[freq[val]].push(val);
        }
        else
        {
            int x = fst[maxFreq].top();
            fst[maxFreq].pop();
            
            if(fst[maxFreq].empty())
            {
                maxFreq--;
            }
            
            freq[x]--;
            ans.push_back(x);
        }
    }

    return ans;
}
int main()
{

}