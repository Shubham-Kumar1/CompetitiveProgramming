
bool isValid(int i, int j, int n,vector<vector<int>> &vis)
{
    if (i>=0 && i<n && j>=0 && j<n && !vis[i][j]) return true;
    return false;
}

int minSteps(pair<int, int> knightPosition, pair<int, int> targetPosition, int size) {

    int n = size;

    int x1 = knightPosition.first; // x coordinate of knight
    int y1 = knightPosition.second; //  y coordinate of knight

    int tx = targetPosition.first;  // TARGET x coordinate
    int ty = targetPosition.second; // TARGET y coordinate

    if(x1==tx && y1==ty) return 0;

    vector<vector<int>> vis(n+1,vector<int>(n+1,0));
    queue< pair<int,int>> q;

    q.push({x1,y1});
    vis[x1][y1] = 1;

    int ans = 0;  // number of steps

    while(!q.empty())
    {
        int sz = q.size();
        ans++;

        while(sz != 0)
        {
            pair<int,int> p = q.front();
            q.pop();

            int xx = p.first;
            int yy = p.second;

            int dx[8] = {1, 1, -1, -1, 2, -2, 2, -2};
	        int dy[8] = {2, -2, 2, -2, 1, 1, -1, -1};

            for(int i=0;i<8;++i)
            {
                int new_x = xx + dx[i];
                int new_y = yy + dy[i];

                if(new_x==tx && new_y==ty) return ans;

                if(isValid(new_x,new_y,n,vis))
                {
                    vis[new_x][new_y] = 1;
                    q.push({new_x,new_y});
                }
            }
            sz--;
        }

    }
}
