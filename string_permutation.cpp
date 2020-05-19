// All permutations of a string by recursion and then backtracking

#include<bits/stdc++.h>
#include<string>
using namespace std;

void permutate(string s , int l , int r)
{
    int i;
    if(l==r)
    {
        cout<<s<<" ";
        return ;
    }
    
    for(i=l;i<r;i++)
    {
        swap(s[l],s[i]);
        permutate(s,l+1,r);
        // backtracking to previous form to make other changes so that strings are not repeated
        swap(s[l],s[i]);
    }
}

int main()
{
    string s;
     cin>>s;
    int n = s.length();
   permutate(s,0,n);
}