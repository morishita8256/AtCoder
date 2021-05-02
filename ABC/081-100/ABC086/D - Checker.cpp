#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repp(i, a, b) for (int i = a; i <= (b); ++i)
#define repr(i, a, b) for (int i = a; i >= (b); --i)
#define bit(n) (1LL << (n))
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

int main() {
  ll N, K;
  cin >> N >> K;
  vector<ll> x(N), y(N);
  vector<char> c(N);
  map<char, char> m;
  m['B'] = 'W';
  m['W'] = 'B';
  vector<vector<ll>> W(K, vector<ll>(K));
  vector<vector<ll>> B(K, vector<ll>(K));
  rep(i, N) {
    cin >> x[i] >> y[i] >> c[i];
    if ((x[i] / K) & 1)
      c[i] = m[c[i]];
    if ((y[i] / K) & 1)
      c[i] = m[c[i]];
    x[i] %= K;
    y[i] %= K;
    if (c[i] == 'W') {
      W[x[i]][y[i]]++;
    } else if (c[i] == 'B') {
      B[x[i]][y[i]]++;
    }
  }

  vector<vector<ll>> Wsum(K + 1, vector<ll>(K + 1));
  vector<vector<ll>> Bsum(K + 1, vector<ll>(K + 1));
  repp(i, 1, K) {
    repp(j, 1, K) {
      Wsum[i][j] = W[i - 1][j - 1] + Wsum[i - 1][j] + Wsum[i][j - 1] -
                   Wsum[i - 1][j - 1];
      Bsum[i][j] = B[i - 1][j - 1] + Bsum[i - 1][j] + Bsum[i][j - 1] -
                   Bsum[i - 1][j - 1];
    }
  }

  ll ans = 0;
  repp(i, 0, K) {
    repp(j, 0, K) {
      ll temp = 0;
      temp += Wsum[K][K] - Wsum[i][K] - Wsum[K][j] + 2 * Wsum[i][j];
      temp += Bsum[i][K] + Bsum[K][j] - 2 * Bsum[i][j];
      chmax(ans, max(N - temp, temp));
    }
  }
  cout << ans << endl;
}