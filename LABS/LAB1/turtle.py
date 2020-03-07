def turtle(i, j):
    global numbers, numbersForce
    compare2 = 0
    compare1 = 0

    if j < b - 1:
        if numbersForce[i][j + 1] != 0:
            compare1 = numbersForce[i][j + 1]
        else:
            turtle(i, j + 1)
            compare1 = numbersForce[i][j + 1]

        if i != 0:
            if numbersForce[i - 1][j] != 0:
                compare2 = numbersForce[i - 1][j]
            else:
                turtle(i - 1, j)
                compare2 = numbersForce[i - 1][j]

        numbersForce[i][j] = numbers[i][j] + (compare1 if compare1 > compare2 else compare2)

    else:
        if i != 0:
            turtle(i - 1, j)
            numbersForce[i][j] = numbersForce[i - 1][j] + numbers[i][j]


fin = open("turtle.in")
a, b = map(int, fin.readline().split())
numbers = []
numbersForce = [[0] * b for i in range(a)]
for i in range(a):
    numbers.append([int(i) for i in fin.readline().split()])
numbersForce[0][b - 1] = numbers[0][b - 1]

turtle(a - 1, 0)

fout = open("turtle.out", "w")
print(numbersForce[a - 1][0], file=fout)
fout.close()