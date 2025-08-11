T = int(input())

for _ in range(T):
    x,y = map(int,input().split())
    i = 0
    goal_distance = y-x
    moved_distance = 0
    count = 0

    while True:
        i += 1
        moved_distance += i*2
        count += 2
        if moved_distance - i >= goal_distance:
            print(count - 1)
            break
        elif moved_distance >= goal_distance:
            print(count)
            break