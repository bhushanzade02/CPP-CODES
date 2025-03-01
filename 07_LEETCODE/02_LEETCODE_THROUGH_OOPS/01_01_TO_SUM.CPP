#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        for (int i = 0; i < nums.size(); i++)
        {

            for (int j = i + 1; j < nums.size(); j++)
            {
                if (nums[i] + nums[j] == target)
                {
                    return {i, j};
                }
            }
        }
        return {};
    }
};

int main()
{
    Solution sol;
    // vector<int> nums = {2, 11, 7, 15};
    // int target = 9;
    int n, target;
    cout << "enter a  number of elements" <<endl;
    cin >> n;
    vector<int> nums(n);
    cout << "entr the element" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    cout << "enter the Target Sum" << endl;
    cin >> target;

    vector<int> result = sol.twoSum(nums, target);
    cout << result[0] << " ," << result[1] << endl;
    return 0;

    return 0;
}