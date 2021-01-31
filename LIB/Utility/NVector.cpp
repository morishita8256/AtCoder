#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define len(x) ((ll)(x).size())
#define debug(var) cout << "[" << #var << "]\n" << var << endl

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

// Negative-Indexed-Vector
///////////////////////////////////////////////////////////
template <typename T>
struct nvector {
  int edge, tot;
  vector<T> vec;
  nvector(int edge) : edge(edge), tot(edge * 2 + 1), vec(tot) {
  }
  nvector(int edge, T init) : edge(edge), tot(edge * 2 + 1), vec(tot, init) {
  }
  T& operator[](int pos) {
    return vec[pos + edge];
  }
};

template <typename T>
ostream& operator<<(ostream& s, const nvector<T>& nvector) {
  s << nvector.vec;
  return s;
}
///////////////////////////////////////////////////////////


signed main() {
  nvector<int> hoge(3);
  hoge[-3] = 1;
  cout << hoge << endl;
}