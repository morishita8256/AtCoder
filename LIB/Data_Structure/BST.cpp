#include <bits/stdc++.h>
using namespace std;

/*
  平衡二分探索木
  setの上位互換みたいなもので、k番目に小さい値や、ある値以上の最初のindexを取得できる。
  大きい値の場合"less"を"greater"に変える

    #define int long long
    #define double long double
  を消さないとエラーを吐く。

  BST<type> bst;
  bst.insert(val)
  bst.erase(val)
  bst.find_by_order(k) -> k番目(0-ind)のイテレータ
  bst.order_of_key(val) -> val以上最初の要素のindex
*/

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tag_and_trait.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template <typename T>
using BST =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

/*
https://atcoder.jp/contests/arc033/tasks/arc033_3
*/

signed main() {
  int Q;
  cin >> Q;

  BST<int> bst;
  while (Q-- > 0) {
    int T, X;
    cin >> T >> X;
    if (T == 1) {  // add
      bst.insert(X);
    } else if (T == 2) {  // query
      X--;
      auto iter = bst.find_by_order(X);
      int ans = *iter;
      cout << ans << endl;
      bst.erase(ans);
    }
  }
}