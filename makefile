buildFolder = clang
CXX = clang++
CXXFLAGS = -g -Wall -Wextra -pedantic -fno-omit-frame-pointer -target x86_64-pc-windows-gnu -fsanitize=address -fno-omit-frame-pointer -fsanitize=undefined -std=c++2b
.PHONY: all run mingw clean rebuild
src = .
addFolder = 
cppName = main
exe = main.exe

all: build/$(buildFolder)/$(exe)
run: build/$(buildFolder)/$(exe)
	./build/$(buildFolder)/$(exe)
mingw: CXX = g++
mingw: CXXFLAGS = -g -pedantic -Wall -Wextra -std=c++2b --coverage
mingw: buildFolder = gcc
mingw: build/$(buildFolder)/$(exe)
clean: cleanlinux
rebuild: cleanlinux mingw
build/$(buildFolder)/$(exe): build/$(buildFolder)/$(cppName).o
	$(CXX) $(CXXFLAGS) $< -o $@
build/$(buildFolder)/$(cppName).o: $(src)/$(cppName).cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@
rebuildwindows: cleanwindows build/$(buildFolder)/$(exe)
cleanwindows:
	del build\*.o build\*.exe  build\*.ilk build\*.pdb build\*.lib build\*.exp build\*.gcda build\*.gcno 
cleanlinux:
	rm -rf ./build/clang/* ./build/gcc/*