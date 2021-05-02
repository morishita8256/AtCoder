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
#define sz(x) ((ll)(x).size())
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
  int N;
  cin >> N;
  vector<vector<int>> D(N, vector<int>(N));
  rep(i, N) {
    rep(j, N) {
      cin >> D[i][j];
    }
  }
  int Q;
  cin >> Q;
  vector<int> P(Q);
  rep(i, Q) {
    cin >> P[i];
  }

  vector<vector<int>> sum(N, vector<int>(N));
  rep(i, N) {
    rep(j, N) {
      sum[i][j] = D[i][j];
      if (i > 0)
        sum[i][j] += sum[i - 1][j];
      if (j > 0)
        sum[i][j] += sum[i][j - 1];
      if (i > 0 && j > 0)
        sum[i][j] -= sum[i - 1][j - 1];
    }
  }

  vector<int> Pmax(N * N + 1);
  repp(iu, 0, N - 1) {
    repp(id, iu, N - 1) {
      repp(ju, 0, N - 1) {
        repp(jd, ju, N - 1) {
          int h = id - iu + 1, w = jd - ju + 1;
          int num = h * w;
          int d = sum[id][jd];
          if (iu > 0)
            d -= sum[iu - 1][jd];
          if (ju > 0)
            d -= sum[id][ju - 1];
          if (iu > 0 && ju > 0)
            d += sum[iu - 1][ju - 1];
          chmax(Pmax[num], d);
        }
      }
    }
  }

  vector<int> Pmaxmax(N * N + 1);
  repp(i, 1, N * N) {
    Pmaxmax[i] = max(Pmaxmax[i - 1], Pmax[i]);
  }

  rep(q, Q) {
    cout << Pmaxmax[P[q]] << endl;
  }
}