class Solution {
public:
    void segmentedSieve(int l, int r, vector<int>& arr) {
        if (l < 2) l = 2; // No primes < 2
        
        int limit = sqrt(r);
        vector<bool> prime(limit + 1, true);
        for (int p = 2; p * p <= limit; p++) {
            if (prime[p]) {
                for (int i = p * p; i <= limit; i += p) {
                    prime[i] = false;
                }
            }
        }

        // Primes up to √r
        vector<int> basePrimes;
        for (int p = 2; p <= limit; p++) {
            if (prime[p]) basePrimes.push_back(p);
        }

        // Boolean array for range [l, r]
        vector<bool> isPrime(r - l + 1, true);

        for (int p : basePrimes) {
            int start = max(p * p, (l + p - 1) / p * p);
            for (int j = start; j <= r; j += p) {
                isPrime[j - l] = false;
            }
        }

        // Collect all primes in [l, r]
        for (int i = 0; i < isPrime.size(); i++) {
            if (isPrime[i]) {
                arr.push_back(i + l);
            }
        }
    }

    vector<int> closestPrimes(int left, int right) {
        vector<int> arr;
        segmentedSieve(left, right, arr);

        if (arr.size() <= 1)
            return {-1, -1};

        int minDist = INT_MAX, x = 0, y = 0;

        for (int i = 0; i < arr.size() - 1; i++) {
            if (arr[i+1] - arr[i] < minDist) {
                minDist = arr[i+1] - arr[i];
                x = arr[i];
                y = arr[i+1];
            }
        }

        return {x, y};
    }
};
