import os
import sys
import base64
os.chdir(sys.path[0])

builtin_file = "../../runtime/builtin.s"
tar_file = "builtin.h"
builtin_ctx = open(builtin_file, 'r').read()
# print(builtin_ctx.encode())
# with open(tar_file, 'w') as F:
#     print(builtin_ctx.encode(), file=F)
#     print('\b', file=F)
encoded_ctx = builtin_ctx.encode(
    'unicode-escape').decode('utf8').replace("\"", "\\\"")
# print('\n'.encode('unicode-escape').decode('utf8'))
output_ctx = """
#pragma once
const char* kBuiltinASM = "{}";""".format(encoded_ctx)
print(output_ctx, file=open(tar_file, 'w'))
