from typing import List

class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        if len(strs) == 1:
            return strs[0]
        smallestStrSize = 999

        for i in range(len(strs)):
            if len(strs[i]) < smallestStrSize:
                smallestStrSize = len(strs[i])

        prefix = ""

        for i in range(smallestStrSize):
            currentLetter = strs[0][i]

            for j in range(1, len(strs)):
                if strs[j][i] != currentLetter:
                    return prefix
            
            prefix += currentLetter

        return prefix