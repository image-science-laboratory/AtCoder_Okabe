n, x, y = gets.chomp.split.map(&:to_i)
x -= 1
y -= 1
tree = Array.new(n).map{Array.new(n, 0)}

(n - 1).times do |i|
    u, v = gets.chomp.split.map{|hoge| hoge.to_i - 1}
    tree[u][v] = 1
    tree[v][u] = 1
end

$hash = {}
def dfs(index, y, route, tree) 
    #puts "index:#{index} route:#{route.join(' ')}"
    route << index 
    $hash[index] = true

    if index == y
        puts route.map{|r| r + 1}.join(" ")
        exit(0)
    end

    tree.length.times do |i|
        if $hash.has_key?(i) == true || tree[index][i] == 0
            next 
        end 

        dfs(i, y, route, tree)
    end

    route.pop
    return route
end

route= []
dfs(x, y, route, tree)