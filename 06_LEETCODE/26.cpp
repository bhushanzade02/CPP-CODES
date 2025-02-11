class Solution {
    public:
        int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
            int sz1 = nums1.size();
            int sz2 = nums2.size();
            int ans = 0;
            
            // Case when both sizes are even
            if (sz1 % 2 == 0 && sz2 % 2 == 0) {
                return 0;
            }
    
            // XOR elements of nums1 if nums2's size is odd
            if (sz2 % 2 == 1) {
                for (auto n : nums1) {
                    ans ^= n;
                }
            }
    
            // XOR elements of nums2 if nums1's size is odd
            if (sz1 % 2 == 1) {
                for (auto n : nums2) {
                    ans ^= n;
                }
            }
    
            return ans;
        }
    };  