CXX = clang++
CXXFLAGS = -g -Wall -Wextra -pedantic -fno-omit-frame-pointer -target x86_64-pc-windows-gnu -fsanitize=address -fno-omit-frame-pointer -fsanitize=undefined
.PHONY: all run mingw clean rebuild
src = .
addFolder = 
cppName = main
exe = main.exe

all: build/$(exe)
run: build/$(exe)
	./build/$(exe)
mingw: CXX = g++
mingw: CXXFLAGS = -g -pedantic -Wall -Wextra -std=c++2a --coverage
mingw: all
clean: cleanlinux
rebuild: cleanlinux mingw
build/$(exe): build/$(cppName).o
	$(CXX) $(CXXFLAGS) $< -o $@
build/$(cppName).o: $(src)/$(cppName).cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@
rebuildwindows: cleanwindows build/$(exe)
cleanwindows:
	del build\*.o build\*.exe  build\*.ilk build\*.pdb build\*.lib build\*.exp build\*.gcda build\*.gcno 
cleanlinux:
	rm -f ./build/*.o ./build/*.exe ./build/*.ilk ./build/*.pdb ./build/*.lib ./build/*.exp build/*.gcda build/*.gcno 