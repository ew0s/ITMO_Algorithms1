fin = open("postfix.in")
fout = open("postfix.out", "w")
top = -1

line = list(fin.readline().split())
stack = [0] * 100

for i in range(len(line)):
    if line[i] == "+":
        top -= 1
        stack[top] += stack[top + 1]

    elif line[i] == "-":
        top -= 1
        stack[top] -= stack[top + 1]

    elif line[i] == "*":
        top -= 1
        stack[top] *= stack[top + 1]

    else:
        top += 1
        stack[top] = int(line[i])

print(stack[top], file=fout)

fout.close()