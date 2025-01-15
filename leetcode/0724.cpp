class Solution{
    public:
    int pivotIndex(vector<int>& nums){
        int sz= nums.size();
        int rs=accumulate(nums.begin(),nums.end(),0);

        int ls=0;
        for(int i=0;i<sz;i++)
        {
            rs=rs-nums[i];
            if(rs==ls)
            return i;
            ls+=nums[i];
        }
        return -1;
    }
};