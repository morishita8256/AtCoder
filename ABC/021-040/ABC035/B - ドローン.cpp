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
  string S;
  cin >> S;
  int T;
  cin >> T;

  int x = 0;
  int y = 0;
  int hatena = 0;
  rep(i, sz(S)) {
    if (S[i] == 'L')
      x--;
    else if (S[i] == 'R')
      x++;
    else if (S[i] == 'U')
      y++;
    else if (S[i] == 'D')
      y--;
    else
      hatena++;
  }

  int dist = abs(x) + abs(y);

  if (T == 1) {
    cout << dist + hatena << endl;
  } else {
    if (hatena <= dist)
      cout << dist - hatena << endl;
    else {
      cout << abs(dist - hatena) % 2 << endl;
    }
  }
}