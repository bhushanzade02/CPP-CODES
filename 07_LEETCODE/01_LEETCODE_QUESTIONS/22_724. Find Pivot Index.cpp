class Solution {
public:
    int pivotIndex(vector<int>& nums) {

        int total = accumulate(nums.begin(), nums.end(), 0);
        int lefttotal = 0;

        for (int i = 0; i < nums.size(); i++) {
            int righttotal = total - lefttotal - nums[i];
            if (righttotal == lefttotal) {
                return i;
            }
            lefttotal += nums[i];
        }

        return -1;
    }
};

