class Solution {
public:
    int n, m, c, now;
    bool visited[50][50];
    void DFS(int i, int j, vector<vector<int>>& image)
    {
        image[i][j] = c;
        if(visited[i][j]) return;
        visited[i][j] = 1;
        if(i < n && image[i+1][j] == now && !visited[i+1][j])
            DFS(i + 1, j, image);
        if(i > 0 && image[i-1][j] == now && !visited[i-1][j])
            DFS(i-1, j, image);
        if(j > 0 && image[i][j-1] == now && !visited[i][j-1])
            DFS(i, j-1, image);
        if(j < m && image[i][j+1] == now && !visited[i][j+1])
            DFS(i, j+1, image);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int i, int j, int color) {
        n = image.size()-1;
        m = image[0].size()-1;
        c = color;
        now = image[i][j];
        DFS(i, j, image);
        return image;
    }
};