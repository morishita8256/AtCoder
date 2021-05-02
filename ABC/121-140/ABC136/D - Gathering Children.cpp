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
  string S;
  cin >> S;

  int N = S.size();

  vector<int> b;
  b.pb(0);
  repp(i, 1, N - 1) {
    if (S[i - 1] == 'R' && S[i] == 'L') b.pb(i);
    if (S[i - 1] == 'L' && S[i] == 'R') b.pb(i);
  }
  b.pb(N);

  int M = b.size();

  int pt = 0;
  for (int i = 1; i < M; i += 2) {
    while (pt < b[i] - 1) {
      cout << 0 << ' ';
      pt++;
    }
    int l = (b[i] - b[i - 1] + 1) / 2 + (b[i + 1] - b[i]) / 2;
    cout << l << ' ';
    pt++;

    int r = (b[i] - b[i - 1]) / 2 + (b[i + 1] - b[i] + 1) / 2;
    cout << r << ' ';
    pt++;
  }
  while (pt < N) {
    cout << 0 << ' ';
    pt++;
  }
  cout << endl;
}