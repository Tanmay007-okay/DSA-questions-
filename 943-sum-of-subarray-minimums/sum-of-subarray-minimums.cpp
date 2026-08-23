class Solution {
public:
    static constexpr int MOD = 1000000007;
    static constexpr int SIZE = 30000;

    int sumSubarrayMins(vector<int>& arr) {
        int mins_index[SIZE + 1];
        long long temp_sum[SIZE + 1];
        int index = 0;
        long long res = 0;
        mins_index[0] = -1;
        temp_sum[0] = 0;
        for (int i = 0; i < arr.size(); i++) {
            int curr = arr[i];

            while (index > 0 && curr <= arr[mins_index[index]]) {
                index--;
            }

            long long curr_sum =
                1LL * curr * (i - mins_index[index]);

            temp_sum[index + 1] =
                (temp_sum[index] + curr_sum) % MOD;

            index++;
            mins_index[index] = i;

            res = (res + temp_sum[index]) % MOD;
        }

        return (int)res;
    }
};