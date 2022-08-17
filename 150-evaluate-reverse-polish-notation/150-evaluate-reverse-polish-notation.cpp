class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int n = tokens.size();
        auto isoper=[](char c){
            return c == '/' || c == '+' || c =='-' || c == '*';
        };
        int stack[5000];
        int size = 0;
        for(int i = 0 ; i < n ; i++){
            // for(int i = 0 ; i < size ; i++) cout << stack[i] <<' ';
            // cout << '\n';
            if(tokens[i].size() < 2 && isoper(tokens[i][0])){
                switch(tokens[i][0]){
                    case'+':
                        stack[size-2] = stack[size-1] + stack[size-2];
                        size--;
                        break;
                    case'-':
                        stack[size-2] = stack[size-2] - stack[size-1];
                        size--;
                        break;
                    case'*':
                        stack[size-2] = stack[size-1] * stack[size-2];
                        size--;
                        break;
                    case'/':
                        stack[size-2] = stack[size-2] / stack[size-1];
                        size--;
                        break;
                }
            }else{
                stack[size++] = stoi(tokens[i]);
            }
        }
        return stack[0];
    }
};