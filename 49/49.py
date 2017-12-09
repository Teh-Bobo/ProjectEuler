import sys
sys.path.insert(0, "C:\\Users\\bobo\\Documents\\Code\\eulerlib-py")
import FactorTable
import time

start = time.time()
MAX = 9999
f = FactorTable.FactorTable(MAX)
primes = f.PrimesInRange(1001,9999)

def permute(x):
    s = str(x)
    a = s[0]
    b = s[1]
    c = s[2]
    d = s[3]
    ret = list(set(map(int,[a+b+c+d,a+b+d+c,a+d+b+c,a+d+c+b,a+c+b+d,a+c+d+b,\
            b+a+c+d,b+a+d+c,b+d+a+c,b+d+c+a,b+c+a+d,b+c+d+a,\
            c+a+b+d,c+a+d+b,c+d+a+b,c+d+b+a,c+b+a+d,c+b+d+a,\
            d+a+b+c,d+a+c+b,d+c+a+b,d+c+b+a,d+b+c+a,d+b+a+c])))
    if "0" in s: #handle leading 0s
        sret = map(str,ret)
        remove = list(map(int,filter(lambda x: len(x) < 4,sret)))
        for r in remove:
            ret.remove(r)
    return ret
ret = []
for p in primes:
    fil = sorted(list(set(filter(f.IsPrime,permute(p)))))
    if len(fil) < 3:
        continue
    ret.append(fil)
sret = sorted(list(set(map(tuple,ret))))
for s in sret:
    for i in range(len(s)):
        for j in range(i+1,len(s)):
            diff = s[j] - s[i]
            if s[j] + diff in s:
                print(s[i],s[j],s[j]+diff)
print(time.time()-start)

