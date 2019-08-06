class Solution
{
public:
    int movesToMakeZigzag(vector<int> &nums)
    {
        int ret, ans;
        ret = ans = INT_MAX;
        ans = 0;
        for (int i = 1; i < nums.size(); i += 2)
        {
            if (nums[i] < nums[i - 1])
            {
                ans++;
            }
            else if ((i + 1) < nums.size())
            {
                if (nums[i] < nums[i + 1])
                {
                    ans++;
                }
            }
        }
        ret = ans;
        for (int i = 0; i < nums.size(); i += 2)
        {
            if (nums[i] < nums[i - 1])
            {
                ans++;
            }
            else if ((i + 1) < nums.size())
            {
                if (nums[i] < nums[i + 1])
                {
                    ans++;
                }
            }
        }
        return min(ret, ans);
    }
};