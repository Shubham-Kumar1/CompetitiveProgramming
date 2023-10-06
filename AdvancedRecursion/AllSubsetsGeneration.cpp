void f(vector<int> &arr, int ind, vector<vector<int>> &Subsets,vector<int> &temp)
{
    if(ind == -1)
    {
        Subsets.push_back(temp);
        return;
    }
    // pick
    temp.push_back(arr[ind]);
    f(arr,ind-1,Subsets,temp);
    temp.pop_back();

    // not pick
    f(arr,ind-1,Subsets,temp);
}

vector<vector<int>> FindAllSubsets(int n, vector<int> &arr){

    vector<vector<int>> Subsets;
    vector<int> temp;
    int ind = n-1;
    f(arr,ind,Subsets,temp);

    return Subsets;

}
