
  int len = S.size();
  ll ans = 0;
  for (int i = 0; i < len; i++)
  {
    ans += (S[i] - '0') * keisuu(len - i);
  }
  cout << ans << endl;