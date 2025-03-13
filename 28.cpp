#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int i = 0;
        int n = haystack.size();
        int m = needle.size();
        if (m == 0) return -1;

        int j = 0;

        while (i < n) {
            if (haystack[i] == needle[0]) {
                j = 0;
                while (j < m && i+j < n && haystack[i+j] == needle[j]) {
                    j++;
                }
                if (j == m) return i;
            }
            i++;
        }

        return -1;
    }
};

int main()
{
    Solution s;
    cout << s.strStr("hello", "ll") << endl;
    cout << s.strStr("aaaaa", "bba") << endl;

    return 0;
}