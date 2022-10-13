#! /usr/bin/python3
import os
import sys

result_filename = 'result.out'
tmp_filename = 'tmp.out'
os.chdir(sys.path[0])
testcases_base_dir = '../Compiler-Design-Implementation/testcases/sema/'
testcases = [
    input[2:-1]for input in open(testcases_base_dir+'judgelist.txt', 'r').readlines()]
# testcases_file_paths = [testcases_base_dir+rel_path[2:-1]
#                         for rel_path in testcases_file_names]
# print(testcases_file_paths)
with open(result_filename, 'w'):
    pass
testcase_number = len(testcases)
for i,testcase in enumerate(testcases):
    input_path = testcases_base_dir+testcase
    input_prog = open(input_path,'r').read()
    if input_prog.count('Verdict: Success'):
        cmd = 'antlr4-parse MxLexer.g4 MxParser.g4 prog -tree {} > {}'.format(
            input_path, tmp_filename)
        print("testing case:{} ({}/{})".format(testcase,i,testcase_number))
        os.system(cmd)
        output = open(tmp_filename, 'r').read()
        if output[:7] != '(prog:1'[:7]:
            with open(result_filename, 'a') as result_file:
                result_file.write(
                    'Case : {} Error\n{}\n<End of output>\n'.format(testcase, output))
