// 3. Longest Substring Without Repeating Characters



class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> sub;  // Set to track characters in the current window
        int left = 0, right = 0;  // Pointers for the sliding window
        int cnt = 0;  // Variable to store the length of the longest substring

        // Traverse through the string using a sliding window
        while (right < s.length()) {
            // If the current character is not in the set, add it and expand the window
            if (sub.count(s[right]) == 0) {
                sub.insert(s[right]);  // Insert the character into the set
                cnt = max(cnt, right - left + 1);  // Update the maximum length
                right++;  // Move the right pointer to expand the window
            } 
            // If the current character is already in the set, shrink the window from the left
            else {
                sub.erase(s[left]);  // Remove the character at the left pointer
                left++;  // Move the left pointer to shrink the window
            }
        }

        return cnt;  // Return the length of the longest substring without repeating characters
    }
};