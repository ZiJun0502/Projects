class Solution {
public:
    int poorPigs(int buckets, int die, int test) {
        int times = test / die+1;
        int ans = ceil(log(buckets)/log(times));
        
        return ans;
    }
};