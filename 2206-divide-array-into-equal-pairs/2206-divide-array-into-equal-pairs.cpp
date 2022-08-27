class Solution {
public:
    bool divideArray(vector<int>& nums) {
        int count[500] = {};
        for(int i : nums){
            count[i-1]++;
        }
        for(int i : count){
            if(i % 2 != 0) return false;
        }
        return true;
    }
};