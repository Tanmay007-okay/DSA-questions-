class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;

        int leftsmall[n], rightsmall[n];

    //    compute pse
        for (int i = 0; i < n; i++) {
           
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            leftsmall[i] = st.empty() ? 0 : st.top() + 1;

            // Push current index to stack
            st.push(i);
        }

        // Clear stack to reuse for NSR
        while (!st.empty())
            st.pop();

        // nse
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }

            // If stack is empty, no smaller to the right
            rightsmall[i] = st.empty() ? n - 1 : st.top() - 1;

            st.push(i);
        }

        // Calculate max area using NSL and NSR
        int maxA = 0;
        for (int i = 0; i < n; i++) {
            int width = rightsmall[i] - leftsmall[i] + 1;
            maxA = max(maxA, heights[i] * width);
        }

        return maxA;
    }
};