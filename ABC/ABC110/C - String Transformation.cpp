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
  string S;
  cin >> S;
  string T;
  cin >> T;

  int N = S.size();

  vector<vector<int>> S_alph(26);
  vector<vector<int>> T_alph(26);

  rep(i, N) {
    S_alph[S[i] - 'a'].pb(i);
    T_alph[T[i] - 'a'].pb(i);
  }

  vector<bool> S_watched(26, false);
  rep(i, N) {
    if (S_watched[S[i] - 'a'] == true) {
      continue;
    }

    S_watched[S[i] - 'a'] = true;
    bool accord = true;
    if (S_alph[S[i] - 'a'].size() != T_alph[T[i] - 'a'].size()) {
      accord = false;
    } else {
      rep(j, S_alph[S[i] - 'a'].size()) {
        if (S_alph[S[i] - 'a'][j] != T_alph[T[i] - 'a'][j]) {
          accord = false;
        }
      }
    }
    if (accord == false) {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
}