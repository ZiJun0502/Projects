class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string, vector<string>> m;
        for(string& s : paths){
            stringstream ss;
            ss << s;
            string ori, path, content;
            ss >> ori;
            while(ss >> content){
                path = ori;
                auto i = content.find('(');
                path.push_back('/');
                path += content.substr(0, i);
                content = content.substr(i+1, content.size() - i - 2);
                //cout  << content <<'\n';
                m[content].push_back(path);
            }
        }
        vector<vector<string>> ans;
        for(auto& i : m){
            if(i.second.size() > 1){
                ans.push_back(i.second);
            }
        }
        return ans;
    }
};