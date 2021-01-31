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

int main() {
  int N, M;
  cin >> N >> M;
  typedef pair<int, int> P;

  vector<P> AB(N);
  rep(i, N) {
    cin >> AB[i].fi >> AB[i].se;
    AB[i].fi;
  }
  sort(all(AB));
  priority_queue<int> p;

  int ans = 0;
  int x = 0;
  repp(i, 1, M) {
    while (AB[x].fi <= i) {
      p.push(AB[x].se);
      x++;
    }
    if (!p.empty()) {
      ans += p.top();
      p.pop();
    }
  }

  cout << ans << endl;
}