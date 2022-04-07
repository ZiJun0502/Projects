class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        sort(stones.begin(), stones.end());
        for(int i = stones.size()-1 ; i > 0 ; i--)
        {
            
            int temp = stones[i] - stones[i - 1];
            stones[i - 1] = temp;
            stones.pop_back();
            stones.pop_back();
            for(int j = i - 2 ; j >= 0 ; j --)
            {
                if(stones[j] > temp)
                    swap(stones[j], stones[j + 1]);
                else break;
            }
        }
        return stones[0];
    }
};