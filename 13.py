class Solution:
    def romanToInt(self, s: str) -> int:
        end = len(s) - 1
        num = 0

        while s[end] == "I":
            num += 1
            end -= 1

            if(end < 0):
                return num
            
        if s[end] == "V":
            if end > 0 and s[end - 1] == "I":
                num += 4
                end -= 2
            else:
                num += 5
                end -= 1
            
            if(end < 0):
                return num

        while s[end] == "X":
            if end > 0 and s[end - 1] == "I":
                num += 9
                end -= 2
            else:
                num += 10
                end -= 1

            if(end < 0):
                return num   
            
        if s[end] == "L":
            if end > 0 and s[end - 1] == "X":
                num += 40
                end -= 2
            else:
                num += 50
                end -= 1

            if(end < 0):
                return num
     
        while s[end] == "C":
            if end > 0 and s[end - 1] == "X":
                num += 90
                end -= 2
            else:
                num += 100
                end -= 1

            if(end < 0):
                return num
      
        if s[end] == "D":
            if end > 0 and s[end - 1] == "C":
                num += 400
                end -= 2
            else:
                num += 500
                end -= 1

            if(end < 0):
                return num

        while s[end] == "M":
            if end > 0 and s[end - 1] == "C":
                num += 900
                end -= 2
            else:
                num += 1000
                end -= 1
            if(end < 0):
                return num
 
        return num