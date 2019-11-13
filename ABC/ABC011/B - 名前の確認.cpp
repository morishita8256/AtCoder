#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fi first
#define se second
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repp(i, a, b) for (int i = a; i <= (b); ++i)
#define repr(i, a, b) for (int i = a; i >= (b); --i)
#define bit(n) (1LL << (n))
#define sz(x) ((ll)(x).size())
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

char to_lower(char c) {
  if ('A' <= c && c <= 'Z') {
    c = c - 'A' + 'a';
  }
  return c;
}

char to_upper(char c) {
  if ('a' <= c && c <= 'z') {
    c = c - 'a' + 'A';
  }
  return c;
}
int main() {
  string S;
  cin >> S;

  rep(i, sz(S)) {
    if (i == 0)
      S[i] = to_upper(S[i]);
    else
      S[i] = to_lower(S[i]);
  }
  cout << S << endl;
}