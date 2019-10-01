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
  int n;
  cin >> n;

  vector<int> v(n);
  rep(i, n) cin >> v[i];

  vector<int> o(1e+5 + 1, 0);
  vector<int> e(1e+5 + 1, 0);

  rep(i, n) {
    if (i % 2 == 0) {
      o[v[i]]++;
    } else {
      e[v[i]]++;
    }
  }

  int omaxnum;
  int omaxcnt = 0;
  int onmaxnum = 0;
  int onmaxcnt = 0;
  rep(i, 1e+5 + 1) {
    if (omaxcnt < o[i]) {
      onmaxnum = omaxnum;
      onmaxcnt = omaxcnt;
      omaxnum = i;
      omaxcnt = o[i];
    } else if (onmaxcnt < o[i]) {
      onmaxnum = i;
      onmaxcnt = o[i];
    }
  }

  int emaxnum;
  int emaxcnt = 0;
  int enmaxnum = 0;
  int enmaxcnt = 0;
  rep(i, 1e+5 + 1) {
    if (emaxcnt < e[i]) {
      enmaxnum = emaxnum;
      enmaxcnt = emaxcnt;
      emaxnum = i;
      emaxcnt = e[i];
    } else if (enmaxcnt < e[i]) {
      enmaxnum = i;
      enmaxcnt = e[i];
    }
  }

  int ans;
  if (omaxnum != emaxnum) {
    ans = n - omaxcnt - emaxcnt;
  } else {
    int cand1 = n - omaxcnt - enmaxcnt;
    int cand2 = n - emaxcnt - onmaxcnt;
    ans = min(cand1, cand2);
  }

  cout << ans << endl;
}