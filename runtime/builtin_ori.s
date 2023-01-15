	.text
	.align 2
	.globl __Malloc_array
__Malloc_array:
	lw a1,-4(sp)
	slli a0,a1,4
	tail malloc

	.globl __Malloc_int
__Malloc_int:
	lw a1,-4(sp)
	slli a0,a1,2
	tail malloc

	.globl __Malloc_bool
__Malloc_bool:
	lw a0,-4(sp)
	tail malloc

	.globl __Malloc_ptr
__Malloc_ptr:
	lw a1,-4(sp)
	slli a0,a1,3
	tail malloc

	.globl print
print:
	lw a0,-4(sp)
	lw a0,0(a0)
	tail printf

	.globl println
println:
	lw a0,-4(sp)
	lw a0,0(a0)
	tail puts

	.globl printInt
printInt:
	la a0,.str__printInt_format
	lw a1,-4(sp)
	tail printf

	.globl printlnInt
printlnInt:
	la a0,.str__printlnInt_format
	lw a1,-4(sp)
	tail printf

	.globl toString
toString:
	addi sp,sp,-12
	sw ra,4(sp)
	# malloc string
	li a0,8
	call malloc
	sw a0,0(sp)
	# malloc cstring
	li a0,11
	call malloc
	# store the cstring ptr into string
	lw a4,0(sp)
	sw a0,0(a4)
	# write into the cstring
	la a1,.str__printInt_format
	lw a2,8(sp)
	call sprintf
	# wirte length into string
	lw a4,0(sp)
	sw a0,4(a4)
	
	mv a0,a4
	lw ra,4(sp)
	addi sp,sp,12
	ret

	.globl getString
getString:
# int : 12(sp)
# ra : 8(sp)
# string : 4(sp)
# cstring : 0(sp)
	addi sp,sp,-16
	sw ra,8(sp)
	# malloc string
	li a0,8
	call malloc
	sw a0,4(sp)
	# malloc cstring
	li a0,256
	call malloc
	sw a0,0(sp)
	# store the cstring ptr into string
	lw a1,4(sp)
	sw a0,0(a1)
	# scan the cstring
	mv a1,a0
	la a0,.str__print_format
	call scanf
	# get and store length
	lw a0,0(sp)
	call strlen
	lw a1,4(sp)
	sw a0,4(a1)

	mv a0,a1
	lw ra,8(sp)
	addi sp,sp,16
	ret

	.globl getInt
getInt:
	addi sp,sp,-8
	sw ra,4(sp)
	la a0,.str__printInt_format
	addi a1,sp,0
	call scanf
	lw a0,0(sp)
	lw ra,4(sp)
	addi sp,sp,8
	ret

	.globl string.length
string.length:
	lw a0,-4(sp)
	lw a0,4(a0)
	ret

	.globl string.parseInt
string.parseInt:
	addi sp,sp,-8
	sw ra,0(sp)

	lw a0,4(sp)
	lw a0,0(a0)
	la a1,.str__printInt_format
	addi a2,sp,4
	call sscanf
	lw a0,4(sp)

	lw ra,0(sp)
	addi sp,sp,8
	ret

	.globl string.ord
string.ord:
	lw a0,-4(sp)
	lw a0,0(a0)
	lw a1,-8(sp)
	add a0,a0,a1
	lbu a0,0(a0)
	ret

	.globl string.substring
string.substring:
# complete string : 16(sp)
# left : 12(sp)
# right/len :8(sp)
# ra : 4(sp)
# new string : 0(sp)
	addi sp,sp,-20
	sw ra,4(sp)
	lw t1,8(sp)
	lw t2,12(sp)
	sub t0,t1,t2
	sw t0,8(sp)
	# malloc string
	li a0,8
	call malloc
	sw a0,0(sp)
	# malloc cstring
	lw a0,8(sp)
	addi a0,a0,1
	call malloc
	# memcpy into cstring
	lw a4,0(sp)
	sw a0,0(a4)
	lw a2,8(sp)
	sw a2,4(a4)
	lw a1,16(sp)
	lw a1,0(a1)
	lw t2,12(sp)
	add a1,a1,t2
	call memcpy

	lw a0,0(sp)
	lw ra,4(sp)
	addi sp,sp,20
	ret

	.globl string.lt
string.lt:
	lw a0,-4(sp)
	lw a0,0(a0)
	lw a1,-8(sp)
	lw a1,0(a1)
	addi sp,sp,-4
	sw ra,0(sp)
	call strcmp
	slti a0,a0,0
	lw ra,0(sp)
	addi sp,sp,4
	ret

	.globl string.le
string.le:
	lw a0,-4(sp)
	lw a0,0(a0)
	lw a1,-8(sp)
	lw a1,0(a1)
	addi sp,sp,-4
	sw ra,0(sp)
	call strcmp
	slti a0,a0,1
	lw ra,0(sp)
	addi sp,sp,4
	ret

	.globl string.eq
string.eq:
	lw a0,-4(sp)
	lw a0,0(a0)
	lw a1,-8(sp)
	lw a1,0(a1)
	addi sp,sp,-4
	sw ra,0(sp)
	call strcmp
	seqz a0,a0
	lw ra,0(sp)
	addi sp,sp,4
	ret

	.globl string.neq
string.neq:
	lw a0,-4(sp)
	lw a0,0(a0)
	lw a1,-8(sp)
	lw a1,0(a1)
	addi sp,sp,-4
	sw ra,0(sp)
	call strcmp
	snez a0,a0
	lw ra,0(sp)
	addi sp,sp,4
	ret

	.globl string.add
string.add:
# cstring1 : 16(sp)
# cstring2 : 12(sp)
# ra : 8(sp)
# new cstring : 4(sp)
# len.new string : 0(sp)
	addi sp,sp,-20
	sw ra,8(sp)
	lw a0,16(sp)
	lw t1,4(a0)
	lw a0,0(a0)
	sw a0,16(sp)
	lw a1,12(sp)
	lw t2,4(a1)
	lw a1,0(a1)
	sw a1,12(sp)
	add t0,t1,t2
	sw t0,0(sp)
	# malloc cstring
	addi a0,t0,1
	call malloc
	sw a0,4(sp)
	# malloc string
	li a0,8
	call malloc
	# store string info
	lw a1,4(sp)
	sw a1,0(a0)
	lw a2,0(sp)
	sw a2,4(a0)
	sw a0,0(sp)
	# copy string1
	mv a0,a1
	lw a1,16(sp)
	call strcpy
	# append string2
	lw a1,12(sp)
	call strcat
	lw a0,0(sp)
	lw ra,8(sp)
	addi sp,sp,20
	ret

	.section .rodata
.str__print_format:
	.string "%s"
.str__printInt_format:
	.string "%d"
.str__printlnInt_format:
	.string "%d\n"