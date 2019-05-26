# CMake 最低版本号要求
cmake_minimum_required (VERSION 2.8)
# 项目信息
project (Demo1)
set(TestFlag 1)
message("TestFlag = ${TestFlag}")
message("PATH = $ENV{PATH}")

#VAR
message("-------------------------------")
set(VAR 1)
message("VAR = ${VAR}")
set(listVAR 1 1 1)
message("listVAR = ${listVAR}")

#for
message("-------------------------------")
set(VAR a b c)
foreach(f ${VAR})
  message("for ${f}")
endforeach()

#while
message("-------------------------------")
set(VAR 5)
while(${VAR} GREATER 0)
  message("while ${VAR}")
  math(EXPR VAR "${VAR} - 1")
endwhile()

#macro function
message("-------------------------------")
macro(hellomacro MESSAGE)
  message("hellomacro:${MESSAGE}")
endmacro()

function(hellofunction MESSAGE)
  message("hellofunction:${MESSAGE}")
endfunction()

hellomacro("hello 1")
hellofunction("hello 2")

message("-------------------------------")
macro(hellomacro2 BASE)
	message("hellomacro2: ${BASE}")
	set(BASE "macro")
endmacro()

function(hellofunction2 BASE)
  message("hellofunction2: ${BASE}")
  set(BASE "function")
  message("hellofunction2 after: ${BASE}")
endfunction()

set(BASE "None")
message("before hellomacro2 BASE = ${BASE}")
hellomacro2(BASE)
message("before hellofunction2 BASE = ${BASE}")
hellofunction2(BASE)
message("after hellofunction2 BASE = ${BASE}")

message("-------------------------------")
macro(hellomacro3 ARG)
  message("hellomacro3: ${ARG}")
  set(${ARG} "macro")
endmacro()

function(hellofunction3 ARG)
  message("hellofunction2: ${ARG}")
  set(${ARG} "function" PARENT_SCOPE)
  message("hellofunction2 after: ${ARG}")
endfunction()

set(BASE "None")
message("before hellomacro3 BASE = ${BASE}")
hellomacro3(BASE)
message("before hellofunction3 BASE = ${BASE}")
hellofunction3(BASE)
message("after hellofunction3 BASE = ${BASE}")

message("-------------------------------")
set(GLOBAL "Global")
set(LOCAL "Global")
function(hellofunction3)
  set(LOCAL "Local")
  message("hellofunction3 GLOBAL:${GLOBAL} LOCAL:${LOCAL}")
endfunction()
hellofunction3()
message("hellofunction3 out GLOBAL:${GLOBAL} LOCAL:${LOCAL}")
message("-------------------------------")
