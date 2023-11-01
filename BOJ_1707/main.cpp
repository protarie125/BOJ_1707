#include <algorithm>
#include <bit>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

using namespace std;

using ll = long long;
using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using pii = pair<int, int>;
using vii = vector<pii>;
using pll = pair<ll, ll>;
using vll = vector<pll>;
using vs = vector<string>;

int v, e;
vvi adj;
vi visit;

void dfs(int i) {
	auto st = stack<int>{};
	st.push(i);
	visit[i] = 1;

	while (!st.empty()) {
		const auto x = st.top();
		st.pop();

		for (const auto& y : adj[x]) {
			if (0 != visit[y]) {
				continue;
			}

			st.push(y);
			if (1 == visit[x]) {
				visit[y] = 2;
			}
			else {
				visit[y] = 1;
			}
		}
	}
}

bool isBipartite() {
	for (auto i = 1; i <= v; ++i) {
		const auto cx = visit[i];
		for (const auto& y : adj[i]) {
			const auto cy = visit[y];

			if (cx == cy) {
				return false;
			}
		}
	}

	return true;
}

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int k;
	cin >> k;
	while (0 < (k--)) {
		cin >> v >> e;

		adj = vvi(v + 1, vi{});
		for (auto i = 0; i < e; ++i) {
			int x, y;
			cin >> x >> y;

			adj[x].push_back(y);
			adj[y].push_back(x);
		}

		visit = vi(v + 1, 0);
		for (auto i = 1; i <= v; ++i) {
			if (0 != visit[i]) {
				continue;
			}

			dfs(i);
		}

		if (isBipartite()) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
	}

	return 0;
}