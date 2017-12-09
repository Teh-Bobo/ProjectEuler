import time

start = time.time()
MAX = 10000

pents = frozenset([int((n*(3*n-1))/2) for n in range(1,MAX)])
ansi = 0
ansj = 0
diff = None
for i in pents:
    for j in pents:
        if i + j in pents and j - i in pents and (diff == None or i - i < diff):
            ansi = i
            ansj = j
            diff = j - i
            print(i,j,diff)
            print(time.time()-start)
print(diff)
print(time.time()-start)
