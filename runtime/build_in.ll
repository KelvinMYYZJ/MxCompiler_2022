%struct.string = type { i8*, i32}

declare  i8* @_Znam(i64)
declare  i8* @_Znwm(i64)
declare  i8* @malloc(i64)

define i8* @__Malloc_array(i32 %len){
block0:
  %len_64 = sext i32 %len to i64
  %size = mul nsw i64 %len_64, 16
  %call = call i8* @_Znam(i64 %size) 
  ret i8* %call
}

define i8* @__Malloc_int(i32 %len){
block0:
  %len_64 = sext i32 %len to i64
  %size = mul nsw i64 %len_64, 4
  %call = call i8* @_Znam(i64 %size) 
  ret i8* %call
}

define i8* @__Malloc_bool(i32 %len){
block0:
  %len_64 = sext i32 %len to i64
  %call = call i8* @_Znam(i64 %len_64) 
  ret i8* %call
}

define i8* @__Malloc_ptr(i32 %len){
block0:
  %len_64 = sext i32 %len to i64
  %size = mul nsw i64 %len_64, 8
  %call = call i8* @_Znam(i64 %size) 
  ret i8* %call
}

declare i32 @printf(i8*, ...) 

@.str__print_format = global [3 x i8] c"%s\00"
define void @print(%struct.string * %0) {
block0:
  %1 = getelementptr inbounds %struct.string, %struct.string* %0, i32 0, i32 0
  %2 = load i8*, i8** %1
  %3 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @.str__print_format, i64 0, i64 0), i8* %2)
  ret void
}

@.str__println_format= global [4 x i8] c"%s\0A\00"
define void @println(%struct.string * %0){
block0:
  %1 = getelementptr inbounds %struct.string, %struct.string* %0, i32 0, i32 0
  %2 = load i8*, i8** %1
  %3 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @.str__println_format, i64 0, i64 0), i8* %2)
  ret void
}

define void @printInt(i32 %0){
block0:
  %1 = call %struct.string* @toString(i32 %0)
  call void @print(%struct.string* %1)
  ret void
}


define void @printlnInt(i32 %0){
block0:
  %1 = call %struct.string* @toString(i32 %0)
  call void @println(%struct.string* %1)
  ret void
}

declare i32 @sprintf(i8* , i8* , ...)
declare i64 @strlen(i8*)

@.str__toString_format = global [3 x i8] c"%d\00"
define %struct.string* @toString(i32 %0) {
  %2 = alloca i32
  %3 = alloca i8*
  %4 = alloca %struct.string*
  store i32 %0, i32* %2
  %5 = call i8* @_Znam(i64 11) 
  store i8* %5, i8** %3
  %6 = load i8*, i8** %3
  %7 = load i32, i32* %2
  %8 = call i32 (i8*, i8*, ...) @sprintf(i8* %6, i8* getelementptr inbounds ([3 x i8], [3 x i8]* @.str__toString_format, i64 0, i64 0), i32 %7) 
  %9 = call i8* @_Znwm(i64 16)
  %10 = bitcast i8* %9 to %struct.string*
  store %struct.string* %10, %struct.string** %4
  %11 = load i8*, i8** %3
  %12 = load %struct.string*, %struct.string** %4
  %13 = getelementptr inbounds %struct.string, %struct.string* %12, i32 0, i32 0
  store i8* %11, i8** %13
  %14 = load i8*, i8** %3
  %15 = call i64 @strlen(i8* %14) 
  %16 = trunc i64 %15 to i32
  %17 = load %struct.string*, %struct.string** %4
  %18 = getelementptr inbounds %struct.string, %struct.string* %17, i32 0, i32 1
  store i32 %16, i32* %18
  %19 = load %struct.string*, %struct.string** %4
  ret %struct.string* %19
}

