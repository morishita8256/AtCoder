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
#define len(x) ((ll)(x).size())
#define debug(var) cout << "[" << #var << "]\n" << var << endl
#define int long long
typedef long long ll;
const int INF = 1001001001001001001ll;
const ll LINF = 1001001001001001001ll;
const int MOD = 1000000007;
const double EPS = 1e-9;

template <typename T>
ostream& operator<<(ostream& words, const vector<T>& v) {
  int len = v.size();
  for (int i = 0; i < len; ++i) {
    words << v[i];
    if (i < len - 1)
      words << ' ';
  }
  return words;
}

template <typename T>
ostream& operator<<(ostream& words, const vector<vector<T>>& vv) {
  int len = vv.size();
  for (int i = 0; i < len; ++i) {
    words << vv[i];
    if (i != len - 1)
      words << '\n';
  }
  return words;
}

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

__attribute__((constructor)) void initial() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(15);
}

signed main() {
  string S;
  getline(cin, S);

  S.pb(' ');

  vector<string> words;
  int i = 0, j = 0;
  while (i < len(S)) {
    while (S[j] != ' ')
      j++;
    words.pb(S.substr(i, j - i));
    i = j + 1;
    j = i;
  }

  rep(n, len(words)) {
    if (words[n] == "Left")
      cout << '<';
    else if (words[n] == "Right")
      cout << '>';
    else
      cout << "A";

    cout << (n == len(words) - 1 ? '\n' : ' ');
  }
}