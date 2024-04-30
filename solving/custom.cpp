
#include <bits/stdc++.h>
using namespace std;

class ListIterator{
public:
    int getNext() {
        return input[position++];
    }
    bool hasNext() {
        return position!=input.size();
    }
    explicit ListIterator (const vector<int>&input) {
        this->input = input;
        this->position = 0;
    }

private:
    vector<int>input;
    int position;
};

class RangeIterator{
public:
    int getNext() {
        auto value = inputList[currIndex][pointers[currIndex]++];
        currIndex=(currIndex+1)%inputList.size();
        return value;
    }

    bool hasNext() {
        int totalTraversals =0;
        while(totalTraversals<inputList.size()) {
            totalTraversals++;
            if(pointers[currIndex]!=inputList[currIndex].size()) return true;
            currIndex=(currIndex+1)%inputList.size();
        }
        return false;
    }

    explicit RangeIterator (int start, int end, int range) {
        vector<int>currList;
        int currElement=start;
        int count = 0;
        while(currElement<=end) {
            if(count==range) {
                this->inputList.push_back(currList);
                currList.clear();
                count=0;
            }
            currList.push_back(currElement++);
            count++;
        }
        if(!currList.empty()) this->inputList.push_back(currList);
        this->pointers.assign(inputList.size(),0);
        this->currIndex=0;
    }

private:
    vector<vector<int>>inputList;
    vector<int>pointers;
    int currIndex;
};

vector<int>mergeListsOfLists(const vector<vector<int>>&input) {
    vector<pair<int,int>> prevIterators, nextIterators;
    prevIterators.reserve(input.size());
    for(int i=0;i<input.size();i++) prevIterators.emplace_back(i,0);//index, position
    vector<int>result;

    while(!prevIterators.empty()) {
        for(auto const &each: prevIterators) {
            auto index = each.first, position = each.second;
            if(position == input[index].size()) continue;
            result.push_back(input[index][position++]);
            nextIterators.emplace_back(index, position);
        }
        swap(prevIterators, nextIterators);
        nextIterators.clear();
    }
    int totalCount=0;
    for_each(begin(input), end(input),[&](auto const &inputList) {
        totalCount+=inputList.size();
    });
    assert(totalCount==result.size());
    return result;
}

vector<int> mergeListsOfLists1(vector<vector<int>>&input)
{
    vector<int>ans;

    int N = input.size();
    deque<pair<int,int>>dq;

    for(int i = 0 ; i < N ; i++)
    {
        if(input[i].size() > 0)
        dq.push_back({i,0});
    }

    while(!dq.empty())
    {
        auto p = dq.front();
        dq.pop_front();

        int listNum = p.first;
        int curIdx = p.second;

        ans.push_back(input[listNum][curIdx]);

        curIdx++;

        if(curIdx < input[listNum].size())
        {
            dq.push_back({listNum,curIdx});
        }
    }

    return ans;
}
int main() {

    vector<vector<int>> input = {{1,2,3,4,5,6,7,8}, {11,12}, {21,22} ,{31,32},{},{100} };
//    cout<<stoi("")<<endl;
    //12,13,14,15

    auto ans = mergeListsOfLists1(input);

    for(auto it : ans)
    {
        cout<<it<<" ";
    }

    cout<<"\n";
    auto  result = mergeListsOfLists(input);
    for(auto const &each:result ) cout<<each<<" ";cout<<endl;

    const vector<int> inputList = {1,2,3,4,5,6,7,8,9};
    ListIterator listIterator = ListIterator(inputList);
    while (listIterator.hasNext()) cout<<listIterator.getNext()<<" ";cout<<endl;

    RangeIterator rangeIterator = RangeIterator(1,11,2);
    while (rangeIterator.hasNext()) cout<<rangeIterator.getNext()<<" ";cout<<endl;

}