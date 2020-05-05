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
ostream& operator<<(ostream& s, const vector<T>& v) {
  int len = v.size();
  for (int i = 0; i < len; ++i) {
    s << v[i];
    if (i < len - 1)
      s << ' ';
  }
  return s;
}

template <typename T>
ostream& operator<<(ostream& s, const vector<vector<T>>& vv) {
  int len = vv.size();
  for (int i = 0; i < len; ++i) {
    s << vv[i];
    if (i != len - 1)
      s << '\n';
  }
  return s;
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

bool isCamel(char c) {
  return 'A' <= c && c <= 'Z';
}

void toLower(string& S) {
  S[0] = S[0] - 'A' + 'a';
  S[len(S) - 1] = S[len(S) - 1] - 'A' + 'a';
}

void toUpper(string& S) {
  S[0] = S[0] - 'a' + 'A';
  S[len(S) - 1] = S[len(S) - 1] - 'a' + 'A';
}


signed main() {
  string S;
  cin >> S;

  vector<string> words;

  int i = 0;
  int j;

  while (i < len(S)) {
    j = i + 1;
    while (!isCamel(S[j]))
      j++;
    words.pb(S.substr(i, j - i + 1));
    i = j + 1;
  }

  int M = len(words);
  rep(i, M) {
    toLower(words[i]);
  }

  sort(all(words));

  rep(i, M) {
    toUpper(words[i]);
    cout << words[i];
  }
  cout << '\n';
}