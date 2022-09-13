class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int n = data.size();
        bitset<8> b;
        for(int i = 0 ; i < n ; i++){
            b = data[i];
            if(b[7] == 1){
                int count = 0;
                for(int j = 6 ; j >= 0 ; j--){
                    if(b[j] == 1) count++;
                    else break;
                }
                if(count > 3) return false;
                if(count == 0) return false;
                while(count-- && i+1 < n){
                    b = data[++i];
                    if(b[b.size()-1] != 1 || b[b.size()-2] != 0) 
                        return false;
                }
                if(count != -1) return false;
            }
            else continue;
        }
        return true;
    }
};