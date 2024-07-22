class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
         int maxlen=0;

        for(int i=0;i<n;i++){
            int maxfreq=0;
           
               int hash[26]={0};

        for(int j=i;j<n;j++){
            hash[s[j]-'A']++;
            maxfreq=max(maxfreq,hash[s[j]-'A']);
            int changes=(j-i+1)-maxfreq;

            if(changes<=k){
                maxlen=max(maxlen,j-i+1);

            }
            else{
                break;
            }

        }
        }
        return maxlen;}

};