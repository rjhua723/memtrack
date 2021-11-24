CXX = clang++
CXXFLAGS = -g -Wall -Wextra -pedantic -fno-omit-frame-pointer -target x86_64-pc-windows-gnu -fsanitize=address -fno-omit-frame-pointer -fsanitize=undefined -std=c++2b
c = clang
.PHONY: all run mingw clean rebuild
src =
addFolder = 
cppName = main
exe = main.exe

all: build/$(c)/$(exe)
run: build/$(c)/$(exe)
	./build/$(c)/$(exe)
mingw: CXX = g++
mingw: CXXFLAGS = -g -pedantic -Wall -Wextra -std=c++2b --coverage
mingw: all
clean: cleanlinux
rebuild: cleanlinux mingw
build/$(c)/$(exe): build/$(c)/$(cppName).o
	$(CXX) $(CXXFLAGS) $< -o $@
build/$(c)/$(cppName).o: $(cppName).cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@
rebuildwindows: cleanwindows build/$(c)/$(exe)
cleanwindows:
	del build\*.o build\*.exe  build\*.ilk build\*.pdb build\*.lib build\*.exp build\*.gcda build\*.gcno 
cleanlinux:
	rm -rf ./build/clang/* ./build/gcc/*