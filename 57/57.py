import time
START = time.time()
d = [2,5]
n = [3,7]
for i in range(1000):
	d.append(d[-1]*2+d[-2])
	n.append(n[-1]*2+n[-2])
ans = 0
for i in range(len(n)):
    if len(str(n[i])) > len(str(d[i])):
        ans+=1
print(ans)
print(time.time() - START)
