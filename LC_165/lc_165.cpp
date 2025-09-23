// Brute force: split using stringstream and stoi
class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<int> v1, v2;
        string part;
        stringstream ss1(version1), ss2(version2);
        while (getline(ss1, part, '.')) v1.push_back(stoi(part));
        while (getline(ss2, part, '.')) v2.push_back(stoi(part));

        int n = max(v1.size(), v2.size());
        for (int i = 0; i < n; ++i) {
            int a = (i < (int)v1.size()) ? v1[i] : 0;
            int b = (i < (int)v2.size()) ? v2[i] : 0;
            if (a < b) return -1;
            if (a > b) return 1;
        }
        return 0;
    }
};

// Two pointers + substr + stoi
class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i1 = 0, i2 = 0;
        int n1 = version1.size(), n2 = version2.size();

        while (i1 < n1 || i2 < n2) {
            int j1 = i1;
            while (j1 < n1 && version1[j1] != '.') ++j1;
            int j2 = i2;
            while (j2 < n2 && version2[j2] != '.') ++j2;

            int num1 = 0, num2 = 0;
            if (i1 < n1) num1 = stoi(version1.substr(i1, j1 - i1));
            if (i2 < n2) num2 = stoi(version2.substr(i2, j2 - i2));

            if (num1 < num2) return -1;
            if (num1 > num2) return 1;

            i1 = j1 + 1;
            i2 = j2 + 1;
        }
        return 0;
    }
};

// Optimal: two pointers + on-the-fly parse
class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i1 = 0, i2 = 0;
        int n1 = version1.length(), n2 = version2.length();
        while (i1 < n1 || i2 < n2) {
            int v1 = 0, v2 = 0;
            while (i1 < n1 && version1[i1] != '.') v1 = v1 * 10 + (version1[i1++] - '0');
            while (i2 < n2 && version2[i2] != '.') v2 = v2 * 10 + (version2[i2++] - '0');
            if (v1 < v2) return -1;
            if (v1 > v2) return 1;
            i1++; i2++; // skip '.' if present
        }
        return 0;
    }
};