// It is the most efficient method of finding all primes less than a number n by marking the multiples of prime starting from 2's square in a boolean array
// https://practice.geeksforgeeks.org/problems/sieve-of-eratosthenes/0

#include<bits/stdc++.h>
using namespace std;
int main()
 {
	//code
	bool prime[10000] = {true};
	int p,i,n;
	int t;
	cin>>t;
	while(t--)
	{
	    cin>>n;
	    memset(prime,true,sizeof(prime));
	    for(p=2;p*p<=n;p++)
	    {
	        if(prime[p]==true)
	        {
	            for(i=p*p;i<=n;i+=p)
	            {
	                prime[i]=false;
	            }
	        }
	    }
	    for(i=2;i<=n;i++)
	    if(prime[i]==true)
	    cout<<i<<" ";
	    cout<<"\n";
	  }
	return 0;
}