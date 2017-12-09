import time
START = time.time()
numfound = 0
for j in range(1,22):
    for i in range(1,10):
        exp = str(i**j)
        if len(exp)>j:
            break
        if len(exp)==j:
            numfound+=1
##            print(len(exp),exp,i,j,numfound)
print(numfound)
print(time.time()-START)
    
