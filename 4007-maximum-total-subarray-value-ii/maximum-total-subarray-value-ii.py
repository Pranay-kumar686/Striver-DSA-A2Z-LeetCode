import heapq
from typing import List

class SparseTableRMQ:
    def __init__(self, nums: List[int]):
        self.n = len(nums)
        self.log = [0] * (self.n + 1)

        for i in range(2, self.n + 1):
            self.log[i] = self.log[i // 2] + 1

        k = self.log[self.n] + 1

        self.mx = [[0] * k for _ in range(self.n)]
        self.mn = [[0] * k for _ in range(self.n)]

        for i in range(self.n):
            self.mx[i][0] = nums[i]
            self.mn[i][0] = nums[i]

        j = 1
        while (1 << j) <= self.n:
            length = 1 << j
            half = length >> 1

            for i in range(self.n - length + 1):
                self.mx[i][j] = max(
                    self.mx[i][j - 1],
                    self.mx[i + half][j - 1]
                )
                self.mn[i][j] = min(
                    self.mn[i][j - 1],
                    self.mn[i + half][j - 1]
                )
            j += 1

    def query_max(self, l: int, r: int) -> int:
        k = self.log[r - l + 1]
        return max(
            self.mx[l][k],
            self.mx[r - (1 << k) + 1][k]
        )

    def query_min(self, l: int, r: int) -> int:
        k = self.log[r - l + 1]
        return min(
            self.mn[l][k],
            self.mn[r - (1 << k) + 1][k]
        )


class Solution:
    def maxTotalValue(self, nums: List[int], k: int) -> int:
        n = len(nums)
        st = SparseTableRMQ(nums)

        heap = []

        for l in range(n):
            value = st.query_max(l, n - 1) - st.query_min(l, n - 1)
            heapq.heappush(heap, (-value, l, n - 1))

        ans = 0

        for _ in range(k):
            neg_val, l, r = heapq.heappop(heap)
            val = -neg_val
            ans += val

            if r > l:
                nxt = st.query_max(l, r - 1) - st.query_min(l, r - 1)
                heapq.heappush(heap, (-nxt, l, r - 1))

        return ans