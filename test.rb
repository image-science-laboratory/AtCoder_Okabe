a = [1,1,1,2,2,3,]

aa = a.group_by(&:itself).to_a
p aa 
p aa.length 
