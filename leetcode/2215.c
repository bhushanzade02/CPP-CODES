
class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        int sz1 = nums1.size(), sz2 = nums2.size();
        unordered_set<int> u_set, u_set2;

        // Insert elements of nums1 into u_set
        for (int i = 0; i < sz1; ++i)
            u_set.insert(nums1[i]);

        // Insert elements of nums2 into u_set2
        for (int i = 0; i < sz2; ++i)
            u_set2.insert(nums2[i]);

        vector<int> l1, l2;

        // Find elements in u_set that are not in u_set2
        for (auto e : u_set)
            if (!u_set2.count(e))
                l1.push_back(e);

        // Find elements in u_set2 that are not in u_set
        for (auto e : u_set2)
            if (!u_set.count(e))
                l2.push_back(e);

        // Return the result
        return {l1, l2};
    }
};