define %struct.string* @getString() {
entry:
  %ret = alloca %struct.string*, align 8
  %call = call noalias nonnull i8* @_Znwm(i64 16) #8
  %0 = bitcast i8* %call to %struct.string*
  store %struct.string* %0, %struct.string** %ret, align 8
  %call1 = call noalias nonnull i8* @_Znam(i64 256) #8
  %1 = load %struct.string*, %struct.string** %ret, align 8
  %val = getelementptr inbounds %struct.string, %struct.string* %1, i32 0, i32 0
  store i8* %call1, i8** %val, align 8
  %2 = load %struct.string*, %struct.string** %ret, align 8
  %val2 = getelementptr inbounds %struct.string, %struct.string* %2, i32 0, i32 0
  %3 = load i8*, i8** %val2, align 8
  %call3 = call i32 (i8*, ...) @__isoc99_scanf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @.str__print_format, i64 0, i64 0), i8* %3)
  %4 = load %struct.string*, %struct.string** %ret, align 8
  %val4 = getelementptr inbounds %struct.string, %struct.string* %4, i32 0, i32 0
  %5 = load i8*, i8** %val4, align 8
  %call5 = call i64 @strlen(i8* %5) #9
  %conv = trunc i64 %call5 to i32
  %6 = load %struct.string*, %struct.string** %ret, align 8
  %size = getelementptr inbounds %struct.string, %struct.string* %6, i32 0, i32 1
  store i32 %conv, i32* %size, align 8
  %7 = load %struct.string*, %struct.string** %ret, align 8
  ret %struct.string* %7
}

declare i32 @__isoc99_scanf(i8*, ...)
define i32 @getInt(){
  %1 = alloca i32
  %2 = call i32 (i8*, ...) @__isoc99_scanf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @.str__toString_format, i64 0, i64 0), i32* %1)
  %3 = load i32, i32* %1
  ret i32 %3
}

define i32 @string.length(%struct.string* %this){
block0:
  %size_ptr = getelementptr inbounds %struct.string, %struct.string* %this, i32 0, i32 1
  %size = load i32, i32* %size_ptr
  ret i32 %size
}

declare i32 @__isoc99_sscanf(i8*, i8*, ...)
define i32 @string.parseInt(%struct.string* %this){
  %ret_ptr = alloca i32
  %val_ptr = getelementptr inbounds %struct.string, %struct.string* %this, i32 0, i32 0
  %val = load i8*, i8** %val_ptr
  %tmp = call i32 (i8*, i8*, ...) @__isoc99_sscanf(i8* %val, i8* getelementptr inbounds ([3 x i8], [3 x i8]* @.str__toString_format, i64 0, i64 0), i32* %ret_ptr)
  %ret = load i32, i32* %ret_ptr
  ret i32 %ret
}

define i32 @string.ord(%struct.string* %this, i32 %pos){
  %val_ptr = getelementptr inbounds %struct.string, %struct.string* %this, i32 0, i32 0
  %val = load i8*, i8** %val_ptr
  %ch_ptr = getelementptr inbounds i8, i8* %val, i32 %pos
  %ch = load i8, i8* %ch_ptr
  %ret = sext i8 %ch to i32
  ret i32 %ret
}

declare i8* @strncpy(i8*, i8*, i64)

define %struct.string* @string.substring(%struct.string* %this, i32 %left, i32 %right){
  %val_ptr = getelementptr inbounds %struct.string, %struct.string* %this, i32 0, i32 0
  %val = load i8*, i8** %val_ptr
  %st_pos = getelementptr inbounds i8, i8* %val, i32 %left
  %new_len = sub nsw i32 %right, %left
  %new_len_64 = sext i32 %new_len to i64
  %real_new_len = add nsw i32 %new_len, 1
  %real_new_len_64 = sext i32 %real_new_len to i64
  %ret_val = call i8* @_Znam(i64 %real_new_len_64)
  %call = call i8* @strncpy(i8* %ret_val, i8* %st_pos, i64 %new_len_64)
  %ret_tmp = call i8* @_Znwm(i64 16) 
  %ret = bitcast i8* %ret_tmp to %struct.string*
  %ret_val_ptr = getelementptr inbounds %struct.string, %struct.string* %ret, i32 0, i32 0
  %ret_size_ptr = getelementptr inbounds %struct.string, %struct.string* %ret, i32 0, i32 1
  store i32 %new_len, i32* %ret_size_ptr
  store i8* %ret_val, i8** %ret_val_ptr
  ret %struct.string* %ret
}

declare i32 @strcmp(i8*, i8*)

define i1 @string.lt(%struct.string* %lhs, %struct.string* %rhs){
  %lhs_val_ptr = getelementptr inbounds %struct.string, %struct.string* %lhs, i32 0, i32 0
  %lhs_val = load i8*, i8** %lhs_val_ptr
  %rhs_val_ptr = getelementptr inbounds %struct.string, %struct.string* %rhs, i32 0, i32 0
  %rhs_val = load i8*, i8** %rhs_val_ptr
  %result = call i32 @strcmp(i8* %rhs_val, i8* %lhs_val)
  %ret = icmp eq i32 %result, 1
  ret i1 %ret
}

