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

int main() {
  ll N, M, L;
  cin >> N >> M >> L;
  vector<ll> A(M), B(M), C(M);
  rep(i, M) {
    cin >> A[i] >> B[i] >> C[i];
    A[i]--;
    B[i]--;
  }
  ll Q;
  cin >> Q;
  vector<ll> s(Q), t(Q);
  rep(i, Q) {
    cin >> s[i] >> t[i];
    s[i]--;
    t[i]--;
  }

  vector<vector<ll>> d(N, vector<ll>(N, LINF));
  rep(i, M) {
    if (L < C[i])
      continue;
    d[A[i]][B[i]] = C[i];
    d[B[i]][A[i]] = C[i];
  }
  rep(i, N) {
    d[i][i] = 0;
  }

  rep(k, N) {
    rep(i, N) {
      rep(j, N) {
        chmin(d[i][j], d[i][k] + d[k][j]);
      }
    }
  }

  vector<vector<ll>> hokyu(N, vector<ll>(N, LINF));
  rep(i, N) {
    rep(j, N) {
      if (i == j)
        hokyu[i][j] = 0;
      else if (d[i][j] <= L)
        hokyu[i][j] = 1;
    }
  }
  rep(k, N) {
    rep(i, N) {
      rep(j, N) {
        chmin(hokyu[i][j], hokyu[i][k] + hokyu[k][j]);
      }
    }
  }

  rep(q, Q) {
    ll temp = hokyu[s[q]][t[q]];
    if (temp == LINF)
      cout << -1 << endl;
    else
      cout << temp - 1 << endl;
  }
}