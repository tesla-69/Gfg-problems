class Solution 
{
    public:
    //Function to find a Mother Vertex in the Graph.
    void dfs(vector<int>adj[], vector<bool> &vis,int node, vector<int> &v){
        vis[node] = true;
        v.push_back(node);
        
        for(auto it: adj[node]){
            if(!vis[it]){
                dfs(adj,vis,it,v);
            }
        }
    }
int findMotherVertex(int V, vector<int>adj[])
{
    // Code here
    
    int ans = -1;
    for(int i=0;i<V;i++){
        vector<bool> vis(V,false);
        if(!vis[i]){
            vector<int> v;
            
            dfs(adj,vis,i,v);
            
            if(v.size() == V){
                ans = i;
                break;
                
            }
        }
    }
    
    return ans;
    
}
 
};
