class Solution {
public:
    int minSwaps(string s) {
        int n = s.size();
        bool stack[500000];
        memset(stack, 0, sizeof(stack));
        bool* size = stack;
        for(int i = 0 ; i < n ; i++){
            if(s[i] == '['){
                *size = 1;
                size++;
            }
            else{
                if(size - stack){
                    size--;
                    if(*size == 0){
                        size++;
                    }
                }
                
            }
        }
        return (size-stack+1)/2;
    }
};