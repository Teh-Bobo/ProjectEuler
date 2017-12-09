import math
import sys
import time
sys.path.insert(0, "..\\..\\eulerlib-py")
import FactorTable

MAX = 19999999
MAXPRIME = MAX//100
start = time.time()
ft = FactorTable.FactorTable(MAX)
print("FT Done.")
print(time.time()-start)
##strprimes = [str(i) for i in ft.PrimesInRange(0,MAX)]
##for i in range(len(strprimes)-1,-1,-1):
##    if len(strprimes[i]) <= len(str(MAX))-2:
##        MAXINDEX = i+1
##        print(i,strprimes[i])
##        break

print("Tables Done")
def intconcat(x,y):
    return int(x*10**(1+math.floor(math.log10(y)))+y)
def IsPrimePair(x,y):
    a = intconcat(x,y)
    b = intconcat(y,x)
    if a > MAX or b > MAX:
        return None
    return ft.IsPrime(a) and ft.IsPrime(b)

res = {}
for p in ft.PrimesInRange(3,int(math.sqrt(MAX))+1):
    for pp in ft.PrimesInRange(3,MAXPRIME):
        if IsPrimePair(p,pp):
            if p not in res:
                res[p] = []
            if pp not in res:
                res[pp] = []
            res[p].append(pp)
##            res[pp].append(p)
##print(res)
sums = []
for b in res:
    for c in res[b]:
        intr = set(res[b]) & set(res[c])
        if len(intr) > 0:
##            res[c].remove(b)
            for d in list(intr):
                if d == b or d == c: continue
                intr = intr & set(res[d])
                if len(intr) > 0:
                    print(b,c,d,intr)
##                    res[d].remove(c)
                    for e in list(intr):
                        if e==b or e==c or e==d: continue
                        intr = intr & set(res[e])
                        if len(intr) > 0:
                            sums.append(sum([b,c,d,e,min(intr)]))
                            print(sums[-1],b,c,d,e,intr)
##print(min(sums))
print(time.time()-start)            
####def Search(pairList,lastindex,MaxDepth,CurrentDepth):
####    if CurrentDepth >= MaxDepth: return
####    for i,p in enumerate(strprimes[lastindex+1:MAXINDEX]):
####        bools = [IsPrimePair(x,p) for x in pairList]
####        if None in bools: break
####        if all(bools):
####            pairList.append(p)
####            if len(pairList) >= MaxDepth:
####                print(pairList,lastindex,MaxDepth,CurrentDepth)
####            if CurrentDepth < MaxDepth:
####                Search(pairList,i,MaxDepth,CurrentDepth+1)
####            pairList.pop()
####for i,p in enumerate(strprimes):
####    Search([p],i,5,1)
##for i,num in enumerate(strprimes):
##    for j,num2 in enumerate(strprimes[i+1:]):
##        pp = IsPrimePair(num,num2)
##        if pp is None: break
##        if pp:
##            for k,num3 in enumerate(strprimes[j+1:]):
##                pp1 = IsPrimePair(num3,num2)
##                pp2 = IsPrimePair(num3,num)
##                if pp1 is None or pp2 is None: break
##                if pp1 and pp2:
####                    print(num,num2,num3)
##                    for l,num4 in enumerate(strprimes[k+1:]):
##                        pp1 = IsPrimePair(num4,num3)
##                        pp2 = IsPrimePair(num4,num2)
##                        pp3 = IsPrimePair(num4,num)
##                        if pp1 is None or pp2 is None or pp3 is None: break
##                        if pp1 and pp2 and pp3:
##                            print(num,num2,num3,num4)
##                            for m,num5 in enumerate(strprimes[l+1]):
##                                pp1 = IsPrimePair(num5,num4)
##                                pp2 = IsPrimePair(num5,num3)
##                                pp3 = IsPrimePair(num5,num2)
##                                pp4 = IsPrimePair(num5,num)
##                                if pp1 is None or pp2 is None or pp3 is None: break
##                                if pp1 and pp2 and pp3 and pp4:
##                                    print(num,num2,num3,num4,num5)
##
##
