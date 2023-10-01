class Solution:
    def reverseWords(self, s: str) -> str:
        s_list = s.split(" ")
        return " ".join([item[::-1] for item in s_list])