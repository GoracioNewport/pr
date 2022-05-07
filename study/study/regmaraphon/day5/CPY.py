a, b, k = map(int, input().split())
ans = 0
for i in range(max(a,10**(k-1)), b + 1):
  s = str(i)
  for j in range(len(s) - k + 1):
    s1 = s[j:j + k]
    # print(s1)
    good = True
    for z in range(len(s1) - 1): 
      if (s1[z] != s1[z + 1]): good = False
    if (good):
      ans += 1
      break
print(ans)