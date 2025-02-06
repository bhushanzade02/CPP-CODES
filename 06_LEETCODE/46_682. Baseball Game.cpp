class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> stk;
        
        for (const string& op : operations) {
            if (op == "C") {
                if (!stk.empty()) stk.pop();
            } 
            else if (op == "D") {
                if (!stk.empty()) stk.push(2 * stk.top());
            } 
            else if (op == "+") {
                if (stk.size() >= 2) {
                    int top1 = stk.top(); stk.pop();
                    int top2 = stk.top();
                    stk.push(top1);
                    stk.push(top1 + top2);
                }
            } 
            else {
                stk.push(stoi(op));
            }
        }
        
        int ans = 0;
        while (!stk.empty()) {
            ans += stk.top();
            stk.pop();
        }
        return ans;
    }
};
 b