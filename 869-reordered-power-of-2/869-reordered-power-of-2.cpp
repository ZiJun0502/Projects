class Solution {
public:
    bool reorderedPowerOf2(int n) {
        int ori[10] = {};
        while(n){
            int temp = n/10;
            ori[n - temp * 10]++;
            n = temp;
        }
        int iter = 1;
        for(int i = 0 ; i < 30 ; i++){
            int count[10] = {};
            int num = iter;
            while(num){
                //cout << num <<'\n';
                int temp = num / 10;
                count[num - temp * 10]++;
                num = temp;
            }
            bool good = 1;
            for(int i = 0 ; i < 10 ; i++){
                if(count[i] != ori[i]){
                    good = 0;
                    break;
                }
            }
            if(good) return 1;
            iter<<= 1;
        }
        return false;
    }
};