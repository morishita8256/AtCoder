#include <bits/stdc++.h>
using namespace std;

#include <boost/multiprecision/cpp_int.hpp>
typedef boost::multiprecision::cpp_int bint;


/*
https://atcoder.jp/contests/abc059/tasks/abc059_b
*/
int main() {
  bint A, B;
  cin >> A >> B;

  if (A > B)
    cout << "GREATER" << endl;
  else if (A < B)
    cout << "LESS" << endl;
  else
    cout << "EQUAL" << endl;
}