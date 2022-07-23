class Solution {
public:
    void merge(vector<pair<int, int>> &nums, int start, int mid, int end, vector<int> &res)
    {
        vector<pair<int, int>> sorted(end - start + 1);

        int i = start;
        int j = mid + 1;
        int k = 0;

        while (i <= mid and j <= end)
        {
            if (nums[i].first <= nums[j].first)
            {
                sorted[k] = nums[j];
                j++;
                k++;
            }
            else
            {
                res[nums[i].second] += end - j + 1;
                sorted[k] = nums[i];
                i++;
                k++;
            }
        }

        while (i <= mid)
        {
            sorted[k] = nums[i];
            i++;
            k++;
        }

        while (j <= end)
        {
            sorted[k] = nums[j];
            j++;
            k++;
        }

        i = start;
        k = 0;
        while (i <= end)
        {
            nums[i] = sorted[k];
            i++;
            k++;
        }
    }

    void Merge_Sort(vector<pair<int, int>> &nums, int start, int end, vector<int> &res)
    {

        if (start < end)
        {
            int mid = start + (end - start) / 2;

            Merge_Sort(nums, start, mid, res);
            Merge_Sort(nums, mid + 1, end, res);
            merge(nums, start, mid, end, res);
        }
        else
            return;
    }

    vector<int> countSmaller(vector<int> &nums)
    {
        vector<pair<int, int>> nums2(nums.size());
        for (int i = 0; i < nums.size(); i++)
        {
            nums2[i] = {nums[i], i};
        }
        vector<int> res(nums.size(), 0);
        Merge_Sort(nums2, 0, nums.size() - 1, res);

        return res;
    }
};