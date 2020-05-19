#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define rep(i, n) for (int i = 0; i < (n); ++i)


template <typename G>
vector<int> topological_sort(const G& g) {
  const int N = (int)g.size();
  vector<int> deg(N);
  for (int i = 0; i < N; i++) {
    for (auto& to : g[i])
      ++deg[to];
  }
  stack<int> st;
  for (int i = 0; i < N; i++) {
    if (deg[i] == 0)
      st.emplace(i);
  }
  vector<int> ord;
  while (!st.empty()) {
    auto p = st.top();
    st.pop();
    ord.emplace_back(p);
    for (auto& to : g[p]) {
      if (--deg[to] == 0)
        st.emplace(to);
    }
  }
  return ord;
}

/*
http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_4_B&lang=jp
*/

int main() {
  int V, E;
  cin >> V >> E;
  vector<int> s(E), t(E);
  rep(i, E) {
    cin >> s[i] >> t[i];
  }

  vector<vector<int>> G(V);
  rep(i, E) {
    G[s[i]].pb(t[i]);
  }

  auto ord = topological_sort(G);
  rep(i, V) {
    cout << ord[i] << endl;
  }
}