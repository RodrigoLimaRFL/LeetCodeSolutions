class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        longest_size = 0
        #longest_substring = ""
        current_substring = ""
        previous_letters = {}


        for i in range(len(s)):
            current_substring += s[i]
            if s[i] in previous_letters:
                for j in range(len(current_substring)):
                    if current_substring[j] == s[i]:
                        current_substring = current_substring[j+1:]
                        break
                    previous_letters.pop(current_substring[j])

            if len(current_substring) > longest_size:
                longest_size = len(current_substring)
                #longest_substring = current_substring

            previous_letters[s[i]] = i
            

        return longest_size