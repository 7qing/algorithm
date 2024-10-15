def count_word_frequency(input_string):
    words = input_string.split()

    word_count = {}

    for word in words:
        word = word.strip().lower() 
        if word in word_count:
            word_count[word] += 1
        else:
            word_count[word] = 1

    # 返回字典
    return word_count

input_string =input()

word_count = count_word_frequency(input_string)

print("单词出现次数：")
for word, count in word_count.items():
    print(f"{word}: {count}")