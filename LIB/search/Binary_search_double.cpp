#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define rep(i, n) for (int i = 0; i < (n); ++i)
typedef long long ll;


#define double long double
double EPS = 1.0e-14;
double find_max(double l, double r, bool f(double)) {
  double c;
  while (abs(r - l) > EPS) {
    c = (r + l) / 2.0;
    if (f(c)) {
      l = c;
    } else {
      r = c;
    }
  }

  return l;
}

double find_min(double l, double r, bool f(double)) {
  double c;
  while (abs(r - l) > EPS) {
    c = (r + l) / 2.0;
    if (f(c)) {
      r = c;
    } else {
      l = c;
    }
  }

  return r;
}

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

int main() {
  cin >> N >> K;
  w = vector<double>(N);
  p = vector<ll>(N);

  rep(i, N) {
    cin >> w[i] >> p[i];
  }

  double ans = find_max(0.0, 100.0, f);
  printf("%.14Lf\n", ans);  // Lf?
}
