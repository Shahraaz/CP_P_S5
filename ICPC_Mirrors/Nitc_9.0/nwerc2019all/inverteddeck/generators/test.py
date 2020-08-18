import random

random.seed(13)

for i in range(0,7):
  n = 10**i

  cards = []

  for j in range(n):
    cards.append(random.randint(1, 10**9))

  cards.sort()

  first = random.randint(0, n-1)
  second = random.randint(first+1, n)

  list1 = cards[:first]
  list2 = cards[first:second]
  list2.reverse()
  list3 = cards[second:]
  
  cards = list1 + list2 + list3

  f_in = open("./data/secret/"+str(101+i)+"-random.in", "w")
  f_in.write(str(n)+"\n")
  cardsstr = " ".join(str(x) for x in cards)
  f_in.write(cardsstr+"\n")
  f_in.close()

  f_ans = open("./data/secret/"+str(101+i)+"-random.ans", "w")
  f_ans.write(str(first+1)+" "+str(second)+"\n")
  f_ans.close()

  cards = []
  for j in range(n):
    cards.append(random.randint(1, round(0.5 + n/10)))

  cards.sort()

  first = random.randint(0, n-1)
  second = random.randint(first+1, n)

  list1 = cards[:first]
  list2 = cards[first:second]
  list2.reverse()
  list3 = cards[second:]
  
  cards = list1 + list2 + list3

  f_in = open("./data/secret/"+str(108+i)+"-random.in", "w")
  f_in.write(str(n)+"\n")
  cardsstr = " ".join(str(x) for x in cards)
  f_in.write(cardsstr+"\n")
  f_in.close()

  f_ans = open("./data/secret/"+str(108+i)+"-random.ans", "w")
  f_ans.write(str(first+1)+" "+str(second)+"\n")
  f_ans.close()

  cards.sort(reverse=True)

  f_in = open("./data/secret/"+str(115+i)+"-random.in", "w")
  f_in.write(str(n)+"\n")
  cardsstr = " ".join(str(x) for x in cards)
  f_in.write(cardsstr+"\n")
  f_in.close()

  f_ans = open("./data/secret/"+str(115+i)+"-random.ans", "w")
  f_ans.write("1 "+str(n)+"\n")
  f_ans.close()