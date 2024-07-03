class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int max_area = 0;

        while (left < right) {
            // Calculate current container area based on shorter line height
            int current_height = min(height[left], height[right]);
            max_area = max(max_area, current_height * (right - left));

            // Move the shorter line's pointer inwards to explore larger areas
            if (height[left] < height[right]) {
                left++;  // Move left pointer if the left line is shorter
            } else {
                right--; // Move right pointer if the right line is shorter
            }
        }

        return max_area;
    }
};
