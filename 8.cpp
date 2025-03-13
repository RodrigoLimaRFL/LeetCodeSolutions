#include <iostream>
#include <unordered_map>
#include <cmath>

using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int size = s.size();
        int start;

        short int sign = 1;

        for(start = 0; start < size; start++)
        {
            if(s[start] == ' ')
            {
                continue;
            }
            else if(s[start] == '-')
            {
                sign = -1;
                start++;
            }
            else if(s[start] == '+')
            {
                start++;
            }
            else if(s[start] < '0' || s[start] > '9')
            {
                return 0;
            }

            break;
        }

        if(start == size)
        {
            return 0;
        }

        for( ; start < size; start++)
        {
            if(s[start] == '0')
            {
                continue;
            }
            if(s[start] < '0' || s[start] > '9')
            {
                return 0;
            }
            break;
        }

        if(start == size)
        {
            return 0;
        }

        for(int i = start ; i < size; i++)
        {
            if(s[i] < '0' || s[i] > '9')
            {
                size = i;
                break;
            }
        }

        if(start == size)
        {
            return 0;
        }

        int numSize = size - start;
        const int maxInt = 2147483647;
        const int minInt = -2147483648;

        if(numSize > 10)
        {
            if(sign == 1)
            {
                return maxInt;
            }
            return minInt;
        }

        long int result = 0;
        unordered_map<char, int> charToNum;
        charToNum['0'] = 0;
        charToNum['1'] = 1;
        charToNum['2'] = 2;
        charToNum['3'] = 3;
        charToNum['4'] = 4;
        charToNum['5'] = 5;
        charToNum['6'] = 6;
        charToNum['7'] = 7;
        charToNum['8'] = 8;
        charToNum['9'] = 9;

        long int multiplier = 1;

        for(int i = start + numSize - 1; i >= start; i--)
        {
            result += charToNum[s[i]] * multiplier;
            multiplier *= 10;
        }

        result *= sign;

        if(numSize == 10)
        {
            if(result > maxInt)
            {
                return maxInt;
            }
            else if(result < minInt)
            {
                return minInt;
            }
        }

        return (int)result;
    }
};

int main()
{
    Solution solution;
    string s = "42";
    cout << solution.myAtoi(s) << endl;
    s = "   -42";
    cout << solution.myAtoi(s) << endl;
    s = "  +002";
    cout << solution.myAtoi(s) << endl;
    s = "4193 with words";
    cout << solution.myAtoi(s) << endl;
    s = "words and 987";
    cout << solution.myAtoi(s) << endl;
    return 0;
}