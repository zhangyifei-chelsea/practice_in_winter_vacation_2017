import random
import gmpy2

random.seed(0)

MAX_N = 100
TEST_N = 500
arr = []

output = open('unittest.h', 'w')
output.write('#pragma once\n\n')
output.write('const int MAX_N = ' + str(MAX_N) + ';\n\n')
output.write('const char* BIGNUMBER_STR[] = {\n\n')

for i in range(0, MAX_N):
    numStr = random.randint(0, 1) and '-1' or ''
    length = random.randint(50, 500)
    numStr += chr(random.randint(1, 9) + ord('0'))
    for j in range(0, length):
        numStr += chr(random.randint(0, 9) + ord('0'))
    output.write('"' + numStr + '",\n')
    arr.append(gmpy2.mpz(numStr))

output.write('};\n')
output.close()


def generate_header():
    return '#pragma once\n\n#include "gtest/gtest.h"\n\n'


def generate_test_case(test_case_name, test_name, content):
    return 'TEST(' + test_case_name + ', ' + test_name + ')\n{\n' + content + '}\n'


def generate_exp(x, y, symbol):
    return '\tans = num[' + str(x) + '] ' + symbol + ' num[' + str(y) + '];\n'


def generate_equal(ans):
    return '\tEXPECT_EQ("' + str(ans) + '", ans.toString());\n'


def generate_init():
    content = '\tBigNumber num[MAX_N] = {};\n'
    content += '\tfor (int i = 0;i < MAX_N;i++)\n'
    content += '\t{\n'
    content += '\t\tnum[i] = BigNumber(BIGNUMBER_STR[i]);\n'
    content += '\t}\n'
    content += '\tBigNumber ans;\n'
    return content


init_content = generate_init()
# print init_content

addition_content = ''
subtraction_content = ''
multiple_content = ''
division_content = ''

for i in range(0, TEST_N):
    indexX = random.randint(0, MAX_N - 1)
    indexY = random.randint(0, MAX_N - 1)
    X = arr[indexX]
    Y = arr[indexY]
    ans = gmpy2.add(X, Y)
    addition_content += generate_exp(indexX, indexY, '+')
    addition_content += generate_equal(ans)
    ans = gmpy2.sub(X, Y)
    subtraction_content += generate_exp(indexX, indexY, '-')
    subtraction_content += generate_equal(ans)
    ans = gmpy2.mul(X, Y)
    multiple_content += generate_exp(indexX, indexY, '*')
    multiple_content += generate_equal(ans)
    ans = gmpy2.t_div(X, Y)
    division_content += generate_exp(indexX, indexY, '/')
    division_content += generate_equal(ans)
    ans = gmpy2.t_mod(X, Y)
    division_content += generate_exp(indexX, indexY, '%')
    division_content += generate_equal(ans)


def write_longer(test_case_name, file_name, content):
    test_case = generate_test_case(test_case_name, 'Longer', init_content + content)
    output = open(file_name, 'w')
    output.write(generate_header())
    output.write(test_case)
    output.close()


write_longer('Addition', 'addition_longer.h', addition_content)
write_longer('Subtraction', 'subtraction_longer.h', subtraction_content)
write_longer('Multiple', 'multiple_longer.h', multiple_content)
write_longer('Division', 'division_longer.h', division_content)
