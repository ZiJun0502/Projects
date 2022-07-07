class Solution {
public:
    int n, m, c, now;
    bool visited[50][50];
    void DFS(int i, int j, vector<vector<int>>& image)
    {
        image[i][j] = c;
        if(visited[i][j]) return;
        visited[i][j] = 1;
        //cout << i <<' ' << j << ' '<<'\n';
        if(i < n-1 && image[i+1][j] == now)
        {
            DFS(i + 1, j, image);
        }
        if(i > 0 && image[i-1][j] == now)
        {
            DFS(i-1, j, image);
        }
        if(j > 0 && image[i][j-1] == now)
        {
            DFS(i, j-1, image);
        }
        if(j < m-1 && image[i][j+1] == now)
        {
            DFS(i, j+1, image);
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int i, int j, int color) {
        n = image.size();
        m = image[0].size();
        c = color;
        now = image[i][j];
        //cout << "hi";
        DFS(i, j, image);
        return image;
    }
};