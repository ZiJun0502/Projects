class Solution {
public:
    int maximumRows(vector<vector<int>>& mat, int cols) {
        int m=mat.size(),n=mat[0].size(),ans=0;
        int mask=((1<<n)-1);
        // use mask to generate every possible columns combination
        while(mask){
            unordered_set<int>select;
            for(int i=0;i<n;i++){
                if(((mask>>i)&1)==1)
                    select.insert(i);
            }
            // if subset contains exaclty "cols" columns then we can use this subset
            if(select.size()==cols){
                int cnt=0;
                for(int j=0;j<m;j++){
                    bool flag=true;
                    for(int k=0;k<n;k++){
                        // if any row contains 1 in  column other than columns which we have in "select" then this row is not valid row for our answer
                        if(mat[j][k]==1 && select.count(k)==0){
                            flag=false;
                            break;
                        }
                    }
                    if(flag)
                        cnt++;
                }
                ans=max(ans,cnt);
            }
            mask--;
        }
        return ans;
    }
};