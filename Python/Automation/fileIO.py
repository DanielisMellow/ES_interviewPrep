# Iterates through .txt file line by line
f = open("inputFile.txt", "r")
passFile = open("PassFile.txt", "w")

# print(f.read())
# f.close

# Iterate through the file by line
count = 0
for line in f:
    line_split = line.split()
    if line_split[2] == "P":
        # print(f"{count}: {line}")
        passFile.write(f"{line}")
    # print(str(count) + line)
    count += 1

# Always close files are being done using them
f.close()
passFile.close()
