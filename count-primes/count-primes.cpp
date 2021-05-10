class Solution {
public:
    int countPrimes(int n) {
        vector<bool> primes(n, true);
        for(int i=2;i<n;i++)
        {
            if(primes[i]){
            for(long long j=(long long)i*i;j<n;j+=i)
                primes[j]=false;
            
            }
        }
        int ans=0;
        for(int i=2;i<n;i++)
        {
            if(primes[i])
                ans++;
        }
        return ans;
    }
};