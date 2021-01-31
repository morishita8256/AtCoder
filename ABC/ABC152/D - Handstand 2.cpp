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
#define len(x) ((ll)(x).size())
typedef long long ll;
const int INF = 1001001001;
const ll LINF = 1001001001001001001ll;
const int MOD = 1000000007;
const double EPS = 1e-9;

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

__attribute__((constructor)) void initial() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(15);
}


signed main() {
  int N;
  cin >> N;

  vector<vector<ll>> table(10, vector<ll>(10));

  repp(i, 1, N) {
    string n = to_string(i);
    int head = n[0] - '0';
    int tail = n[len(n) - 1] - '0';
    table[head][tail]++;
  }

  ll ans = 0;
  repp(i, 1, 9) {
    repp(j, 1, 9) {
      ans += table[i][j] * table[j][i];
    }
  }
  cout << ans << "\n";
}