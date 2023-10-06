vector<int> findRepeatingAndMissingNumbers(vector<int> nums)
{
    int n = nums.size();
    int repeat = -1, miss = -1;
    for(int i=0;i<n;++i)
    {
        int val = nums[i];
        if(nums[i] < 0) val = abs(val);

        int index = val-1;
        if(nums[index] > 0)
        {
            nums[index] = -nums[index];
        }else{
            repeat = val;
        }
    }
    for(int i=0;i<n;++i)
    {
        if(nums[i] > 0)
        {
            miss = i+1;
            break;
        }
    }
    vector<int>ans;
    ans.push_back(repeat);
    ans.push_back(miss);
    return ans;
}
