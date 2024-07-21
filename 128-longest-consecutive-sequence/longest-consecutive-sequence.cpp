class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>set;
        int cnt=0;
        int longest=0;
        for(int i=0;i<nums.size();i++){
            set.insert(nums[i]);
        }

        for(auto it:nums){
            if(set.find(it-1)==set.end()){
                cnt=1;
                int x=it;

                while(set.find(x+1)!=set.end()){
                    cnt++;
                    x++;

                }
            }
            longest=max(longest,cnt);

        }
          
            return longest;      
    }
    
};