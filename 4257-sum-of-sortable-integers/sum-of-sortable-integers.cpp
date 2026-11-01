class Solution {
public:
    int sortableIntegers(vector<int> &nums) {
        const int n = nums.size();

        vector<int> sorted_nums(nums);
        sort(sorted_nums.begin(), sorted_nums.end());

        int sum = 0;
        for (int k = 1; k <= n; ++k) {
            if (n % k == 0) {
                bool valid = true;
                for (int i = 0; i < n && valid; i += k) {
                    int start = -1;
                    for (int j = i + 1; j < i + k; ++j) {
                        if (nums[j] < nums[j - 1]) {
                            if (start == -1) {
                                start = j;
                            } else {
                                goto stop;
                            }
                        }
                    }

                    if (start == -1) {
                        start = i;
                    }

                    for (int j = start, l = i; l < i + k; ++l) {
                        if (nums[j] != sorted_nums[l]) {
                            goto stop;
                        }

                        j = i + (j + 1) % k;
                    }
                }

                sum += k;

            stop:;
            }
        }

        return sum;
    }
};
