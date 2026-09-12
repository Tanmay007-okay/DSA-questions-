class Solution {
public:
  struct State 
  {
    long long score = 0;
    array<int, 4> idx = {};
    int size = 0;
  };

  bool isBetter(const State& a, const State& b)
  {
    if(a.score != b.score) return a.score > b.score;

    for(int i = 0; i < min(a.size, b.size); i++)
      if(a.idx[i] != b.idx[i]) return a.idx[i] < b.idx[i];

    return a.size < b.size;
  }

  State addIndex(State state, int index)
  {
    int pos = state.size;

    while(pos > 0 && state.idx[pos - 1] > index)
    {
      state.idx[pos] = state.idx[pos - 1];
      pos--;
    }

    state.idx[pos] = index;
    state.size++;

    return state;
  }

  vector<int> maximumWeight(vector<vector<int>>& intervals) {
    int n = intervals.size();
    vector<array<long long, 4>> arr(n);

    for(int i = 0; i < n; i++)
    {
      arr[i] = 
      {
        intervals[i][0],
        intervals[i][1],
        intervals[i][2],
        i
      };
    }

    sort(arr.begin(), arr.end(), [](const auto& a, const auto& b) { return a[1] < b[1]; });

    vector<long long> ends(n);

    for(int i = 0; i < n; i++) ends[i] = arr[i][1];

    vector<int> prev(n);

    for(int i = 0; i < n; i++)
      prev[i] = lower_bound(ends.begin(), ends.begin() + i, arr[i][0]) - ends.begin() - 1;

    vector<array<State, 5>> dp(n + 1);

    for(int i = 1; i <= n; i++)
    {
      for(int j = 1; j <= 4; j++)
      {
        State skip = dp[i - 1][j];

        State take = dp[prev[i - 1] + 1][j - 1];
        take.score += arr[i - 1][2];
        take = addIndex(take, arr[i - 1][3]);

        dp[i][j] = isBetter(take, skip) ? take : skip;
      }
    }

    State& ans = dp[n][4];

    return vector<int>(ans.idx.begin(), ans.idx.begin() + ans.size);
  }
};
