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
  int N;
  cin >> N;
  vector<int> t(N + 1);
  repp(i, 1, N) {
    cin >> t[i];
    t[i] *= 2;
    t[i] += t[i - 1];
  }
  vector<int> v(N + 1);
  repp(i, 1, N) {
    cin >> v[i];
    v[i] *= 2;
  }

  int MAX_T = t[N];

  vector<vector<int>> speed(N + 2, vector<int>(MAX_T + 1));
  repp(i, 1, N) {
    int t1 = t[i - 1];
    int t2 = t[i];
    rep(j, MAX_T + 1) {
      speed[i][j] = max({-(j - t1) + v[i], (j - t2) + v[i], v[i]});
    }
  }
  rep(j, MAX_T + 1) {
    speed[0][j] = j;
    speed[N + 1][j] = -(j - MAX_T);
  }

  vector<int> max_speed(MAX_T + 1);
  rep(j, MAX_T + 1) {
    int temp = INF;
    rep(i, N + 2) {
      chmin(temp, speed[i][j]);
    }
    max_speed[j] = temp;
  }

  double ans = 0;
  rep(i, MAX_T) {
    int a = max_speed[i];
    int b = max_speed[i + 1];
    ans += ((double)(a + b)) / 2.0;
  }
  ans /= 4.0;
  printf("%.10f\n", ans);
}