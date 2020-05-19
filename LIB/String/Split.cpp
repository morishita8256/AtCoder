#include <bits/stdc++.h>
using namespace std;

#include <boost/algorithm/string/classification.hpp>
#include <boost/algorithm/string/split.hpp>
using boost::algorithm::is_any_of;
using boost::algorithm::split;


/*
https://atcoder.jp/contests/abc033/tasks/abc033_c
*/

int main() {
  string S;
  cin >> S;
  vector<string> sp;
  split(sp, S, is_any_of("+"));
  int ans = 0;
  for (auto s : sp) {
    if (s.find('0') == string::npos)
      ans++;
  }
  cout << ans << endl;
}