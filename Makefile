# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.0

# Default target executed when no arguments are given to make.
default_target: all
.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:
.PHONY : .NOTPARALLEL

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list

# Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.0.1/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.0.1/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/jonesax/Projects/qtile

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/jonesax/Projects/qtile

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake cache editor..."
	/usr/local/Cellar/cmake/3.0.1/bin/ccmake -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache
.PHONY : edit_cache/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/local/Cellar/cmake/3.0.1/bin/cmake -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache
.PHONY : rebuild_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /Users/jonesax/Projects/qtile/CMakeFiles /Users/jonesax/Projects/qtile/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /Users/jonesax/Projects/qtile/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean
.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named qtile

# Build rule for target.
qtile: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 qtile
.PHONY : qtile

# fast build rule for target.
qtile/fast:
	$(MAKE) -f CMakeFiles/qtile.dir/build.make CMakeFiles/qtile.dir/build
.PHONY : qtile/fast

src/cartographer.o: src/cartographer.cpp.o
.PHONY : src/cartographer.o

# target to build an object file
src/cartographer.cpp.o:
	$(MAKE) -f CMakeFiles/qtile.dir/build.make CMakeFiles/qtile.dir/src/cartographer.cpp.o
.PHONY : src/cartographer.cpp.o

src/cartographer.i: src/cartographer.cpp.i
.PHONY : src/cartographer.i

# target to preprocess a source file
src/cartographer.cpp.i:
	$(MAKE) -f CMakeFiles/qtile.dir/build.make CMakeFiles/qtile.dir/src/cartographer.cpp.i
.PHONY : src/cartographer.cpp.i

src/cartographer.s: src/cartographer.cpp.s
.PHONY : src/cartographer.s

# target to generate assembly for a file
src/cartographer.cpp.s:
	$(MAKE) -f CMakeFiles/qtile.dir/build.make CMakeFiles/qtile.dir/src/cartographer.cpp.s
.PHONY : src/cartographer.cpp.s

src/gameworld.o: src/gameworld.cpp.o
.PHONY : src/gameworld.o

# target to build an object file
src/gameworld.cpp.o:
	$(MAKE) -f CMakeFiles/qtile.dir/build.make CMakeFiles/qtile.dir/src/gameworld.cpp.o
.PHONY : src/gameworld.cpp.o

src/gameworld.i: src/gameworld.cpp.i
.PHONY : src/gameworld.i

# target to preprocess a source file
src/gameworld.cpp.i:
	$(MAKE) -f CMakeFiles/qtile.dir/build.make CMakeFiles/qtile.dir/src/gameworld.cpp.i
.PHONY : src/gameworld.cpp.i

src/gameworld.s: src/gameworld.cpp.s
.PHONY : src/gameworld.s

# target to generate assembly for a file
src/gameworld.cpp.s:
	$(MAKE) -f CMakeFiles/qtile.dir/build.make CMakeFiles/qtile.dir/src/gameworld.cpp.s
.PHONY : src/gameworld.cpp.s

src/qtile.o: src/qtile.cpp.o
.PHONY : src/qtile.o

# target to build an object file
src/qtile.cpp.o:
	$(MAKE) -f CMakeFiles/qtile.dir/build.make CMakeFiles/qtile.dir/src/qtile.cpp.o
.PHONY : src/qtile.cpp.o

src/qtile.i: src/qtile.cpp.i
.PHONY : src/qtile.i

# target to preprocess a source file
src/qtile.cpp.i:
	$(MAKE) -f CMakeFiles/qtile.dir/build.make CMakeFiles/qtile.dir/src/qtile.cpp.i
.PHONY : src/qtile.cpp.i

src/qtile.s: src/qtile.cpp.s
.PHONY : src/qtile.s

# target to generate assembly for a file
src/qtile.cpp.s:
	$(MAKE) -f CMakeFiles/qtile.dir/build.make CMakeFiles/qtile.dir/src/qtile.cpp.s
.PHONY : src/qtile.cpp.s

src/tilemap.o: src/tilemap.cpp.o
.PHONY : src/tilemap.o

# target to build an object file
src/tilemap.cpp.o:
	$(MAKE) -f CMakeFiles/qtile.dir/build.make CMakeFiles/qtile.dir/src/tilemap.cpp.o
.PHONY : src/tilemap.cpp.o

src/tilemap.i: src/tilemap.cpp.i
.PHONY : src/tilemap.i

# target to preprocess a source file
src/tilemap.cpp.i:
	$(MAKE) -f CMakeFiles/qtile.dir/build.make CMakeFiles/qtile.dir/src/tilemap.cpp.i
.PHONY : src/tilemap.cpp.i

src/tilemap.s: src/tilemap.cpp.s
.PHONY : src/tilemap.s

# target to generate assembly for a file
src/tilemap.cpp.s:
	$(MAKE) -f CMakeFiles/qtile.dir/build.make CMakeFiles/qtile.dir/src/tilemap.cpp.s
.PHONY : src/tilemap.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... qtile"
	@echo "... rebuild_cache"
	@echo "... src/cartographer.o"
	@echo "... src/cartographer.i"
	@echo "... src/cartographer.s"
	@echo "... src/gameworld.o"
	@echo "... src/gameworld.i"
	@echo "... src/gameworld.s"
	@echo "... src/qtile.o"
	@echo "... src/qtile.i"
	@echo "... src/qtile.s"
	@echo "... src/tilemap.o"
	@echo "... src/tilemap.i"
	@echo "... src/tilemap.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

