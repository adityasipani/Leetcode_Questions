class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // Create an unordered map to store the count of each number
        unordered_map<int, int> countMap;
        for (int& num : nums)
            countMap[num]++;
        vector<int> result;
        // Create a min-heap to store the top k frequent elements
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        for (const auto& entry : countMap) {
            // Insert the frequency and corresponding number into the min-heap
            minHeap.emplace(entry.second, entry.first);
            // If the size of the min-heap exceeds k, remove the element with the smallest frequency
            if (minHeap.size() > k)
                minHeap.pop();
        }
        while (!minHeap.empty()) {
            // Extract the number from the top of the min-heap and add it to the result vector
            result.push_back(minHeap.top().second);
            minHeap.pop();
        }
        return result;
    }
};