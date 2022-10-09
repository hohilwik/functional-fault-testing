import csv

filename = "table.txt"

with open(filename) as f:
    lines = f.readlines()


def clean(line):
    return line.rstrip("\n")


def parse_result(result):
    result_ = result.split()[1:]
    node = int(result_[0])
    if result_[1] == 's-a-0':
        sa = 0
    elif result_[1] == 's-a-1':
        sa = 1
    return (node, sa)


def printmat(mat):

    for line in mat:
        for i in line:
            print("%3s|" % (i), end="")
        print()


def add_test(mat, testcase_num, node, sa):

    row = testcase_num + 1
    col_start = (2 * node) - 1
    if sa == 0:
        col = col_start
    elif sa == 1:
        col = col_start + 1

    mat[row][col] = 'Y'
    return mat


# making the main CSV matrix
header1 = ["  "]
for i in range(16):
    header1 += [i + 1, i + 1]
header2 = ["  "] + ['s0', 's1'] * 16
mat = [header1, header2]
for i in range(32):
    mat.append([str(i + 1)] + [" " for i in range(32)])


lines = [clean(line) for line in lines]
for i in range(0, 64, 2):
    testcase = lines[i]
    testcase_num = testcase.split()[1]
    results = lines[i + 1]

    sub_results = results.split(", ")
    sub_results = [x.rstrip(",").lstrip() for x in sub_results]
    parsed_results = [parse_result(res) for res in sub_results]

    for node, sa in parsed_results:
        mat = add_test(mat, int(testcase_num), int(node), int(sa))
    
with open("table.csv", "w+") as f:
    writer = csv.writer(f)
    writer.writerows(mat)
