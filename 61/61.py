import collections
import time
START = time.time()
polys = [[(x*(x+1))//2 for x in range(45,140)],\
         [(x*x) for x in range(32,99)],\
         [(x*((3*x)-1))//2 for x in range(26,81)],\
         [(x*((2*x)-1)) for x in range(23,71)],\
         [((x*((5*x)-3))//2) for x in range(21,64)],\
         [(x*((3*x)-2)) for x in range(19,59)]]
startpoly = 3
polynodes = []
for polylist in polys:
    polynodes.extend([(startpoly,x//100,x%100) for x in polylist if x%100 >= 10 and (x//100)!=(x%100)])
    startpoly+=1

def findCycle(start,nodesCovered,polyscovered,maxlen=5):
    nodesCovered.append(start)
    polyscovered.append(start[0])
##    print("\t"*(len(nodesCovered)-1) + (str(nodesCovered[-1]) if len(nodesCovered)>0 else ""))
    if len(nodesCovered)>=maxlen:
        if nodesCovered[-1][2]==nodesCovered[0][1]:
            print(nodesCovered)
            print(sum([(x[1]*100)+x[2] for x in nodesCovered]))
            return True
        nodesCovered.pop()
        polyscovered.pop()
        return False
    for x in polynodes:
        if x[1]==start[2] and x[0] not in polyscovered:
            if findCycle(x,nodesCovered,polyscovered,maxlen):
                return True
    nodesCovered.pop()
    polyscovered.pop()
    return False
    
    
for p in [x for x in polynodes if x[0]==8]:
    if findCycle(p,collections.deque(),collections.deque(),6):
        break
print(time.time()-START)
