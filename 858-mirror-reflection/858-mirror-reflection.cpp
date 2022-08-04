class Solution {
public:
    int mirrorReflection(int p, int q) {
        int ans = 0;
        if(p % q != 0){
            int temp = lcm(q, p);
            int hor = temp / q;
            int ver = temp / p;
            if(hor % 2 != 0){
                if(ver % 2 == 0){
                    return 0;
                }
                else return 1;
            }
            else return 2;
        }
        if((p / q) %2 == 0) return 2;
        else return 1;
    }
};