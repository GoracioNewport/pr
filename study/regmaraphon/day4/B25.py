maxN = 541
maxF = 10000
isPrime = list(range(maxN + 1))
isPrime[1] = 0

for i in isPrime:
  if (i > 1):
    for j in range(i + i, len(isPrime), i):
      isPrime[j] = 0

factorial = list(range(maxF + 1))
factorial[0] = 1
for i in range(1, len(factorial)):
  factorial[i] = factorial[i - 1] * i

primes = list()
for i in isPrime: 
  if (i != 0): primes.append(i)

t = int(input())

# for i in range(len(primes)):
#   print('{' + str(primes[i]) + ', ' + str(i) + '}, ', end = '')
# print(factorial)

for k in range(t):
  m = int(input())
  num = 1
  a = [int(i) for i in input().split()]
  for i in range(m):
    num *= (primes[i] ** a[i])
  
  # print(num)
  
  for i in range(len(factorial)):
    if (factorial[i] % num == 0):
      print(i)
      break