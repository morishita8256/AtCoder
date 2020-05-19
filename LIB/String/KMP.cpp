#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) ((ll)(x).size())
typedef long long ll;


/*
テキストTの中のパターンSの開始位置を求める。
前処理O(S)。検索O(T)。
*/
struct KMP {
  string pattern;
  int plen;
  vector<int> table;

  KMP(const string& s)
      : pattern(s), plen((int)pattern.size()), table(plen + 1) {
    table[0] = -1;
    int j = -1;
    for (int i = 0; i < plen; ++i) {
      while (j >= 0 && pattern[i] != pattern[j]) {
        j = table[j];
      }
      table[i + 1] = ++j;
    }
  }

  void search(const string& text, vector<int>& res) {
    int head = 0, j = 0, tlen = (int)text.size();
    while (head + j < tlen) {
      if (pattern[j] == text[head + j]) {
        if (++j == plen) {
          res.push_back(head);
          head = head + j - table[j];
          j = table[j];
        }
      } else {
        head = head + j - table[j];
        if (j)
          j = table[j];
      }
    }
  }
};

// 文字列 s[0, i] の最小周期の長さ
void minimum_cycle(const string& s, vector<int>& res) {
  KMP kmp(s);
  res.resize((int)s.size());
  for (int i = 0; i < (int)s.size(); ++i) {
    res[i] = i + 1 - kmp.table[i + 1];
  }
}

/*
http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B&lang=ja
*/

int main() {
  string T;
  cin >> T;
  string P;
  cin >> P;
  KMP kmp(P);  // 検索文字列
  vector<int> ans;
  kmp.search(T, ans);
  rep(i, sz(ans)) {
    cout << ans[i] << endl;
  }
}