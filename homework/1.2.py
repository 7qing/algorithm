import random

num=random.randint(12, 20)
guessnum = int(input("12-20:"))
time =3
while guessnum!=num and time>0:
    if guessnum>num:
        print("too large")
    else:
        print("too small")
    guessnum = int(input())
    time=time-1

if(guessnum==num):
    print("right")
else:
    print("game over num is:",num)