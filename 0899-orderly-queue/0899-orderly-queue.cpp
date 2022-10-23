class Solution {
public:
    string orderlyQueue(string s, int k) {
        int n = s.size();
        if(k > 1){
            sort(s.begin(), s.end());
            return s;
        }
        else{
            string temp = s;
            string mini = s;
            int now = 0;
            for(int i = 1 ; i < n ; i++){
                temp = s.substr(i, n-1) + s.substr(0, i);
                if(temp < mini) mini = temp;
            }
            return mini;
        }
        return "";
    }
};