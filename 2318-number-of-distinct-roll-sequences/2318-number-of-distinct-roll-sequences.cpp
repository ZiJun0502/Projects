const int MOD=1e9+7;
class Solution {
public:
    int w[10005][7][7];
    int distinctSequences(int n) {
        memset(w,0,sizeof w);
        w[0][0][0]=1;
        for(int i=1;i<=n;++i) {
            for(int x=0;x<=6;++x)
                for(int y=0;y<=6;++y)
                    for(int z=1;z<=6;++z)
                        if(y!=0&&__gcd(y,z)>1);else if(y==z||x==z);else (w[i][y][z]+=w[i-1][x][y])%=MOD;
        }
        int ans=0;
            for(int x=0;x<=6;++x)
                for(int y=0;y<=6;++y) (ans+=w[n][x][y])%=MOD;return ans;
    }
};