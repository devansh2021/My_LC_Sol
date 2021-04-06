class Solution {
public:
    int minOperations(int n) {
        int mid=0;
        if(n%2)
            mid=2*(n/2)+1;
        else{
            mid=2*(n/2)+1;
                 mid=(mid+(mid-2))/2;
                 }
        int k=1;
        int ans=0;
        //cout<<mid<<endl;
            for(int i=1;k<mid;i++)
            {
                ans+=(mid-k);
                k=2*i+1;
            }
        return ans;
    }
};