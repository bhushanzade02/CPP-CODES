class Solution {
    public:
        bool doesValidArrayExist(vector<int>& derived) {
    
            int sz= derived.size();
            int ans =0;
            for(int i =0;i<sz;i++)
            {
                ans =ans^derived[i];
                
            }
            return (ans ==0);
            
        }
    };