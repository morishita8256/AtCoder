#include <bits/stdc++.h>
using namespace std;

#include <boost/algorithm/string/join.hpp>
using boost::algorithm::join;

#define all(x) (x).begin(), (x).end()
#define rep(i, n) for (int i = 0; i < (n); ++i)


int main() {
  int N, L;
  cin >> N >> L;
  vector<string> S(N);
  rep(i, N) {
    cin >> S[i];
  }
  sort(all(S));
  string ans = join(S, "");
  cout << ans << endl;
}