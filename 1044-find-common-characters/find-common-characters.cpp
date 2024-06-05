class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        // Initialize frequency array for the first word
        vector<int> common_freq(26, 0);
        for (char c : words[0]) {
            common_freq[c - 'a']++;
        }
        
        // Iterate through each subsequent word
        for (int i = 1; i < words.size(); i++) {
            // Initialize frequency array for the current word
            vector<int> curr_freq(26, 0);
            for (char c : words[i]) {
                curr_freq[c - 'a']++;
            }
            // Update common_freq with the minimum frequency of each character
            for (int j = 0; j < 26; j++) {
                common_freq[j] = min(common_freq[j], curr_freq[j]);
            }
        }
        
        // Construct the result vector
        vector<string> result;
        for (int i = 0; i < 26; i++) {
            if (common_freq[i] > 0) {
                string s(1, 'a' + i);
                for (int j = 0; j < common_freq[i]; j++) {
                    result.push_back(s);
                }
            }
        }
        
        return result;
    }
};