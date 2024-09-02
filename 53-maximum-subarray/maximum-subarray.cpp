class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        long long maxi=LONG_MIN;
        int n=nums.size();
        long long sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            maxi=max(maxi,sum);
            if(sum<0){
                sum=0;
            }

        }
        // if(maxi<0)maxi=0;
        return maxi;
        
    }
};