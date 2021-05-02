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
#define sz(x) ((int)(x).size())
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
  string S;
  cin >> S;

  string T = S;
  rep(i, N) {
    rep(j, sz(T) - 1) {
      if (T[j] == '(' && T[j + 1] == ')') {
        T.erase(T.begin() + j, T.begin() + j + 2);
        continue;
      }
    }
  }

  int cnt_l = 0, cnt_r = 0;
  rep(i, sz(T)) {
    if (T[i] == ')')
      cnt_r++;
    else
      cnt_l++;
  }

  reverse(all(S));
  rep(i, cnt_r) {
    S.pb('(');
  }

  reverse(all(S));
  rep(i, cnt_l) {
    S.pb(')');
  }

  cout << S << endl;
}