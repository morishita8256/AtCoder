#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define int long long
typedef long long ll;
#define double long double
typedef double ld;
const double EPS = 1e-9;

__attribute__((constructor)) void initial() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(15);
}

// 引数は(ok, ng)
#pragma region bin_search
bool f(double);
double bin_search(double ok, double ng) {
  double c;
  int cnt = 100;
  while (abs(ok - ng) > EPS && cnt-- > 0) {
    c = (ok + ng) / 2.0;
    if (f(c)) {
      ok = c;
    } else {
      ng = c;
    }
  }
  return ok;
}
#pragma endregion

/*
https://atcoder.jp/contests/abc034/tasks/abc034_d
*/

int N, K;
vector<double> w;
vector<ll> p;

bool f(double trial) {
  vector<double> over(N);
  rep(i, N) {
    over[i] = w[i] * (p[i] - trial);
  }
  sort(all(over), greater<>());

  double ov = 0.0;
  rep(i, K) {
    ov += over[i];
  }

  return ov >= 0.0;
}

signed main() {
  cin >> N >> K;
  w = vector<double>(N);
  p = vector<ll>(N);

  rep(i, N) {
    cin >> w[i] >> p[i];
  }

  double ans = bin_search(0.0, 100.0);
  cout << ans << endl;
}
