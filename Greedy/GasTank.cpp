int minimumStartingIndex(vector<int> &gas, vector<int> &cost, int n) 
{
    int start = 0;
    int capacity = 0;
    int deficiency = 0;

    for(int i=0;i<n;++i)
    {
        capacity+=(gas[i] - cost[i]);
        if(capacity < 0)
        {
            start = i+1;
            deficiency+=capacity;
            capacity=0;
        }
    }
    
    if(capacity+deficiency>=0) return start;
    return -1;
}
