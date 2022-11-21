class Solution {
public:
    int n, m;
    bool valid(int i, int j){
        return i >= 0 && i < n && j >= 0 && j < m; 
    }
    bool win(int i, int j){
        return i == 0 || i == n-1 || j == 0 || j == m-1;
    }
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        queue<vector<int>> q;
        int dir[4][2] = {{1,0}, {0,1},{-1,0},{0,-1}};
        q.push({entrance[0], entrance[1], 0});
        n = maze.size(), m = maze[0].size();
        maze[entrance[0]][entrance[1]] = '+';
        while(!q.empty()){
            auto now = q.front();
            //cout << now[0] << ' ' << now[1] << ' ' << now[2] << '\n';
            q.pop();
            
            if(now[2] > 0 && win(now[0], now[1])){
                return now[2];
            }
            
            for(auto d : dir){
                int i = now[0] + d[0];
                int j = now[1] + d[1];
                if(!valid(i, j)) continue;
                if(maze[i][j] == '.'){
                    maze[i][j] = '+';
                    q.push({i, j, now[2]+1});
                }
            }
        }
        return -1;
    }
};