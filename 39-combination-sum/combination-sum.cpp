class Solution {
public:
      void recursionCall(int ind,vector<int>&arr,int target, vector<vector<int>>&ans,
        vector<int>&ds){

            //base case
            if(ind==arr.size()){
                if( target==0){
                ans.push_back(ds);
                 
                }
                   return;}
            
            

            //pick
            if(arr[ind]<=target){
                ds.push_back(arr[ind]);
                recursionCall(ind,arr,target-arr[ind],ans,ds);
                ds.pop_back();
            }

            //notpick

            recursionCall(ind+1,arr,target,ans,ds);


        }
    vector<vector<int>> combinationSum(vector<int>& arr, int target) {
        vector<vector<int>>ans;
        vector<int>ds;

        recursionCall(0,arr,target,ans,ds);
        return ans;
        
    }
};