template <int n, typename i_t = int>
struct bit_t {
    array<i_t, 1 + n> D{};
	void add(int i, int d = 1) { for (++i; i <= n; i += i & -i) D[i] += d; }
	i_t sum(int i) const { i_t s = 0; for (++i; i > 0; i -= i & -i) s += D[i]; return s; }
};

class Solution {
public:
    vector<int> countSmaller(vector<int>& X) {
		const int M = 10'000;
		vector<int> R(X.size());
		bit_t<2 * M> B;
        for (int i = X.size(); i--;) {
			int x = X[i] + M;
			R[i] = B.sum(x - 1);
			B.add(x);
		}
        return R;
    }
};