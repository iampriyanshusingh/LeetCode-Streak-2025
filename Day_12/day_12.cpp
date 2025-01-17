class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = s.length();
        if (n % 2 != 0) return false;
        stack<int> openBrackets; 
        // Renamed from 'stack' to 'openBrackets'
        stack<int> unlocked;
        for (int i = 0; i < n; i++) {
            char ch = s[i];
            char state = locked[i];
            if (state == '0') {
                unlocked.push(i);
            } else if (ch == '(') {
                openBrackets.push(i);
            } else {
                if (!openBrackets.empty()) {
                    openBrackets.pop();
                } else {
                    if (!unlocked.empty()) {
                        unlocked.pop();
                    } else {
                        return false;
                    }
                }
            }
        }
        while (!openBrackets.empty() && !unlocked.empty() && openBrackets.top() < unlocked.top()) {
            openBrackets.pop();
            unlocked.pop();
        }
        return openBrackets.empty();
    }
};
