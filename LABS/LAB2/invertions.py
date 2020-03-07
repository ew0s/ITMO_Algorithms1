def merge_sort(array, left, right):
    i, j, count = 0, 0, 0

    while i < len(left) or j < len(right):
        if i == len(left):
            array[i + j] = right[j]
            j += 1
        elif j == len(right):
            array[i + j] = left[i]
            i += 1
        elif left[i] <= right[j]:
            array[i + j] = left[i]
            i += 1
        elif right[j] < left[i]:
            array[i + j] = right[j]
            count += len(left) - i
            j += 1

    return count


def score_of_count(array):
    if len(array) < 2:
        return 0

    m = (len(array) + 1) // 2

    left = []
    for i in range(m):
        left.append(array[i])

    right = []
    for i in range(m, len(array)):
        right.append(array[i])

    return score_of_count(left) + score_of_count(right) + merge_sort(array, left, right)


fin = open("inversions.in")
n = int(fin.readline())
array = [int(i) for i in fin.readline().split()]

fout = open("inversions.out", "w")
print(score_of_count(array), file=fout)
fout.close()