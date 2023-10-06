
// You are given two arrays, ‘arr1’ of size 'N' and ‘arr2’ of size 'M'. You need to create an array of bitwise AND of all the
// possible pairs between the elements of both arrays, and your task is to find the XOR sum of the array.
// The XOR sum of an array is equal to the XOR of all elements of the array.


int xorSum(vector<int> &arr1, vector<int> &arr2)
{
    // Write your code here
    int n = arr1.size();
    int m = arr2.size();

    int ans1 = 0, ans2=0;

    for(int i=0;i<n;++i) ans1^=arr1[i];
    for(int i=0;i<m;++i) ans2^=arr2[i];

    return (ans1 & ans2);

}

