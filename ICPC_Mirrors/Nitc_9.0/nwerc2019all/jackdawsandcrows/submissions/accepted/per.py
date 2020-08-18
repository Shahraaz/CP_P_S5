def cost(v1, v2, sgn=1):
    return v1 is not None and v2 is not None and sgn*v1*v2 >= 0

class Elem:
    def __init__(self, v, p):
        self.v = v
        self.f = 1
        self.prev = p
        if p: p.next = self
        self.next = None
    def rm(self):
        if self.prev: self.prev.next = self.next
        if self.next: self.next.prev = self.prev
    def midc(self):
        return self.next is not None and self.prev is not None and cost(self.prev.v, self.next.v, 1-2*(self.f % 2))
    def merge(self, node):
        if node is None: return 0
        if node.v is None:
            self.f += node.f
            node.rm()
            return node.midc()
        return cost(self.v, node.v)
    def fuzzy(self):
        delta = self.merge(self.prev) + self.merge(self.next) - self.midc()
        self.v = None
        return delta

def solve():
    (n, x, y) = map(int, raw_input().split())
    A = map(int, raw_input().split())
    V = [Elem(A[0], None)]
    p = A[0]
    dels = A[0] == 0
    for i in range(1, n):
        dels += p*A[i] > 0 or not A[i]
        if A[i]: p = A[i]
        V.append(Elem(A[i], V[-1]))
    ans = y*dels
    dels = sum(A[i]*A[i+1] >= 0 for i in range(n-1))

    for (c, v) in sorted(zip(map(abs, A), V)):
        dels -= v.fuzzy()
        ans = min(ans, (c+1)*x + y*dels)
    return ans

print solve()
    
