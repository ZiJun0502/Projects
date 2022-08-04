class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int ans = 0;
        int n = points.size();
        if(n == 1) return 1;
        for(int i = 0 ; i < n-1 ; i++){
            map<vector<float>,int> m;
            auto p = points[i];
            double x0 = p[0], y0 = p[1];
            for(int j = i+1 ; j < n ; j++){
                auto p1 = points[j];
                double x1 = p1[0], y1 = p1[1];
                double a,b;
                if(x1 == x0){
                    m[{1e9, (float)x0}]++;
                    continue;
                }
                a = (y1 - y0) / (x1 - x0);
                b = y1 - a * x1;
                //cout << a <<' '<< b <<' '<<'\n';
                m[{(float)a,(float)b}]++;
            }
            for(auto i : m){
                //cout << i.first[0] <<' '<<i.first[1] <<' '<<i.second<<'\n';
                ans = max(ans, i.second+1);
            }//cout << '\n';
        }
        return ans;
    }
};