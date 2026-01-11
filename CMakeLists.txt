cmake_minimum_required(VERSION 3.10)

project(MyApp)

# すべてのソースファイルを収集
file(GLOB_RECURSE SOURCES "C_core/src/**/*.c")

add_executable(my_app ./C_core/main.c ${SOURCES} ./generated/weight.c)

# インクルードディレクトリを指定
target_include_directories(my_app PRIVATE C_core/include)