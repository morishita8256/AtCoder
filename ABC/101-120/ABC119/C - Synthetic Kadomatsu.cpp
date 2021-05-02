#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repp(i, a, b) for (int i = a; i <= (b); ++i)
#define repr(i, a, b) for (int i = a; i >= (b); --i)
typedef long long ll;
const int INF = 1001001001;
const ll LINF = 1001001001001001001ll;
const int MOD = 1e9 + 7;

template <class T>
inline bool chmin(T &a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}

template <class T>
inline bool chmax(T &a, T b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}

int N, A, B, C;
vector<int> l;

int dfs(int itr, int a, int b, int c) {
  /* itr番目の竹までで、Aの材料の長さの合計がa、……のときの使用MP */
  if (itr == N) {
    if (min(a, min(b, c)) > 0)
      return abs(a - A) + abs(b - B) + abs(c - C);
    else
      return INF;
  }
  int next = dfs(itr + 1, a, b, c);
  chmin(next, dfs(itr + 1, a + l[itr], b, c) + (a == 0 ? 0 : 10));
  chmin(next, dfs(itr + 1, a, b + l[itr], c) + (b == 0 ? 0 : 10));
  chmin(next, dfs(itr + 1, a, b, c + l[itr]) + (c == 0 ? 0 : 10));
  return next;
}

int main() {
  cin >> N >> A >> B >> C;
  l.resize(N);
  rep(i, N) cin >> l[i];

  cout << dfs(0, 0, 0, 0) << endl;
}