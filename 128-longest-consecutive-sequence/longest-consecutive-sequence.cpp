class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int cnt=0;
        int length=0;
        int lastsmaller=INT_MIN;

        for(int i=0;i<n;i++){

            if(nums[i]-1==lastsmaller){
                cnt++;
                lastsmaller=nums[i];
                
            }

            else if(nums[i]==lastsmaller){
                continue;
            }
            else if(nums[i]!=lastsmaller){
                cnt=1;
                lastsmaller=nums[i];
            }



            length=max(length,cnt);




        }
        return length;
        
    }
};