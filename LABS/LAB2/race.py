def mergeSort(alist):
    if len(alist) > 1:
       mid = len(alist) // 2
       lefthalf = alist[:mid]
       righthalf = alist[mid:]

       mergeSort(lefthalf)
       mergeSort(righthalf)

       i = 0
       j = 0
       k = 0

       while i < len(lefthalf) and j < len(righthalf):
           if lefthalf[i] < righthalf[j]:
               alist[k] = lefthalf[i]
               i = i + 1
           else:
               alist[k] = righthalf[j]
               j = j + 1
           k = k + 1

       while i < len(lefthalf):
           alist[k] = lefthalf[i]
           i = i + 1
           k = k + 1

       while j < len(righthalf):
           alist[k] = righthalf[j]
           j = j + 1
           k = k + 1


fin = open("race.in")
n = int(fin.readline())
l = {}
for i in range(n):
    country, name = map(str, fin.readline().split())

    if country not in l:
        l[country] = [name]
    else:
        l[country].append(name)

alist = list(l.keys())
mergeSort(alist)
fout = open("race.out", "w")
for i in range(len(alist)):
    print("===", alist[i], "===", file=fout)
    for j in l[alist[i]]:
        print(j, file=fout)
fout.close()
