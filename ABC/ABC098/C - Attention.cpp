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
  string S;
  cin >> S;

  vector<int> to_r(N);
  to_r[0] = 0;
  repp(i, 1, N - 1) { to_r[i] = to_r[i - 1] + (S[i - 1] == 'W'); }

  vector<int> to_l(N);
  to_l[N - 1] = 0;
  repr(i, N - 2, 0) { to_l[i] = to_l[i + 1] + (S[i + 1] == 'E'); }

  vector<int> turn(N);
  rep(i, N) { turn[i] = to_r[i] + to_l[i]; }
  sort(all(turn));
  cout << turn[0] << endl;
}