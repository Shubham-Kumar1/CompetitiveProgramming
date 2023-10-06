

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};
char d[] = {'D','U','R','L'};

bool isValid(int i,int j,vector<vector<bool>> &visited,vector<vector<bool>> &arr)
{
    int n = arr.size();
    
    return (i>=0 && i< n && j>=0 && j<n && arr[i][j]==true && visited[i][j]==false);
}


void allvalidPaths(int x,int y,string &path,vector<string>&allpaths,vector<vector<bool>>&visited,vector<vector<bool>>&arr)
{
    if(!arr[x][y]) return;
    int n = arr.size();
    if(x==n-1 && y==n-1)
    {
        allpaths.push_back(path);
        return;
    }
    visited[x][y]= true;
    for(int i=0;i<4;++i)
    {
        int newX = x + dx[i];
        int newY = y + dy[i];
        
        if(isValid(newX,newY,visited,arr))
        {
            path.push_back(d[i]);
            allvalidPaths(newX,newY,path,allpaths,visited,arr);
            path.pop_back();
        }
    }
    visited[x][y] = false;
}

vector<string> findAllPaths( vector<vector<bool>> &arr)
{
    //    Write your code here.
    int n = arr.size();
    vector<vector<bool>> visited(n,vector<bool>(n,false));
    string path = "";
    vector<string> allpaths;
    allvalidPaths(0,0,path,allpaths,visited,arr);
    return allpaths;
}
