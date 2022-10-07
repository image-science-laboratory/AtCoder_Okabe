n = gets.chomp.to_i 
manga = gets.chomp.split.map(&:to_i)
manga.sort!

hash = {0}
manga.each do |m|
    hash[m] += 1
end

count = 0

