fin = open("priorityqueue.in", 'r')
fout = open("priorityqueue.out", 'w')

commands = []
queue = []

line = fin.readline()

while len(line):

    commands.append(line.split())
    line = fin.readline()

for c in commands:

    if c[0] == 'push':

        queue.append(int(c[1]))

    elif c[0] == 'extract-min':

        if len(queue):

            mini = queue[0]
            index = 0

            for e in range(len(queue) - 1, -1, -1):
                if queue[e] < mini:
                    mini = queue[e]
                    index = e

            print(mini, file=fout)

            del queue[index]
        else:

            print('*', file=fout)

    elif c[0] == 'decrease-key':

        elem = int(commands[int(c[1]) - 1][1])

        commands[int(c[1]) - 1][1] = int(c[2])

        for i in range(len(queue)):

            if queue[i] == elem:
                queue[i] = int(c[2])
                break