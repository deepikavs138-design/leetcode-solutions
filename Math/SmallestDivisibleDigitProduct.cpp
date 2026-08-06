#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int smallestNumber(int n, int t) {
        auto digitProduct = [&](int x) {
            int prod = 1;
            while (x > 0) {
                prod *= (x % 10);
                x /= 10;
            }
            return prod;
        };

        int ans = n;
        while (true) {
            if (digitProduct(ans) % t == 0) return ans;
            ans++;
        }
    }
};
