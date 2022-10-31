class Solution {
public:
    using state = vector<int>;
    int seen[40][40];
    int n, m;
    bool valid(int i, int j){
        return i < n && i >= 0 && j < m && j >=0;
    }
    int shortestPath(vector<vector<int>>& grid, int k) {
        n = grid.size(), m = grid[0].size();
        queue<state> q;
        state init = {0, 0, k, 0};
        int direction[4][2] = {{1,0}, {0,1}, {-1,0}, {0,-1}};
        q.push(init);
        int ans = -1;
        memset(seen, -1, sizeof(seen));
        while(!q.empty()){
            state s = q.front();
            q.pop();
            if(s[0] == n-1 && s[1] == m-1){
                ans = s[3];
                goto end;
            }
            if(seen[s[0]][s[1]] != -1 && s[2] <= seen[s[0]][s[1]]) continue;
            seen[s[0]][s[1]] = s[2];
            for(auto d : direction){
                int i = s[0]+d[0], j = s[1]+d[1] , kk =s[2];
                if(valid(i, j)){
                    //wall
                    if(grid[i][j]){
                        if(kk > 0){
                            q.push({i, j, kk-1, s[3]+1});
                        }
                    }else{
                        q.push({i, j, kk, s[3]+1});
                    }
                }
            }
        }
        end:
        return ans;
    }
};