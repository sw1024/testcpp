mytable = {123, 12.44, {1,2}, "hello", "this", "is", "SunWu", "five"}
mytable[8] = "world"
mytable["wow"] = "key"
for k, v in ipairs(mytable) do
	print(k, v)
end
