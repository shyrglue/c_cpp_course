sum=0
i=1
while i<=100:
    if i%5==0:
        sum+=i
    i+=1
print(sum)

str=input()
n=0
for s in str:
    if s.isalpha():
        n+=1
print(n)