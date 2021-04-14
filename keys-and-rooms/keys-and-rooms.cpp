class Solution {
public:
    
    void dfs(int u, vector<int>& visited, vector<vector<int> >& rooms){
        visited[u] = 1;
        for(int i=0;i<rooms[u].size();i++){
            if(visited[rooms[u][i]] == 0){
                dfs(rooms[u][i], visited, rooms);
            }
        }
    }
    
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int size = rooms.size();
        if(size == 0 || size == 1)return true;
     vector<int>visited(size, 0);
        dfs(0, visited, rooms); 
        
        for(int i=0;i<size;i++){
            if(visited[i] == 0)
                return false;
        } 
        return true;
    }
};