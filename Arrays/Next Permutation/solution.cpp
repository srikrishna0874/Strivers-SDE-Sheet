class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        int n = nums.size();
        int break_index = n - 1;
        int i = n - 2;
        while (i >= 0 && nums[i] >= nums[i + 1])
        {
            i--;
        }
        if (i == -1)
        {
            reverse(nums.begin(), nums.end());
            return;
        }
        break_index = i;
        int mi = INT_MAX, mi_ind = -1;
        for (int i = break_index + 1; i < n; i++)
        {
            if (nums[i] > nums[break_index] && mi > nums[i])
            {
                mi = nums[i];
                mi_ind = i;
            }
        }
        swap(nums[break_index], nums[mi_ind]);
        sort(nums.begin() + break_index + 1, nums.end());
    }
};