// Geeks for Geeks problem for implementing LRU Cache get and set function remember that get function also changes the order of elements in cache
#include<bits/stdc++.h>
using namespace std;

// design the class:

class LRUCache
{
private:
list<int> lis;
unordered_map<int,int>hsmap;
int csize;
public:
    LRUCache(int cap)
    {
        // constructor for cache
        csize = cap;
        
    }
    
    int get(int key)
    {
        // this function should return value corresponding to key
        if(hsmap.find(key)==hsmap.end())
        return -1;
        else
        {
            lis.remove(key);
            lis.push_front(key);
        }
        return hsmap[key];
    }
    
    void set(int key, int value)
    {
        // storing key, value pair
        // if key is not present in the list
        if(hsmap.find(key)==hsmap.end())
        {
            if(lis.size()==csize)
            {
                int last = lis.back();
                hsmap.erase(last);
                lis.pop_back();
            }
        }
        else if(hsmap.find(key)!=hsmap.end())
        {
            lis.remove(key);
            hsmap.erase(key);
        }
        
        
        lis.push_front(key);
        hsmap[key]=value;
        
        
    }
};