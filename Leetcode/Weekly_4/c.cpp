class Solution
{
    map<int, pair<vector<int>, int>> M;

public:
    Solution(vector<int> &nums)
    {
        for (int i = 0; i < nums.size(); ++i)
            M[nums[i]].first.push_back(i);
    }

    int pick(int target)
    {
        M[target].second++;
        M[target].second %= M[target].first.size();
        return M[target].first[M[target].second];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */