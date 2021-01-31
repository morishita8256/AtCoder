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

/* 嘘っぽい */
int main() {
  int H, W;
  cin >> H >> W;
  vector<vector<char>> A(H, vector<char>(W));
  rep(i, H) {
    rep(j, W) {
      cin >> A[i][j];
    }
  }

  vector<vector<int>> dist(H, vector<int>(W, INF));

  rep(iter, 2) {
    rep(i, H) {
      rep(j, W) {
        if (A[i][j] == '#')
          dist[i][j] = 0;
      }
    }

    rep(i, H) {
      repp(j, 1, W - 1) {
        chmin(dist[i][j], dist[i][j - 1] + 1);
      }
    }

    rep(i, H) {
      repr(j, W - 2, 0) {
        chmin(dist[i][j], dist[i][j + 1] + 1);
      }
    }

    repp(i, 1, H - 1) {
      rep(j, W) {
        chmin(dist[i][j], dist[i - 1][j] + 1);
      }
    }

    repr(i, H - 2, 0) {
      rep(j, W) {
        chmin(dist[i][j], dist[i + 1][j] + 1);
      }
    }
  }
  int ans = 0;
  rep(i, H) {
    rep(j, W) {
      chmax(ans, dist[i][j]);
    }
  }
  cout << ans << endl;
}