class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int time) {
        sort(clips.begin(),clips.end());
        int now = 0, next = 0;
        int n = clips.size();
        int ans = 0;
        for(int i = 0 ; i < n ; i++)
        {
            if(clips[i][0] <= now){
                next = max(next, clips[i][1]);
            }
            else
            {
                now = next;
                next = clips[i][1];
                if(now < clips[i][0]) return -1;
                ans++;
            }
            if(clips[i][1] >= time)
            {
                return ans+1;
            }
            
        }
        if(now < time) return -1;
        return ans;
    }
    
};