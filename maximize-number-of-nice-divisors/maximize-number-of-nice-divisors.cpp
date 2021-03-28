#define ll long long
class Solution
{
  const int mod = 1e9 + 7;
int power(long long x, unsigned int y, int p)
{
    int res = 1;    
    x = x % p;           
    if (x == 0) return 0; 
 
    while (y > 0)
    {
        
        if (y & 1)
            res = (res*x) % p;
        y = y>>1; 
        x = (x*x) % p;
    }
    return res;
}
public:
  int maxNiceDivisors(int n)
  {
    if (n==1||n == 2 || n == 3)
      return (n );
        if (n % 3 == 0)
        return power(3, n / 3, mod)%mod;
      else if (n % 3 == 1)
        return (ll)2 * 2 * power(3, (n - 4) / 3, mod)%mod;
      else
        return (ll)2 * power(3, n / 3, mod)%mod;
  }
};
// Output:
// 1947137520
// Expected:
// 947137513
