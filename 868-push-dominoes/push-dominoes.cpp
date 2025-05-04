class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.size();
        string result = dominoes;
        int i = 0;
        int lastR = -1; // Position of last seen 'R'

        while (i < n) {
            if (dominoes[i] == 'L') {
                if (lastR == -1) {
                    // Fill all previous '.'s with 'L'
                    int j = i - 1;
                    while (j >= 0 && result[j] == '.') {
                        result[j--] = 'L';
                    }
                } else {
                    // Handle 'R...L'
                    int left = lastR + 1;
                    int right = i - 1;
                    while (left < right) {
                        result[left++] = 'R';
                        result[right--] = 'L';
                    }
                    lastR = -1; // Reset
                }
            } else if (dominoes[i] == 'R') {
                if (lastR != -1) {
                    // Fill 'R...R'
                    for (int j = lastR + 1; j < i; ++j) {
                        result[j] = 'R';
                    }
                }
                lastR = i;
            }
            i++;
        }

        // Handle trailing 'R...'
        if (lastR != -1) {
            for (int j = lastR + 1; j < n; ++j) {
                result[j] = 'R';
            }
        }

        return result;
    }
};
