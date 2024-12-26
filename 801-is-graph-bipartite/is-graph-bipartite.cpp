class Solution {
    private:
    bool check(int node,vector<vector<int>>& graph,vector<int>&color){
        queue<int>q;
        q.push(node);
        color[node]=0;

        while(!q.empty()){
            int bro=q.front();
            q.pop();

            for(auto it:graph[bro]){
                if(color[it]==-1){
                    color[it]=!color[bro];
                    q.push(it);

                }
                else if(color[it]==color[bro]){
                    return false;
                }
            }
        }
        return true;

    

    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>color(n,-1);

        for(int i=0;i<n;i++){
            if(color[i]==-1){
                if(check(i,graph,color)==false)return false;
            }
        }
        return true;
        
    }
};