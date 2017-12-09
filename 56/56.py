def F(x):
    sx = str(x)
    ret=0
    for i in sx:
            ret += int(i)
    return ret

print(max(map(F,[a**b for a in range(100) for b in range(100)])))
