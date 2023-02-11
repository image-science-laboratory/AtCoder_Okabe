import queue
stack = queue.LifoQueue()

n, m = list(map(int, input().split(" ")))

# 例外処理
if m == 0: 
	ans = [i + 1 for i in range(n)]
	print(" ".join(list(map(str, ans))))
	exit(0)

arr = list(map(int, input().split(" ")))
arr = set(arr)

ans = []
for ii in range(n): # 1 ~ n で列挙する方法を知らないので無理やり実装
	i = ii + 1
	# レ点が来るときはいったんスタックに貯めておく
	if i in arr:
		stack.put(i)
	# レ点が無いときはスタックを開放してansにつっこむ
	else:
		ans.append(i)
		while stack.empty() == False:
			ans.append(stack.get())
	# end of ifelse
# end of for

print(" ".join(list(map(str, ans))))

	