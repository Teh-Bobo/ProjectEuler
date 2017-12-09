import time
def arePermutes(a,b):
    a = str(a)
    b = str(b)
    if len(a) != len(b):
        return False
    for i in a:
        if i not in b:
            return False
    return True

start = time.time()
num = 1
while True:
    p = [num*i for i in range(1,7)]
    t = [arePermutes(p[y],p[y+1]) for y in range(0,len(p)-1)]
    if all(t):
        print(num)
        print(p)
        print(time.time() - start)
        break
    num += 1
