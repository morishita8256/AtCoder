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
  string S;
  cin >> S;
  string T;
  cin >> T;

  int s = S.size();
  int t = T.size();

  bool ok = false;
  repr (i, s - t, 0) {
    string S_sub = S.substr(i, t);
    bool accord = true;
    rep (j, t) {
      if (S_sub[j] == '?')
        continue;
      if (S_sub[j] != T[j])
        accord = false;
    }
    if (accord) {
      S.replace(i, t, T);
      ok = true;
      break;
    }
  }

  if (!ok) {
    cout << "UNRESTORABLE" << endl;
    return 0;
  }

  rep (i, s) {
    if (S[i] == '?')
      S[i] = 'a';
  }

  cout << S << endl;
}