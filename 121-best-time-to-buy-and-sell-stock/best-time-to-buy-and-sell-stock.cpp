class Solution {
public:
    int maxProfit(vector<int>& prices) {     //arr=[7,1,5,3,6,4] n=6
        int n=prices.size();
            int maxprof=0;                   
        int minprice=INT_MAX; 
                  
        for(int i=0;i<n-1;i++){  
        

            minprice=min(prices[i],minprice)   ;      
           maxprof=max(prices[i+1]-minprice,maxprof);
            }
              return maxprof;
        }
     
        
    }
;