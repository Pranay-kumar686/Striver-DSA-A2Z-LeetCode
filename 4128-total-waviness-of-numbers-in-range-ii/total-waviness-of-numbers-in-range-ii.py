class Solution:
    def totalWaviness(self, num1: int, num2: int) -> int:
        def solve(n):
            if n < 0:
                return 0

            s = str(n)
            memo = {}

            def dfs(pos, started, state, last2, last1, tight):
                if pos == len(s):
                    return (1, 0)  # (count, waviness)

                key = (pos, started, state, last2, last1)
                if not tight and key in memo:
                    return memo[key]

                limit = int(s[pos]) if tight else 9
                total_cnt = 0
                total_wav = 0

                for d in range(limit + 1):
                    ntight = tight and (d == limit)

                    if not started and d == 0:
                        cnt, wav = dfs(
                            pos + 1, False, 0, -1, -1, ntight
                        )
                    else:
                        if not started:
                            cnt, wav = dfs(
                                pos + 1, True, 1, -1, d, ntight
                            )

                        elif state == 1:
                            cnt, wav = dfs(
                                pos + 1, True, 2, last1, d, ntight
                            )

                        else:
                            add = int(
                                (last1 > last2 and last1 > d) or
                                (last1 < last2 and last1 < d)
                            )

                            cnt, wav = dfs(
                                pos + 1, True, 2, last1, d, ntight
                            )

                            wav += cnt * add

                    total_cnt += cnt
                    total_wav += wav

                if not tight:
                    memo[key] = (total_cnt, total_wav)

                return total_cnt, total_wav

            return dfs(0, False, 0, -1, -1, True)[1]

        return solve(num2) - solve(num1 - 1)