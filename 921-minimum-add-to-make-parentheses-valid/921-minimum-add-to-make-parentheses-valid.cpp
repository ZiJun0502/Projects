class Solution {
public:
    int minAddToMakeValid(string s) {
        int n = s.size();
        bool stack[n];
        memset(stack, 0 , sizeof(stack));
        int size = 0;
        for(int i = 0 ; i < n ; i++){
            if(s[i] == '('){
                stack[size++] = 1;
            }
            else{
                if(size){
                    if(stack[size-1]== 1){size--;}
                    else stack[size++] = 0;
                }
                else stack[size++] = 0;
            }
            //cout << size << ' ';
        }
        return size;
    }
};