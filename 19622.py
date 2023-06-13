import sys
input = sys.stdin.readline
N = int(input())
meetings = []
for n in range(N):
    start, end, count = map(int, input().split())
    meetings.append(count)

dp = [0 for _ in range(len(meetings))]
if len(dp) == 1:
    print(meetings[0])
    exit()
if len(dp) >= 2:
    dp[0] = meetings[0]
    dp[1] = max(meetings[0], meetings[1])
for i in range(2, len(dp)):
    dp[i] = max(dp[i-2] + meetings[i], dp[i-1])

print(dp[-1])
