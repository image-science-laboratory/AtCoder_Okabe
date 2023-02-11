import queue
stack = queue.LifoQueue()

n, m = list(map(int, input().split(" ")))
if m == 0: 
	ans = [i + 1 for i in range(n)]
	print(" ".join(list(map(str, ans))))
	exit(0)
	
arr = list(map(int, input().split(" ")))
arr = set(arr)

ans = []
for ii in range(n):
	i = ii + 1
	if i in arr:
		stack.put(i)
	else:
		ans.append(i)
		while stack.empty() == False:
			ans.append(stack.get())

print(" ".join(list(map(str, ans))))

	