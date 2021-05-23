class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n=s.size(), far=0;
        queue<int> q;
        q.push(0);
        if(s[n-1]=='1')
            return false;
        while(!q.empty()){
            int cur=q.front();
            q.pop();
             if(cur == n-1)
                return true;
             for(int j = max(cur+ minJump, far); j <= min(cur + maxJump, n - 1); j++)
                if(s[j] == '0')   q.push(j);
                 
             far=max(cur+maxJump+1, far);
        }
        
        return false;
    }
};