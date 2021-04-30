// 12ms, 13.2MB 
class Solution {
    const int PROCESSING = 2;
    const int PROCESSED = 1;
    const int DEFAULT = 0;
    
public:
    bool isCycle(vector<vector<int>>& adj, vector<int>& status, int target) {
        if (status[target] == PROCESSING) 
            return true;
        
        status[target] = PROCESSING;
        
        for (int i = 0; i < adj[target].size(); i++) {
            if (status[adj[target][i]] != PROCESSED) {
                if (isCycle(adj, status, adj[target][i])) 
                    return true;
            }
        }
        
        status[target] = PROCESSED;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for (int i = 0; i < prerequisites.size(); ++i) 
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
            
        vector<int> status(numCourses, 0);
        for (int i = 0; i < numCourses; i++) {
            if (status[i] == DEFAULT) {
                if (isCycle(adj, status, i)) 
                    return false;
            }
        }
        
        return true;
    }
};
