// Codeforces educational round 86 problem b as we have only two characters 1 & 0 in the string t we can just make 1010.... of length 2t or 
// it will be of period 2 but if all elements of t are same then we can have a string of period 1.
// Also take a look at how hashmap can be used to find the number of different characters in a string.



#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        string t;
        cin>>t;
        int n = t.length();
        unordered_map<char,int>m;
        int i;
        for(i=0;i<n;i++)
        m[t[i]]++;
        if(m.size()==1)
        {
            cout<<t<<"\n";
            continue;
        }
        for(i=0;i<n;i++)
        cout<<"10";
        cout<<"\n";
        
    }
    
}