define i1 @string.le(%struct.string* %lhs, %struct.string* %rhs){
  %lhs_val_ptr = getelementptr inbounds %struct.string, %struct.string* %lhs, i32 0, i32 0
  %lhs_val = load i8*, i8** %lhs_val_ptr
  %rhs_val_ptr = getelementptr inbounds %struct.string, %struct.string* %rhs, i32 0, i32 0
  %rhs_val = load i8*, i8** %rhs_val_ptr
  %result = call i32 @strcmp(i8* %lhs_val, i8* %rhs_val)
  %ret = icmp ne i32 %result, 1
  ret i1 %ret
}

define i1 @string.eq(%struct.string* %lhs, %struct.string* %rhs){
  %lhs_val_ptr = getelementptr inbounds %struct.string, %struct.string* %lhs, i32 0, i32 0
  %lhs_val = load i8*, i8** %lhs_val_ptr
  %rhs_val_ptr = getelementptr inbounds %struct.string, %struct.string* %rhs, i32 0, i32 0
  %rhs_val = load i8*, i8** %rhs_val_ptr
  %result = call i32 @strcmp(i8* %rhs_val, i8* %lhs_val)
  %ret = icmp eq i32 %result, 0
  ret i1 %ret
}

define i1 @string.neq(%struct.string* %lhs, %struct.string* %rhs){
  %lhs_val_ptr = getelementptr inbounds %struct.string, %struct.string* %lhs, i32 0, i32 0
  %lhs_val = load i8*, i8** %lhs_val_ptr
  %rhs_val_ptr = getelementptr inbounds %struct.string, %struct.string* %rhs, i32 0, i32 0
  %rhs_val = load i8*, i8** %rhs_val_ptr
  %result = call i32 @strcmp(i8* %rhs_val, i8* %lhs_val)
  %ret = icmp eq i32 %result, 0
  ret i1 %ret
}

@.str__string_add_format = global [5 x i8] c"%s%s\00"

define %struct.string* @string.add(%struct.string* %lhs, %struct.string* %rhs){
  %lhs_val_ptr = getelementptr inbounds %struct.string, %struct.string* %lhs, i32 0, i32 0
  %lhs_val = load i8*, i8** %lhs_val_ptr
  %lhs_size_ptr = getelementptr inbounds %struct.string, %struct.string* %lhs, i32 0, i32 1
  %lhs_size = load i32, i32* %lhs_size_ptr
  %rhs_val_ptr = getelementptr inbounds %struct.string, %struct.string* %rhs, i32 0, i32 0
  %rhs_val = load i8*, i8** %rhs_val_ptr
  %rhs_size_ptr = getelementptr inbounds %struct.string, %struct.string* %rhs, i32 0, i32 1
  %rhs_size = load i32, i32* %rhs_size_ptr
  %ret_size = add nsw i32 %lhs_size, %rhs_size
  %ret_real_size = add nsw i32 %ret_size, 1
  %ret_real_size_64 = sext i32 %ret_real_size to i64
  %ret_val = call i8* @_Znam(i64 %ret_real_size_64)
  %call = call i32 (i8*, i8*, ...) @sprintf(i8* %ret_val, i8* getelementptr inbounds ([5 x i8], [5 x i8]* @.str__string_add_format, i64 0, i64 0), i8* %lhs_val, i8* %rhs_val)
  %ret_tmp = call i8* @_Znwm(i64 16) 
  %ret = bitcast i8* %ret_tmp to %struct.string*
  %ret_val_ptr = getelementptr inbounds %struct.string, %struct.string* %ret, i32 0, i32 0
  %ret_size_ptr = getelementptr inbounds %struct.string, %struct.string* %ret, i32 0, i32 1
  store i32 %ret_size, i32* %ret_size_ptr
  store i8* %ret_val, i8** %ret_val_ptr
  ret %struct.string* %ret
}

; @.str_test = global [4 x i8] c"abc\00" 
; define i32 @main(){
; block0:
;   %0 = getelementptr inbounds [4 x i8], [4 x i8]* @.str_test
;   %1 = bitcast [4 x i8]* @.str_test to i8*
;   %2 = alloca %struct.string
;   %3 = getelementptr inbounds %struct.string, %struct.string* %2, i32 0, i32 0
;   store i8* %1, i8** %3  
;   ; %4 = call %struct.string* @toString(i32 123123)
;   ; %4 = call %struct.string* @getString()
;   %4 = call i32 @getInt()
;   %5 = call %struct.string* @toString(i32 %4)
;   call void @println(%struct.string* %5)
;   call void @printInt(i32 %4)
;   call void @printlnInt(i32 %4)
;   ret i32 0
; }