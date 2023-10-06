
void TOH(int numberOfDisk,int src, int aux, int des, vector<vector<int>> &ans)
{
    if(numberOfDisk == 0) return;

    TOH(numberOfDisk - 1, src,des,aux,ans);

    ans.push_back({src,des});

    TOH(numberOfDisk - 1, aux,src,des,ans);

}



vector<vector<int>> towerOfHanoi(int n)
{
    vector<vector<int>> ans;

    TOH(n,1,2,3,ans);

    return ans;

}
