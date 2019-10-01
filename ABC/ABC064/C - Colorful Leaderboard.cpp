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
  vector<int> a(N);
  vector<int> color(9);
  rep(i, N) {
    cin >> a[i];
    color[min(a[i] / 400, 8)]++;
  }

  int Min = 0;
  int Max;
  rep(i, 8) {
    if (color[i] != 0)
      Min++;
  }

  if (Min == 0) {
    Min = 1;
    Max = color[8];
  } else {
    Max = Min + color[8];
  }

  cout << Min << ' ' << Max << endl;
}