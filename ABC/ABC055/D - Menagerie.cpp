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

int N;
string s, t;

bool solve() {
  repp(i, 2, N - 1) {
    if ((t[i - 1] == 'S' && s[i - 1] == 'o') ||
        (t[i - 1] == 'W' && s[i - 1] == 'x')) {
      t[i] = t[i - 2];
    } else {
      if (t[i - 2] == 'S')
        t[i] = 'W';
      else
        t[i] = 'S';
    }
  }

  bool ok = true;
  if ((t[0] == 'S' && s[0] == 'o') || (t[0] == 'W' && s[0] == 'x')) {
    if (t[1] != t[N - 1])
      ok = false;
  } else {
    if (t[1] == t[N - 1])
      ok = false;
  }

  if ((t[N - 1] == 'S' && s[N - 1] == 'o') ||
      (t[N - 1] == 'W' && s[N - 1] == 'x')) {
    if (t[0] != t[N - 2])
      ok = false;
  } else {
    if (t[0] == t[N - 2])
      ok = false;
  }
  return ok;
}

int main() {
  cin >> N;
  cin >> s;

  t = string(N, '.');

  t[0] = 'S';
  t[1] = 'S';
  if (solve()) {
    cout << t << endl;
    return 0;
  }

  t[0] = 'S';
  t[1] = 'W';
  if (solve()) {
    cout << t << endl;
    return 0;
  }

  t[0] = 'W';
  t[1] = 'S';
  if (solve()) {
    cout << t << endl;
    return 0;
  }

  t[0] = 'W';
  t[1] = 'W';
  if (solve()) {
    cout << t << endl;
    return 0;
  }

  cout << -1 << endl;
}