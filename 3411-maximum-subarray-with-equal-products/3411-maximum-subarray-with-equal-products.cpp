class Solution {
public:
    using int4=array<int, 4>;
    inline int4 exp(unsigned x){
        int4 p2357={0};
        int b=countr_zero(x);
        p2357[0]+=b;
        x>>b;
        while (x%3==0) {x/=3; p2357[1]++;}
        while (x%5==0) {x/=5; p2357[2]++;}
        while (x%7==0) {x/=7; p2357[3]++;}
        return p2357;
    }
    inline int4 expAdd(const int4 & x, const int4& y){
        int4 ans=x;
        for (int i=0; i<4; i++)
            ans[i]+=y[i];
        return ans;
    }
    int maxLength(vector<int>& nums) {
        int cnt=2, n=nums.size();
        for(int i=0; i<n; i++){
            int4 x=exp(nums[i]);
            int4 P=x, L=x, G=x;
            for(int j=i+1; j<n; j++){
                int4 y=exp(nums[j]);
                for(int k=0; k<4; k++)
                    P[k]+=y[k];
                for(int k=0; k<4; k++)
                    G[k]=min(G[k], y[k]);
                for(int k=0; k<4; k++)
                    L[k]=max(L[k], y[k]);
                if (P==expAdd(G, L))
                    cnt=max(cnt, j-i+1);
                else break;
            }
        }
        return cnt;
    }
};