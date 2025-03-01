class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> stk;
        
        // First pass: Mark invalid parentheses
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                stk.push(i);
            } else if (s[i] == ')') {
                if (!stk.empty()) {
                    stk.pop();
                } else {
                    s[i] = '#'; // Mark invalid closing parenthesis
                }
            }
        }
        
        // Mark remaining unmatched opening parentheses
        while (!stk.empty()) {
            s[stk.top()] = '#';
            stk.pop();
        }
        
        // Build the valid string
        string ans;
        for (char c : s) {
            if (c != '#') {
                ans += c;
            }
        }
        
        return ans;
    }
};
