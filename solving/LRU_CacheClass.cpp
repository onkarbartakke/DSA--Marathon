#include<bits/stdc++.h>

using namespace std;

class LRU_Cache
{
    private:
    int capacity;
    list<pair<int,int>>linkList;
    unordered_map<int, list<pair<int,int>>::iterator>keyPtrMap;

    void refresh(int key, int value)
    {
        auto listPtr = keyPtrMap[key];
        linkList.erase(listPtr);
        linkList.push_front({key,value});
        keyPtrMap[key] = linkList.begin();
    }

    public:
    LRU_Cache(int pCapacity)
    {
        this->capacity = pCapacity;
    }
        
    bool put(int key, int value)
    {
        if(keyPtrMap.find(key)!=keyPtrMap.end())
        {
            refresh(key,value);
        }
        else if(linkList.size() == this->capacity)
        {
            auto lruPair = linkList.back();
           keyPtrMap.erase(lruPair.first);
           linkList.pop_back();
           
        }

        linkList.push_front({key,value});
        keyPtrMap[key] = linkList.begin();
        return true;
    }

    int get(int key)
    {
       
       
            if(keyPtrMap.find(key)!=keyPtrMap.end())
            {
                auto listPtr = keyPtrMap[key];
                int value = (*listPtr).second;
                refresh(key,value);
                return value;
            }
            else
                throw("This key doesn't exists in CACHE\n");
       
        // catch(string excpMessage)
        // {
        //     cout<<excpMessage<<"\n";
        //     cout<<"For Key : "<<key<<"\n\n";
        // }

        return -1;
    }

    void printState()
    {
        cout<<"\n\n";
        for(auto it : linkList)
        {
            cout<<"{"<<it.first<<" , "<<it.second<<"}\n";
        }
        cout<<"\n";
    }
};

int main()
{
    LRU_Cache cachec(5);
    cachec.put(1,100);
    cachec.put(2,200);
    cachec.put(3,300);
    cachec.put(4,400);
    cachec.put(5,500);

    cachec.printState();

    int val = cachec.get(5);
    cout<<"Value for key 5 : "<<val<<"\n";

    cachec.printState();

    val = cachec.get(3);
    cout<<"Value for key 3 : "<<val<<"\n";

    cachec.printState();

    cachec.put(6,600);
    cachec.printState();

    try
    {
        /* code */
        val = cachec.get(9);
    }
    catch(char const *excpMessage)
    {
       cout<<excpMessage<<"\n";
       cout<<"For Key : "<<9<<"\n\n";
    }
    
    val = cachec.get(9);
    cachec.printState();

    cachec.put(9,900);
    cachec.printState();
}