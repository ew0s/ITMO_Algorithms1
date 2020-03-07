stack = [0] * 1000000
fin = open("stack.in")
fout = open("stack.out", "w")
n = int(fin.readline())
top = -1

for i in range(n):
    data = list(fin.readline().split())

    if data[0] == "+":
        top += 1
        data[1] = int(data[1])

        stack[top] = data[1]


    else:
        print(stack[top], file=fout)
        top -= 1
fout.close()