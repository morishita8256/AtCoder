#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fi first
#define se second
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repp(i, a, b) for (int i = a; i <= (b); ++i)
#define repr(i, a, b) for (int i = a; i >= (b); --i)
#define bit(n) (1LL << (n))
#define sz(x) ((int)(x).size())
typedef long long ll;
const int INF = 1001001001;
const ll LINF = 1001001001001001001ll;
const int MOD = 1000000007;

template <class T>
inline bool chmin(T& a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}

template <class T>
inline bool chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}

struct edge {
  int from, to, cost;

  edge(int from, int to, int cost) : from(from), to(to), cost(cost) {}
};

int lg2(int n) {
  int temp = 0;
  while (n) {
    temp++;
    n /= 2;
  }
  temp--;
  return temp;
}

int pw2(int n) {
  int temp = 1;
  rep(i, n) {
    temp *= 2;
  }
  return temp;
}

int main() {
  int L;
  cin >> L;

  vector<edge> ans;
  rep(i, 19) {
    ans.pb(edge(i + 1, i + 2, 0));
  }

  int c = 1;
  rep(i, lg2(L)) {
    ans.pb(edge(20 - i - 1, 20 - i, c));
    c *= 2;
  }

  L -= pw2(lg2(L));

  while (L) {
    int lg = lg2(L);
    ans.pb(edge(1, 20 - lg, c));
    c += pw2(lg);
    L -= pw2(lg);
  }

  int M = sz(ans);
  cout << 20 << ' ' << M << endl;
  rep(i, M) {
    printf("%d %d %d\n", ans[i].from, ans[i].to, ans[i].cost);
  }
}