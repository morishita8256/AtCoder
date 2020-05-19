#include <bits/stdc++.h>
using namespace std;

#include <boost/algorithm/string/replace.hpp>
using boost::algorithm::replace_all;


int main() {
  string S;
  getline(cin, S);
  replace_all(S, "Left", "<");
  replace_all(S, "Right", ">");
  replace_all(S, "AtCoder", "A");
  cout << S << endl;
}