queue = []
fin = open("queue.in")
fout = open("queue.out", "w")
n = int(fin.readline())
down = 0

for i in range(n):
    data = list((fin.readline().split()))

    if data[0] == "+":
        data[1] = int(data[1])
        queue.append(data[1])


    else:
        print(queue[down], file=fout)
        down += 1
fout.close()