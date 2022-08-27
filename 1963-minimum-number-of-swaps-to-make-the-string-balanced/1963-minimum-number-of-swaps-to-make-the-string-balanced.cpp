class Solution {
public:
    int minSwaps(string s) {
        int n = s.size();
        bool stack[n/2];
        memset(stack, 0, sizeof(stack));
        //bool* size = stack;
        int size = 0;
        for(int i = 0 ; i < n ; i++){
            if(s[i] == '['){
                stack[size++] = 1;
            }
            else{
                if(size){
                    size--;
                    if(stack[size] == 0){
                        size++;
                    }
                }
                
            }
        }
        return (size+1)/2;
    }
};