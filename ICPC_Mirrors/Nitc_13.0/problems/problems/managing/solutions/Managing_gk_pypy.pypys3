for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    ans = 0
    cnts = {}
    for j in range(n - 1, -1, -1):
        for i in range(j):
            ak = a[j] + a[j] - a[i]
            if ak in cnts:
                ans += cnts[ak]
        if a[j] in cnts:
            cnts[a[j]] += 1
        else:
            cnts[a[j]] = 1
    print(ans)
