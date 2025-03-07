class Solution {
    public:
        vector<int> closestPrimes(int left, int right) {
            // Apply sieve of eratosthenes
            vector<bool> isPrime(right + 1, true);
            for (int i = 2; i * i <= right; ++i) {
                if (isPrime[i] == true) {
                    for (int j = 2; i * j <= right; ++j)
                        isPrime[i * j] = false;
                }
            }
            // Save all the primes in our range
            vector<int> primes;
            for (int i = max(2, left); i <= right; ++i) {
                if (isPrime[i] == true)
                    primes.push_back(i);
            }
            // Now find the 2 closest primes
            int a = 0, b = INT_MAX;
            for (int i = 1; i < primes.size(); ++i) {
                if ((b - a) > (primes[i] - primes[i - 1])) {
                    b = primes[i];
                    a = primes[i - 1];
                }
            }
            // Build your answer
            vector<int> ans;
            if (a == 0)
                ans = {-1, -1};
            else
                ans = {a, b};
            return ans;
        }
    };