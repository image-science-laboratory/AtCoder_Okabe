import itertools

n, m = list(map(int, input().split(" ")))
sets = list() # 集合のリスト

# S_i を入力
for i in range(m):
	input()
	sets.append(set(list(map(int, input().split(" ")))))
# end of for

bits = [i for i in range(m)] # 全探索用
ans = 0
for i in range(m):
	# itertoolsを使うことで順列・組み合わせの列挙ができる
	for v in itertools.combinations(bits, i + 1):
		uni_set = set()	
		# コンビネーションで選択されたS_iの和集合を作る
		for b in v:
			uni_set = uni_set.union(sets[b])

			# 1 ~ N まであったらカウントして終わり
			if len(uni_set) == n: 
				ans += 1
				break
		#print(f"i:{i} v:{v} set:{uni_set}")
	# end of iterator
# end of for		

print(ans)
