import re
input_string =input()
three_letter_words = re.findall(r'\b\w{3}\b', input_string)
print(three_letter_words)