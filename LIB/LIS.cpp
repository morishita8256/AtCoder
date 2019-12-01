#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)


// strict: true -> "<", false -> "<="
template <typename T>
size_t lis(const vector<T>& a, bool strict) {
  vector<T> lis;
  for (auto& p : a) {
    typename vector<T>::iterator it;
    if (strict)
      it = lower_bound(begin(lis), end(lis), p);
    else
      it = upper_bound(begin(lis), end(lis), p);
    if (end(lis) == it)
      lis.emplace_back(p);
    else
      *it = p;
  }
  return lis.size();
}

/*
https://atcoder.jp/contests/abc006/tasks/abc006_4
*/

int main() {
  int N;
  cin >> N;
  vector<int> c(N);
  rep(i, N) {
    cin >> c[i];
    c[i]--;
  }

  int l = lis(c, true);
  cout << N - l << endl;
}