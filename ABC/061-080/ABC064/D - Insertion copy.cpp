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

  stack<int> L, R;
  int l = 0, r = 0;
  rep(i, N) {
    if (S[i] == '(') {
      L.push(i);
    } else {
      if (L.empty())
        r++;
      else {
        L.pop();
      }
    }
  }
  l = sz(L);

  reverse(all(S));
  rep(i, r) {
    S.pb('(');
  }

  reverse(all(S));
  rep(i, l) {
    S.pb(')');
  }

  cout << S << endl;
}