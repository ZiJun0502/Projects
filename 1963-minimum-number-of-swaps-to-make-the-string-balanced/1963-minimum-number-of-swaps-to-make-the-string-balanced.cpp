class Solution {
public:
    int minSwaps(string s) {
        int n = s.size();
        //bool stack[n/2];
        vector<bool> stack(n/2);
        //memset(stack, 0, sizeof(stack));
        //bool* size = stack;
        auto size = stack.begin();
        for(int i = 0 ; i < n ; i++){
            if(s[i] == '['){
                *size = 1;
                size++;
            }
            else{
                if(size - stack.begin()){
                    size--;
                    if(*size == 0){
                        size++;
                    }
                }
                
            }
        }
        return (size-stack.begin()+1)/2;
    }
};