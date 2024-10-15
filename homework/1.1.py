import random

num=random.randint(12, 20)
guessnum = int(input("12-20:"))
if guessnum>num:
    print("too large")
elif guessnum<num:
    print("too small")
else:
    print("right")

print("game over num is:",num)