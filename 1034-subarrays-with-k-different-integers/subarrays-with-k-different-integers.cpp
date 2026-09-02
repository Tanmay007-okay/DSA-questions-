class Solution {
public:

    int atMostK(vector<int>& nums, int K) {
        unordered_map<int, int> freq;
        int left = 0, count = 0;

        // Traverse the array with right pointer
        for (int right = 0; right < nums.size(); right++) {
            // If it's a new unique element, decrease K
            if (freq[nums[right]] == 0) {
                K--;
            }

            // Increment frequency of current element
            freq[nums[right]]++;

            // Shrink the window if distinct count > K
            while (K < 0) {
                freq[nums[left]]--;
                if (freq[nums[left]] == 0) {
                    K++;
                }
                left++;
            }

            // Count all subarrays ending at current right
            count += (right - left + 1);
        }

        return count;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMostK(nums, k) - atMostK(nums, k - 1);
    }
};

