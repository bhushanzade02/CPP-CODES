class Solution
{
public:
    int maximumWealth(vector<vector<int>> &accounts)
    {

        int maxwealth = 0;
        int r = accounts.size();
        int c = accounts[0].size();
        for (int i = 0; i < r; i++)
        {
            int rmax = 0;
            for (int j = 0; j < c; j++)
            {
                rmax += accounts[i][j];
            }
            maxwealth = max(maxwealth, rmax);
        }
        return maxwealth;
    }
};