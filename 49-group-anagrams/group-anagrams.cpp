class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for (string s : strs) {
            mp[strSort(s)].push_back(s);
        }
        vector<vector<string>> anagrams;
        for (auto p : mp) { 
            anagrams.push_back(p.second);
        }
        return anagrams;
    }
private:
    string strSort(string s) {
        int counter[26] = {0};
        for (char c : s) {
            counter[c - 'a']++;
        }
        string t;
        for (int i = 0; i < 26; i++) {
            // Manually append the character 'i' + 'a' counter[i] times to the string t
            for (int j = 0; j < counter[i]; j++) {
                t += (i + 'a');
            }
        }
        return t;
    }
};
