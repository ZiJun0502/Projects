class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int n = words.size();
        unordered_map<string, int> m;
        unordered_map<string, int> du;
        int p = 0, maxi = 0;
        bool flag = 0;
        for(string& s : words){
            m[s]++;
        }
        for(auto& i : m){
            string temp;
            temp.push_back(i.first[1]);
            temp.push_back(i.first[0]);
            if(m.find(temp) != m.end()){
                if(temp[0] == temp[1]){
                    flag |= m[temp] % 2;
                    //cout << temp << ' ' << m[temp] << '\n';
                    p += 2*(m[temp]/2);
                }else
                p += min(m[temp], i.second);
            }
        }
        return p * 2 + flag * 2;
    }
};