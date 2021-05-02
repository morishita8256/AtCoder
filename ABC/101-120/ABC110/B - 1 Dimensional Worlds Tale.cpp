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
  int N, M;
  cin >> N >> M;
  int X, Y;
  cin >> X >> Y;

  vector<int> x(N);
  rep(i, N) cin >> x[i];
  vector<int> y(M);
  rep(i, M) cin >> y[i];

  sort(all(x));
  sort(all(y));

  if (x[N - 1] < y[0] && X < y[0] && x[N - 1] < Y) {
    cout << "No War" << endl;
  } else {
    cout << "War" << endl;
  }
}