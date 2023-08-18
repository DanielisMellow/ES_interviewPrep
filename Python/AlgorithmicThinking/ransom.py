
# def ransom_note(magazine, note):
#     dic = {}
#     for idx, val in enumerate(magazine):
#         if val in dic:
#             dic[val] += 1
#         else:
#             dic[val] = 1

#     return dic


def ransomNote(magazine, note):
    word_dic = {}

    for word in magazine:
        if word in word_dic:
            word_dic[word] += 1
        else:
            word_dic[word] = 1

    for word in note:
        #.get(word,0) tries to access the word in dic but if it doesn't find the key it returns 0
        if word_dic.get(word,0) < 1:
            return False
        else:
            word_dic[word] -= 1

    return True


magazine = "give me one grand today night".split()
note = "give one grand today".split()
print(ransomNote(magazine, note))
assert ransomNote(magazine, note) is True



magazine = "two times three is not four".split()
note = "two times two is four".split()
print(ransomNote(magazine, note))
assert ransomNote(magazine, note) is False

