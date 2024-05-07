#include <iostream>
#include <vector>

enum class KeyWord: int {
  kAsm,
  kAuto,
  kbreak
};

enum A {
  F,
  C
};

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  long long n, k;
  std::cin >> n >> k;

  std::vector<long long> prices ;

  for (long long i = 0; i < n; ++i) {
    long long tmp;
    std::cin >> tmp;
    prices.push_back(tmp);
  }

  std::vector<long long> res{ prices[0] };
  std::vector<long long> cnt(n, 0);
  ++cnt[0];

  long long mn = prices[0];
  long long idx = 0;
  long long last_mn = 10000000;
  long long idx_ = 0;

  
  for (long long i = 1; i < n; ++i) {
    if (k == 1) {
      cnt[i] = 1;
      res.push_back(res[i - 1] + prices[i]);
      continue;
    }
    if (i - idx + 1 <= k) {
      if (prices[i] <= mn) {
        mn = prices[i];
        idx = i;
        last_mn = 10000000;

      } else if (prices[i] <= last_mn) {
        last_mn = prices[i];  
        idx_ = i;
      }
    }
    else {
      if (prices[i] <= last_mn) {
        mn = prices[i];
        idx = i;
        last_mn = 10000000;
      }
      else {
        mn = last_mn;
        idx = idx_;
        last_mn = 10000000;
        for (long long j = idx_ + 1; j <= i; ++j) {
          if (prices[j] <= last_mn) {
            last_mn = prices[j];
            idx_ = j;
          } 
        }
      }

    }
    res.push_back(res[i - 1] + mn);
    ++cnt[idx];
  }
  std::cout << res[res.size() - 1] << '\n';
  for (long long i = 0; i < cnt.size(); ++i) {
    std::cout << cnt[i] << ' ';
  }
}