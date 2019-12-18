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

int main() {
  int N;
  cin >> N;
  vector<string> w(N);
  rep(i, N) {
    cin >> w[i];
  }

  map<char, char> m;
  m['b'] = '1', m['c'] = '1', m['d'] = '2', m['w'] = '2';
  m['t'] = '3', m['j'] = '3', m['f'] = '4', m['q'] = '4';
  m['l'] = '5', m['v'] = '5', m['s'] = '6', m['x'] = '6';
  m['p'] = '7', m['m'] = '7', m['h'] = '8', m['k'] = '8';
  m['n'] = '9', m['g'] = '9', m['z'] = '0', m['r'] = '0';

  m['b' - 'a' + 'A'] = '1', m['c' - 'a' + 'A'] = '1', m['d' - 'a' + 'A'] = '2',
                m['w' - 'a' + 'A'] = '2';
  m['t' - 'a' + 'A'] = '3', m['j' - 'a' + 'A'] = '3', m['f' - 'a' + 'A'] = '4',
                m['q' - 'a' + 'A'] = '4';
  m['l' - 'a' + 'A'] = '5', m['v' - 'a' + 'A'] = '5', m['s' - 'a' + 'A'] = '6',
                m['x' - 'a' + 'A'] = '6';
  m['p' - 'a' + 'A'] = '7', m['m' - 'a' + 'A'] = '7', m['h' - 'a' + 'A'] = '8',
                m['k' - 'a' + 'A'] = '8';
  m['n' - 'a' + 'A'] = '9', m['g' - 'a' + 'A'] = '9', m['z' - 'a' + 'A'] = '0',
                m['r' - 'a' + 'A'] = '0';

  vector<string> list(N);
  rep(i, N) {
    rep(j, sz(w[i])) {
      if (m.find(w[i][j]) != m.end())
        list[i].pb(m[w[i][j]]);
    }
  }

  vector<string> ans;
  rep(i, sz(list)) {
    if (list[i] == "")
      continue;
    ans.pb(list[i]);
  }

  rep(i, sz(ans)) {
    cout << ans[i] << ((i == sz(ans) - 1) ? "\n" : " ");
  }

  if (sz(ans) == 0)
    cout << endl;
}