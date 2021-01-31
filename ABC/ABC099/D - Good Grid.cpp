#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repp(i, x, y) for (int i = x; i <= (y); ++i)
#define repr(i, x, y) for (int i = x; i >= (y); --i)
#define bit(n) (1LL << (n))
typedef long long ll;
const int INF = 1001001001;
const ll LINF = 1001001001001001001ll;
const int MOD = 1000000007;

template <class T>
inline bool chmin(T& x, T y) {
  if (x > y) {
    x = y;
    return true;
  }
  return false;
}

template <class T>
inline bool chmax(T& x, T y) {
  if (x < y) {
    x = y;
    return true;
  }
  return false;
}

int main() {
  int N, C;
  cin >> N >> C;
  vector<vector<int>> D(C, vector<int>(C));
  rep(i, C) {
    rep(j, C) {
      cin >> D[i][j];
    }
  }
  int c;
  map<int, int> x, y, z;
  rep(i, N) {
    rep(j, N) {
      cin >> c;
      c--;
      switch ((i + j) % 3) {
        case 0:
          x[c]++;
          break;
        case 1:
          y[c]++;
          break;
        case 2:
          z[c]++;
          break;
      }
    }
  }

  int ans = INF;
  rep(xx, C) {
    rep(yy, C) {
      rep(zz, C) {
        if (xx == yy || yy == zz || zz == xx)
          continue;

        int temp = 0;
        for (auto iter = x.begin(); iter != x.end(); iter++) {
          int old_color = iter->fi;
          int num = iter->se;
          temp += D[old_color][xx] * num;
        }
        for (auto iter = y.begin(); iter != y.end(); iter++) {
          int old_color = iter->fi;
          int num = iter->se;
          temp += D[old_color][yy] * num;
        }
        for (auto iter = z.begin(); iter != z.end(); iter++) {
          int old_color = iter->fi;
          int num = iter->se;
          temp += D[old_color][zz] * num;
        }
        chmin(ans, temp);
      }
    }
  }
  cout << ans << endl;
}