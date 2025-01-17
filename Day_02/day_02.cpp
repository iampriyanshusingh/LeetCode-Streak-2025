class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.length();
        vector<int> arr(n, 0);
        for (const auto& shift : shifts) {
            if (shift[2] == 1) { 
                arr[shift[0]]++;
                if (shift[1] + 1 < n) {
                    arr[shift[1] + 1]--;
                }
            } else { 
                arr[shift[0]]--;
                if (shift[1] + 1 < n) {
                    arr[shift[1] + 1]++;
                }
            }
        }

        string result = s;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum = (sum + arr[i]) % 26;
            if (sum < 0) sum += 26;
            char shiftedChar = 'a' + ((s[i] - 'a' + sum) % 26);
            result[i] = shiftedChar;
        }
        return result;
    }
};
