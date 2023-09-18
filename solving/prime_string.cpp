#include <bits/stdc++.h>
using namespace std;
/*
You are given a binary string S of length N. Your task is to check if there exists a substring of S which is the binary
 representation of a prime number.

Formally, check if there exist integers L and R such that 1≤L≤R≤N, and the substring SLSL+1SL+2…SR, when treated as a 
binary integer, is prime.

Print "Yes" if such a substring exists, and "No" if it doesn't.
*/

bool isPrime(int n)
{
    if(n%2 == 0)
    return false;
    
    for(int i = 3 ; i*i <= n ; i = i + 2)
    {
        if(n%i == 0)
        return false;
    }
    
    return true;
}
bool containsPrime(string s)
{
    int n = s.length();
	int len = 2;
	    
	    for(len = 2 ; len <= n ; len ++)
	    {
	        int i = 0,k;
	        int j = i + len - 1;
	        
	        int num = 0;
	        for(k = i ; k<=j ; k++)
	        {
	            num = num << 1;
	            
	            num += (s[k]-'0');
	        }
	        
	        if(isPrime(num))
	        return true;
	       
	        for(i = 1 ; i + len - 1< n ; i++)
	        {
	            j = i + len -1;
	            
	            num = num << 1;
	            num += (s[j]-'0');
	            
	            int p = 1 << len;
	            
	            if(p&num)
	            {
	                num = num ^ p;
	            }
	            if(isPrime(num))
	            return true;
	        }
	    }
	    
	    return false;
	    
	    
	   
}
int main() {
	// your code goes here
	
	int t;
	cin>>t;
	while(t--)
	{
	    string s;
	    cin>>s;
	 
	  if(containsPrime(s))
	  cout<<"Yes\n";
	  else
	  cout<<"No\n";
	} 
	return 0;
}


// optimal Approach

#include<bits/stdc++.h>


using namespace std;

int main()
{
    int t;
    cin>>t;
    
    while(t--)
    {
        string s;
        
        cin>>s;
        
        if(s.find("11")!=string::npos || s.find("10")!= string::npos)
        cout<<"Yes\n";
        else
        cout<<"No\n";
    }
}