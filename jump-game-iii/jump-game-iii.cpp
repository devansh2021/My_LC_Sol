class Solution {
public:
    bool canReach(vector<int>& v, int s) {
        int n=v.size();
     
        vector<bool> visited(n,0);

        vector<bool> canv(n,0);
        queue<int> q;
        q.push(s);
        while(!q.empty())
        {
            int cur=q.front();
            q.pop();
            visited[cur]=true;
           canv[cur]=true;
            if(cur+v[cur]<n && !visited[cur+v[cur]]){
                q.push(cur+v[cur]);
                canv[cur+v[cur]]=true;
            }
            if(cur-v[cur]>=0 && !visited[cur-v[cur]]){
                q.push(cur-v[cur]);
                canv[cur-v[cur]]=true; 
            }
        }
         for(int i=0;i<n;i++)
        {
            if(v[i]==0){
               if(canv[i])
                   return true;
            }
        }
       return false;
        
    }
};