class Solution {
public:
    vector<int> parent;
    int getParent(int i)
    {
        if(parent[i] == i) return i;
        return getParent(parent[i]);
    }
    int minCostConnectPoints(vector<vector<int>>& p) {
        int m = p[0].size();
        int n = p.size();
        priority_queue<vector<int>> edges; // {distance, i , j}
        int d;
        for(int i = 0 ; i < n; i++)
        {
            for(int j = i+1 ; j < n ; j++)
            {
                d = abs(p[i][0] -p[j][0]) + abs(p[i][1] - p[j][1]); 
                edges.push({-1*d, i, j});
            }
        }
        parent = vector<int>(n);
        for(int i = 0 ; i < n ; i++)
        {
            parent[i] = i;
        }
        int a,b;
        int ans = 0;
        int count = 0;
        while(count != n-1)
        {
            vector<int> edge = edges.top();
            a = getParent(edge[1]);
            b = getParent(edge[2]);
            if(a == b)
            {
                edges.pop();
                continue;
            }
            count++;
            ans -= edge[0];
            parent[a] = b;
            edges.pop();
        }
        return ans;
    }
};