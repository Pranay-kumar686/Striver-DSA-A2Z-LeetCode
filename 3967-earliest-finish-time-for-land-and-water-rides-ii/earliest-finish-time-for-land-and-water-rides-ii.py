from typing import List
from bisect import bisect_right

class Solution:
    def earliestFinishTime(self, landStartTime: List[int], landDuration: List[int],
                           waterStartTime: List[int], waterDuration: List[int]) -> int:

        def solve(Astart, Adur, Bstart, Bdur):
            rides = sorted(zip(Bstart, Bdur))
            m = len(rides)

            starts = [s for s, _ in rides]

            pref_min_dur = [0] * m
            pref_min_dur[0] = rides[0][1]
            for i in range(1, m):
                pref_min_dur[i] = min(pref_min_dur[i - 1], rides[i][1])

            suff_min = [0] * m
            suff_min[-1] = rides[-1][0] + rides[-1][1]
            for i in range(m - 2, -1, -1):
                suff_min[i] = min(suff_min[i + 1],
                                  rides[i][0] + rides[i][1])

            ans = float('inf')

            for s, d in zip(Astart, Adur):
                finish = s + d
                pos = bisect_right(starts, finish)

                best = float('inf')

                if pos > 0:
                    best = min(best, finish + pref_min_dur[pos - 1])

                if pos < m:
                    best = min(best, suff_min[pos])

                ans = min(ans, best)

            return ans

        return min(
            solve(landStartTime, landDuration,
                  waterStartTime, waterDuration),
            solve(waterStartTime, waterDuration,
                  landStartTime, landDuration)
        )