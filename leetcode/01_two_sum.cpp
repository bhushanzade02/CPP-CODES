#include <iostream>
using namespace std;

int main()
{
    int nums[4] = {1, 2, 3, 4};
    int target =7;
    for (int i = 0; i < 4; i++)
    {
        for (int j = i + 1; j < 4; j++)
        {
            if (nums[i] + nums[j] == target)
                cout << nums[i]<<nums[j];
        }
    }
    return 0;
}