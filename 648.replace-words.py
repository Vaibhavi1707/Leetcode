#
# @lc app=leetcode id=648 lang=python3
#
# [648] Replace Words
#

# @lc code=start

def get_word_root(word, dictionary):
    for root in dictionary:
        if word.startswith(root):
            return root
    return None

class Solution:
    def replaceWords(self, dictionary: List[str], sentence: str) -> str:
        dictionary.sort(key = len)
        words = sentence.split()
        
        new_words = []
        for word in words:
            root = get_word_root(word, dictionary)
            
            if not root:
                new_words.append(word)
            else:
                new_words.append(root)
        
        return ' '.join(new_words).rstrip()
# @lc code=end

