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
#define debug(var) cout << "[" << #var << "]\n" << var << endl
#define int long long
typedef long long ll;
const int INF = 1001001001001001001ll;
const ll LINF = 1001001001001001001ll;
const int MOD = 1000000007;
const double EPS = 1e-9;

template <typename T>
ostream& operator<<(ostream& s, const vector<T>& v) {
  int len = v.size();
  for (int i = 0; i < len; ++i) {
    s << v[i];
    if (i < len - 1)
      s << ' ';
  }
  return s;
}

template <typename T>
ostream& operator<<(ostream& s, const vector<vector<T>>& vv) {
  int len = vv.size();
  for (int i = 0; i < len; ++i) {
    s << vv[i];
    if (i != len - 1)
      s << '\n';
  }
  return s;
}

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

struct B {
  ll V, W;
  B() = default;
  B(ll V, ll W) : V(V), W(W) {
  }

  bool operator<(const B& another) const {
    return W == another.W ? (V < another.V) : (W < another.W);
  };
};


signed main() {
  ll N, W;
  cin >> N >> W;

  bool smallV = true;
  vector<int> v(N), w(N);
  rep(i, N) {
    cin >> v[i] >> w[i];
    if (v[i] > 1000)
      smallV = false;
  }


  if (N <= 30) {
    vector<vector<B>> Bs(2);
    rep(i, N / 2) {
      Bs[0].pb(B(v[i], w[i]));
    }
    repp(i, N / 2, N - 1) {
      Bs[1].pb(B(v[i], w[i]));
    }

    vector<B> L, R;
    rep(_, 2) {
      int n = len(Bs[_]);
      rep(b, bit(n)) {
        int Vsum = 0, Wsum = 0;
        rep(i, n) {
          if (b & bit(i)) {
            Vsum += Bs[_][i].V;
            Wsum += Bs[_][i].W;
          }
        }
        if (Wsum > W)
          continue;
        (_ == 0 ? L : R).pb(B(Vsum, Wsum));
      }
    }

    sort(all(L));
    sort(all(R));

    int LL = len(L), RR = len(R);
    vector<int> RmaxV(RR);

    rep(i, RR) {
      RmaxV[i] = max((i == 0 ? 0ll : RmaxV[i - 1]), R[i].V);
    }

    int ans = 0;
    rep(l, LL) {
      int tempV = L[l].V;
      int tempW = L[l].W;
      auto iter = upper_bound(all(R), B(INF, W - tempW));
      int ind = distance(R.begin(), iter);
      if (ind == 0)
        continue;
      ind--;
      chmax(ans, tempV + RmaxV[ind]);
    }
    cout << ans << endl;

  } else if (smallV) {
    int Vmax = 2e+5;
    vector<vector<int>> dp(N + 1, vector<int>(Vmax + 1, INF));
    dp[0][0] = 0;
    rep(n, N) {
      rep(j, Vmax + 1) {
        if (dp[n][j] == INF)
          continue;
        chmin(dp[n + 1][j], dp[n][j]);
        chmin(dp[n + 1][j + v[n]], dp[n][j] + w[n]);
      }
    }
    int ans = INF;
    rep(j, Vmax + 1) {
      if (dp[N][j] <= W)
        ans = j;
    }
    cout << ans << endl;

  } else {
    int Wmax = 2e+5;
    vector<vector<int>> dp(N + 1, vector<int>(Wmax + 1));
    rep(n, N) {
      rep(j, Wmax + 1) {
        chmax(dp[n + 1][j], dp[n][j]);
        if (j + w[n] <= Wmax)
          chmax(dp[n + 1][j + w[n]], dp[n][j] + v[n]);
      }
    }
    int ans = 0;
    rep(j, min(Wmax, W) + 1) {
      chmax(ans, dp[N][j]);
    }
    cout << ans << endl;
  }
}