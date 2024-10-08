class Solution {
public:
    long long mod = 1e9 + 7;

    
    long long solve(long long x, long long n){
        if(n==0) return 1;

        if(n%2==0){
            return solve((x*x)%mod, n/2);
        }
        else{
            return (x*solve(x, n-1))%mod;
        }
    }

    int countGoodNumbers(long long n) {
        long long odd_places=n/2;
        long long even_places=n/2+n%2;

        long long ans1=0, ans2=0;
        ans1=solve(5, even_places)%mod;
        ans2=solve(4, odd_places)%mod;

        
        return (ans1*ans2)%mod;
    }
};