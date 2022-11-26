require "bigdecimal"

a, b = gets.chomp.split.map(&:to_i)

def bin_search(a, b)
	prev = -1 * (10 ** 20)
	l = 0
	r = 10 ** 20

	aa = BigDecimal(a, 100)
	bb = BigDecimal(b, 100)
	while true
		mid = BigDecimal((l + r) / 2)
		return 0 if mid == 0
		
		if mid == 1
			sq2 = BigDecimal(Math.sqrt(2), 100)
			diff = aa / sq2
		else   
			hoge1 = BigDecimal(aa / Math.sqrt(mid - 1), 100)
			hoge2 = BigDecimal(aa / Math.sqrt(mid), 100)
			diff = (hoge1 - hoge2).abs
		end 

		#puts "l:#{l} mid:#{mid} r:#{mid} diff:#{diff}"

		if diff == b    
			return mid 
		elsif diff < b 
			r = mid.to_i 
		else
			l = mid.to_i
		end

		break if prev == mid
		prev = mid 
	end

	return prev 
end


gnum = bin_search(a, b)
if gnum == 0 
	ans = a 
else 
	ans = a / Math.sqrt(gnum ) + b * (gnum - 1)
	diff = 10 ** 6
	((gnum - diff).to_i).upto((gnum + diff).to_i) do |i|
		next if i <= 0
		hoge = a / Math.sqrt(i ) + b * (i - 1)
		ans = hoge if ans > hoge
	end

end 

puts "gnum:#{gnum}"
puts ans.to_f