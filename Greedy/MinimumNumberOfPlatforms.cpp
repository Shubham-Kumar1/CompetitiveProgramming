int calculateMinPatforms(int at[], int dt[], int n) {

    sort(at,at+n);
    sort(dt,dt+n);
    int i=1,j=0,plat=1,maxi=1;
    while(i<n && j<n)
    {
        if(at[i]<=dt[j])
        {
            plat++;
            i++;
        }else{
            plat--;
            j++;
        }
        maxi = max(maxi,plat);
    }
    return maxi;
}
