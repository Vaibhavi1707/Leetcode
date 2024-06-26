#
# @lc app=leetcode id=1002 lang=python3
#
# [1002] Find Common Characters
#

# @lc code=start

class Solution:
    def commonChars(self, words: List[str]) -> List[str]:
        words_freqs = []
        for word in words:
            freq = {}
            for ch in word:
                if ch not in freq:
                    freq[ch] = 0
                freq[ch] += 1
            words_freqs.append(freq)
            
        set_words = [set(word) for word in words]
        word_intersection = set.intersection(*set_words)
        
        word_counts = {}
        for word_freq in words_freqs:
            for ch in word_intersection:
                if ch not in word_counts:
                    word_counts[ch] = []
                word_counts[ch].append(word_freq[ch])        
        
        cnt_char_intersections = []
        for ch in word_counts:
            cnt_char_intersections.append((min(word_counts[ch]), ch))
        
        uniq_list = []
        for cnt, char in cnt_char_intersections:
            uniq_list += [char] * cnt
            
        return uniq_list
# @lc code=end

