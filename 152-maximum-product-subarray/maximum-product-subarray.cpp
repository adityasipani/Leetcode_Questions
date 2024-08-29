class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int maxP=INT_MIN;
       
        for(int i=0;i<n;i++){
             int product=1;
            for(int j=i;j<n;j++){
                product*=nums[j];

                maxP= max(product,maxP);

            }
        }
        return maxP;
        
    }
};