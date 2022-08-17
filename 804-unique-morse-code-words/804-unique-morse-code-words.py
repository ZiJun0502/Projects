class Solution:
    def uniqueMorseRepresentations(self, words: List[str]) -> int:
        morse = [".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."]
        seen = {}
        for word in words:
            temp = ""
            for c in word:
                temp += morse[ord(c) - ord('a')]
            if temp not in seen:
                seen[temp] = 1
        return len(seen)