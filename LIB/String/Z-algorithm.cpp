#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repp(i, a, b) for (int i = a; i <= (b); ++i)

template <class T>
inline bool chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}

vector<int> z_algorithm(const string& s) {
  vector<int> prefix(s.size());
  for (int i = 1, j = 0; i < s.size(); i++) {
    if (i + prefix[i - j] < j + prefix[j]) {
      prefix[i] = prefix[i - j];
    } else {
      int k = max(0, j + prefix[j] - i);
      while (i + k < s.size() && s[k] == s[i + k])
        ++k;
      prefix[i] = k;
      j = i;
    }
  }
  prefix[0] = (int)s.size();
  return prefix;
}

/*
https://atcoder.jp/contests/abc141/tasks/abc141_e
*/

int main() {
  int N;
  cin >> N;
  string S;
  cin >> S;

  int ans = 0;
  rep(i, N) {
    auto p = z_algorithm(S.substr(i, (N - i)));
    repp(j, i + 1, N - 1) {
      chmax(ans, min(j - i, p[j - i]));
    }
  }
  cout << ans << endl;
}