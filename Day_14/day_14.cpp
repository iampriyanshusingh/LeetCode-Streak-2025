class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> freq(n + 1, 0); // Frequency array
        vector<int> C(n, 0); // Resultant array
        int count = 0;

        for (int i = 0; i < n; i++) {
            freq[A[i]]++;
            if (freq[A[i]] == 2) count++; // If an element appears in both arrays

            freq[B[i]]++;
            if (freq[B[i]] == 2) count++; // If an element appears in both arrays

            C[i] = count; // Store the count at the ith position
        }

        return C;
    }
};