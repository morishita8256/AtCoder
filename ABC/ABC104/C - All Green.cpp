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

int main() {
  int D, G;
  cin >> D >> G;

  vector<int> p(D), c(D);
  rep(i, D) cin >> p[i] >> c[i];

  int ans = INF;
  rep(i, 1 << D) {
    vector<int> comp;
    vector<int> not_comp;

    rep(j, D) {
      if (i >> j & 1) {
        comp.pb(j + 1);
      } else {
        not_comp.pb(j + 1);
      }
    }

    int score = 0;
    int solve = 0;

    rep(j, comp.size()) {
      int id = comp[j];
      score += 100 * id * p[id - 1] + c[id - 1];
      solve += p[id - 1];
    }

    vector<int> not_comp_score;
    repr(j, not_comp.size() - 1, 0) {
      int id = not_comp[j];
      rep(k, p[id - 1] - 1) { not_comp_score.pb(100 * id); }
    }

    rep(j, not_comp_score.size()) {
      if (score >= G) {
        chmin(ans, solve);
        break;
      } else {
        score += not_comp_score[j];
        solve++;
      }
    }
    if (score >= G) {
      chmin(ans, solve);
    }
  }
  cout << ans << endl;
}