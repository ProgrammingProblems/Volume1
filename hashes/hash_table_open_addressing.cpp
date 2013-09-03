int fib(int n) {
  vector<int> memo(n);
  for (int index = 0; index <= n; ++index) {
  	if (0 == index) memo[index] = 0;
    else if (1 == index) memo[index] = 1;
  	else memo[index] = memo[index-1] + memo[index-2];
  }
  return memo[n];
}