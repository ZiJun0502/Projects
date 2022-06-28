class Solution {
public:
    int countHousePlacements(int n) {
        int ans = 0;
        int mod = 1e9+7;
        int houseEnding = 1; // number of ways to place with house on the endpoint.
        int spaceEnding = 1; //number of ways to place with an space on the endpoint.
        long long total = 2;
        for(int i = 2 ; i <= n ; i++)
        {
            houseEnding = spaceEnding; // if ending with an space, we can put a house on it.
            spaceEnding = total; // we can always choose to put an space on the endpoint.
            total = (houseEnding + spaceEnding) % mod; 
        }
        // number of ways is no.top * no.down, by symmetry:
        return (total * total) % mod;
    }
};