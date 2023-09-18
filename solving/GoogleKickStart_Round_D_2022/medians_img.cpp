#include<bits/stdc++.h>
#define ll long long
using namespace std;


double SuccessMetric(vector<int>&A, int n, int m)
{
    sort(A.begin() , A.end());


    if(n == m)
    {
        return (double)(accumulate(A.begin() , A.end(), 0));
    }

    if(m == 1)
    {
       if(n&1)
       return  (double)(A[n/2]+A[n/2])/2.0;
       else
       return ((double)(A[n/2] + A[n/2 - 1]))/2.0;
    }

    double ans = 0;
        // only m-1
        // first pick region n-1, n-2, ... n-m+1
        for(int i=n-m+1; i<=n-1; i++){
            ans += A[i];
        }
        
        // now median of the rest
        // 0....n-m
        int cnt = n-m+1;
        if(cnt==0){
            // nothing left
        }
        else if(cnt%2 != 0){
            // odd num of element
            int mid = (n-m)/2;
            ans += A[mid];
        }
        else{
            // even
            // if 0...5
            // cnt = n-m = 6
            // mid1 = 2,3
            int mid1 = (n-m+1)/2 - 1;
            int mid2 = (n-m+1)/2 ;
            
            ans += (A[mid1] + A[mid2])/ 2.0 ;
            
        }

    return ans;
    
}
int main()
{
    int t;
    cin>>t;
    int count = 1;


    while(t--)
    {
        int n,m;
        cin>>n>>m;

        vector<int>A(n);

        for(int i = 0 ; i < n ; i++)
        cin>>A[i];

        double metric = SuccessMetric(A,n,m);
          cout<<"Case #"<<count<<": ";
        if(ceil(metric) == floor(metric))
        {
            string s = to_string((int)metric);
            s += ".0";
            cout<<s<<"\n";
        }
        else
        {
            cout<<metric<<"\n";
        }
      
        count++;
    }   
}
/*
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    for(int tst=1; tst<=t; tst++){
        int n,m;
        cin>>n>>m;
        vector<int> a(n);
        
        for(int& i : a) cin>> i;
        
        sort(a.begin(), a.end());
        
        double ans = 0;
        // only m-1
        // first pick region n-1, n-2, ... n-m+1
        for(int i=n-m+1; i<=n-1; i++){
            ans += a[i];
        }
        
        // now median of the rest
        // 0....n-m
        int cnt = n-m+1;
        if(cnt==0){
            // nothing left
        }
        else if(cnt%2 != 0){
            // odd num of element
            int mid = (n-m)/2;
            ans += a[mid];
        }
        else{
            // even
            // if 0...5
            // cnt = n-m = 6
            // mid1 = 2,3
            int mid1 = (n-m+1)/2 - 1;
            int mid2 = (n-m+1)/2 ;
            
            ans += (a[mid1] + a[mid2])/ 2.0 ;
            
        }

        // string ans_str = "" ;
        // if(ans == (int)ans){
        //     ans_str = to_string((int)ans) + ".0";
        // }
        // else{
        //     ans_str = to_string((int)ans) + ".5";
        // }
        
        //cout << "Case #" << tst << ": " << ans_str << endl;
        cout << "Case #" << tst << ": " << ans << endl;
        
        
    }
    
}

/*
int main(){
    int t;
    cin>>t;
    
    for(int tst=1; tst<=t; tst++){
        int n,m;
        cin>>n>>m;
        vector<int> a(n);
        
        for(int& i : a) cin>> i;
        
        sort(a.begin(), a.end());
        
        double ans = 0;
        // only m-1
        // first pick region n-1, n-2, ... n-m+1
        for(int i=n-m+1; i<=n-1; i++){
            ans += a[i];
        }
        
        // now median of the rest
        // 0....n-m
        int cnt = n-m+1;
        if(cnt==0){
            // nothing left
        }
        else if(cnt%2 != 0){
            // odd num of element
            int mid = (n-m)/2;
            ans += a[mid];
        }
        else{
            // even
            // if 0...5
            // cnt = n-m = 6
            // mid1 = 2,3
            int mid1 = (n-m+1)/2 - 1;
            int mid2 = (n-m+1)/2 ;
            
            ans += (a[mid1] + a[mid2])/ 2.0 ;
            
        }
        
        cout << "Case #" << tst << ": ";

        if(ceil(ans) == float(ans))
        {
            string s = to_string((int)ans);
            s += ".0";
            cout<<s<<"\n";
        }
        else
        {
            cout<<ans<<"\n";
        }
        
    }
    
}
*/