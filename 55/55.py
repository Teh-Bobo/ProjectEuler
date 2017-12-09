import time
def isPalindrome(a):
    sa = str(a)
    return sa[:len(sa)//2] == sa[:(len(sa)-1)//2:-1]
#Reverse str s = s[::-1]
start = time.time()
MAX = 10000
MAXITER = 50
answer = 0
for base in range(MAX):
    iters = 1
    num = base + int(str(base)[::-1])
    while not isPalindrome(num) and iters < MAXITER:
        num += int(str(num)[::-1])
        iters += 1
    if iters == MAXITER:
        answer += 1

print(answer)
print(time.time() - start)
