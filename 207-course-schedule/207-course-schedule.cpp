class Solution {
public:
    short int visited[2000];
    int n;
    bool ans = true;
    vector<vector<int>> g;
    void DFS(int i){
        //cout << i <<' ';
        visited[i] = 1;
        for(int j : g[i]){
            if(visited[j] == 0){
                DFS(j); 
            } 
            else if(visited[j] == 1){
                ans = false;
                //cout << i <<' '<<j<<'\n';
            }
        }
        //cout << '\n';
        visited[i] = 2;
        return ;
    }
    bool canFinish(int nn, vector<vector<int>>& pre) {
        n = nn;
        g.resize(n);
        for(auto i : pre){
            g[i[1]].push_back(i[0]);
        }
        for(int i = 0 ; i < n ; i++){
            //memset(visited, 0, sizeof(visited));
            //cout << i <<' ';
            //for(int j = 0 ; j < n ; j++) cout << visited[j]<<' ';
            //cout << '\n';
            
            DFS(i);
        }
        return ans;
    }
};