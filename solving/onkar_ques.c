#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef unsigned long long int ulli;

const int NMAX = 90;

// return a char strinng of size n+1
char* getbasestring(int n){
    char* res = (char*) malloc((n+1) * sizeof(char));
    
    res[n] = '\0' ;
    
    for(int i=0; i<n; i++){
        res[i] = 'A' ;
    }

    return res;
}

int search(ulli m, int n, ulli sum[]){
    // find min k such that
    // sum[k] >= m and sum[k-1] < m
    assert(m!=1);

    int st = 1;
    int end = n;
    int k;
    while(1){
        k = (st+end)/2;
        if(sum[k]>=m && sum[k-1]<m){
            break;
        }
        else if(sum[k]>=m){
            // sum [k-1] is also >= m

            end = k-1;
        }
        else{
            st = k+1;
        }
    }

    return k;
}

// maybe we can pass string around by refrence.
// instead of passing by value
char* solve(int n, ulli m, ulli sum[]){

    // possibility check.
    assert(n<=NMAX);
    assert(sum[n]>=m);

    char* base = getbasestring(n);

    // base case
    if(m==1){
        // return base;
    }
    else{
        // find k with binary seach on sum array
        int k = search(m, n, sum);

        assert(k>=1);
        assert(k<=n);

        // put b at position n-k+1(1-indexed)
        base[n-k] = 'B' ; // 0 indexed

        // find offset and recurse 
        ulli offset = m - sum[k-1];
        char* rest = solve(n, offset, sum);

        // combine the result
        for(int i=n-k+2; i<n; i++){
            base[i] = rest[i] ;
        }

        // free the memory of temp. string.
        free(rest);
        
    }
    
    // return result
    return base;
}

int main(){

    freopen("input.txt", "r", stdin);


    int t;
    int n;
    ulli m;
    ulli limit = 1e19 ;

    // precomputation. 
    // valid for all test cases.

    ulli num[NMAX+2];
    ulli sum[NMAX+2]; 
    
    //ulli* num = (ulli*)malloc(n*sizeof(ulli));
    //ulli* sum = (ulli*)malloc(n*sizeof(ulli));

    num[0] = num[1] = 1;
    sum[0] = 1;

    int sum_limit = -1;
    // sum[sum_limit] <= m and sum[sum_limit+1] > m 
    // to take care of overflow
    // but seems of no use if input is feasable.

    for(int i=2; i<=NMAX+1; i++){
        num[i] = sum[i-2] ;
        
        // num[i-1] = sum[i-3]
        if(sum[i-2] <= limit && num[i-1] > limit - sum[i-2]){
            // sum[i-1] will be too much
            sum_limit = i-2;
            break;
        }
        sum[i-1] = sum[i-2] + num[i-1] ; // overflow check ??
    }

    if(sum_limit == -1){
        // sum calculated 0...n-1
        // num calculated 0...n
        sum_limit = NMAX ;
        
    }

    assert(sum_limit>=1 && sum_limit<=NMAX) ;

    
    scanf("%d", &t);

    while(t--){
        scanf("%d%llu", &n, &m);
        // find string now

        if(m > sum[n]){
            // not possible
            printf("Fuck\n");
            exit(0);
        }

        char* ans = solve(n, m, sum);

        printf("%s\n", ans);

    }



    return 0;
}