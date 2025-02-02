class Solution{
public:

int heightchecker(vector<int>& heights){
    vector<int> expected(heights);
    sort(expected.begin(),expected.end());

    int cnt=0;
    for(int i=0;i<heights.size();i++)
    {
        if(height[i]!=expected[i])
        {
            cnt++;
        }
    }
return cnt;

}

};