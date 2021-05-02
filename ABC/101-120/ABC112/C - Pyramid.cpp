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
  int N;
  cin >> N;

  vector<int> x(N), y(N), h(N);
  int xx, yy, hh;

  rep(i, N) {
    cin >> x[i] >> y[i] >> h[i];
    if (h[i] > 0) {
      xx = x[i];
      yy = y[i];
      hh = h[i];
    }
  }

  repp(cx, 0, 100) {
    repp(cy, 0, 100) {
      int h_cand = hh + abs(cx - xx) + abs(cy - yy);
      int correct = true;
      rep(i, N) {
        int h_inf = max(h_cand - abs(cx - x[i]) - abs(cy - y[i]), 0);
        if (h_inf != h[i]) {
          correct = false;
          break;
        }
      }
      if (correct) {
        cout << cx << ' ' << cy << ' ' << h_cand << endl;
        return 0;
      }
    }
  }
}