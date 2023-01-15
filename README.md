# MxCompiler_2022
By Kelvin_MYYZJ

## Codegen

### IR design
#### Object
| Mx* language                      | llvm IR object                   |
| :-------------------------------- | :------------------------------- |
| int                               | i32                              |
| char                              | i8                               |
| bool                              | i8                               |
| class_object(including string)  T | T*                               |
| int array int [] a                | _array_int_1{int size;int *ptr;} |
| array T[ ]                        | _array_T_1                       |
| array T[ ][ ][ ]                  | _array_T_3                       |

#### Function: 
The function `_Global_Init_()` is used to initalize all the global varibles and is called at the begining of `main()`
A class `T` with a member function `func(arg0,arg1,...)` is called `T_func(arg_this,arg0,arg1...)`.
The construct function of class `T` is called `T_Init_(arg_this)`

### Assembly Design (only a draft now)
- Without register allocation, which means I store all the virtual registers(including function arguments) on stack.