#include<bits/stdc++.h>

using namespace std;

int main()
{

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin) ;
    #endif
    
    int t;
    cin>>t;

    while(t--)
    {
        int n,m;

        cin>>n>>m;

        vector<vector<char>>grid(n, vector<char>(m,'.'));

        for(int i = 0 ; i < n ; i++)
        {
            for(int j = 0 ; j <m ; j++)
            {
                cin>>grid[i][j];
            }
        }

        int wpar = -1 ;
        bool impos = false;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                
                int par = (i+j) % 2 ;

                if(grid[i][j] == 'W' ){
                    if(wpar == -1){
                        wpar = par ;
                    }
                    else if(wpar != par){
                        impos = true;
                    }
                }
                else if(grid[i][j] == 'R'){
                    par = !par ;
                    if(wpar == -1){
                        wpar = par ;
                    }
                    else if(wpar != par){
                        impos = true ;
                    }
                }
            }
        }

        if(wpar == -1 ) wpar = 0 ;

        if(impos){
            cout << "NO\n" ;
            continue;
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                
                int par = (i+j)% 2 ;

                if(par == wpar){
                    grid[i][j] = 'W' ;
                }
                else{
                    grid[i][j] = 'R' ;
                }
            }
        }

        cout<<"YES\n";

        for(int i = 0 ; i< n ; i++)
        {
            for(int j = 0 ; j < m; j++)
            {
                cout<<grid[i][j];
            }
            cout<<"\n";
        }


        
    }
}