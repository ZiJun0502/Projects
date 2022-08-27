class Solution {
public:
    bool divideArray(vector<int>& nums) {
        int count[501] = {};
        for(int i : nums){
            count[i]++;
        }
        for(int i : count){
            if(i % 2 != 0) return false;
        }
        return true;
    }
};