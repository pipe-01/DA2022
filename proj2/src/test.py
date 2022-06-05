f = open("Tests/mytest.txt", "r")
f2 = open("Tests/out.txt", "w")

x = []

for line in f:
    line = line[0:len(line)-1]
    if line not in x:
        x.append(line)
        f2.write(line + "\n")
print(x)
