# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

# Default target executed when no arguments are given to make.
default_target: all

.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:


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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/artix41/Programmation/Genetics/traveler

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/artix41/Programmation/Genetics/traveler

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "No interactive CMake dialog available..."
	/usr/bin/cmake -E echo No\ interactive\ CMake\ dialog\ available.
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/artix41/Programmation/Genetics/traveler/CMakeFiles /home/artix41/Programmation/Genetics/traveler/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/artix41/Programmation/Genetics/traveler/CMakeFiles 0
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
# Target rules for targets named myproject

# Build rule for target.
myproject: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 myproject
.PHONY : myproject

# fast build rule for target.
myproject/fast:
	$(MAKE) -f CMakeFiles/myproject.dir/build.make CMakeFiles/myproject.dir/build
.PHONY : myproject/fast

src/AbstractState.o: src/AbstractState.cpp.o

.PHONY : src/AbstractState.o

# target to build an object file
src/AbstractState.cpp.o:
	$(MAKE) -f CMakeFiles/myproject.dir/build.make CMakeFiles/myproject.dir/src/AbstractState.cpp.o
.PHONY : src/AbstractState.cpp.o

src/AbstractState.i: src/AbstractState.cpp.i

.PHONY : src/AbstractState.i

# target to preprocess a source file
src/AbstractState.cpp.i:
	$(MAKE) -f CMakeFiles/myproject.dir/build.make CMakeFiles/myproject.dir/src/AbstractState.cpp.i
.PHONY : src/AbstractState.cpp.i

src/AbstractState.s: src/AbstractState.cpp.s

.PHONY : src/AbstractState.s

# target to generate assembly for a file
src/AbstractState.cpp.s:
	$(MAKE) -f CMakeFiles/myproject.dir/build.make CMakeFiles/myproject.dir/src/AbstractState.cpp.s
.PHONY : src/AbstractState.cpp.s

src/AnimationState.o: src/AnimationState.cpp.o

.PHONY : src/AnimationState.o

# target to build an object file
src/AnimationState.cpp.o:
	$(MAKE) -f CMakeFiles/myproject.dir/build.make CMakeFiles/myproject.dir/src/AnimationState.cpp.o
.PHONY : src/AnimationState.cpp.o

src/AnimationState.i: src/AnimationState.cpp.i

.PHONY : src/AnimationState.i

# target to preprocess a source file
src/AnimationState.cpp.i:
	$(MAKE) -f CMakeFiles/myproject.dir/build.make CMakeFiles/myproject.dir/src/AnimationState.cpp.i
.PHONY : src/AnimationState.cpp.i

src/AnimationState.s: src/AnimationState.cpp.s

.PHONY : src/AnimationState.s

# target to generate assembly for a file
src/AnimationState.cpp.s:
	$(MAKE) -f CMakeFiles/myproject.dir/build.make CMakeFiles/myproject.dir/src/AnimationState.cpp.s
.PHONY : src/AnimationState.cpp.s

src/CreateGraphState.o: src/CreateGraphState.cpp.o

.PHONY : src/CreateGraphState.o

# target to build an object file
src/CreateGraphState.cpp.o:
	$(MAKE) -f CMakeFiles/myproject.dir/build.make CMakeFiles/myproject.dir/src/CreateGraphState.cpp.o
.PHONY : src/CreateGraphState.cpp.o

src/CreateGraphState.i: src/CreateGraphState.cpp.i

.PHONY : src/CreateGraphState.i

# target to preprocess a source file
src/CreateGraphState.cpp.i:
	$(MAKE) -f CMakeFiles/myproject.dir/build.make CMakeFiles/myproject.dir/src/CreateGraphState.cpp.i
.PHONY : src/CreateGraphState.cpp.i

src/CreateGraphState.s: src/CreateGraphState.cpp.s

.PHONY : src/CreateGraphState.s

# target to generate assembly for a file
src/CreateGraphState.cpp.s:
	$(MAKE) -f CMakeFiles/myproject.dir/build.make CMakeFiles/myproject.dir/src/CreateGraphState.cpp.s
.PHONY : src/CreateGraphState.cpp.s

src/Display.o: src/Display.cpp.o

.PHONY : src/Display.o

# target to build an object file
src/Display.cpp.o:
	$(MAKE) -f CMakeFiles/myproject.dir/build.make CMakeFiles/myproject.dir/src/Display.cpp.o
.PHONY : src/Display.cpp.o

src/Display.i: src/Display.cpp.i

.PHONY : src/Display.i

# target to preprocess a source file
src/Display.cpp.i:
	$(MAKE) -f CMakeFiles/myproject.dir/build.make CMakeFiles/myproject.dir/src/Display.cpp.i
.PHONY : src/Display.cpp.i

src/Display.s: src/Display.cpp.s

.PHONY : src/Display.s

# target to generate assembly for a file
src/Display.cpp.s:
	$(MAKE) -f CMakeFiles/myproject.dir/build.make CMakeFiles/myproject.dir/src/Display.cpp.s
.PHONY : src/Display.cpp.s

src/algo_genetique.o: src/algo_genetique.cpp.o

.PHONY : src/algo_genetique.o

# target to build an object file
src/algo_genetique.cpp.o:
	$(MAKE) -f CMakeFiles/myproject.dir/build.make CMakeFiles/myproject.dir/src/algo_genetique.cpp.o
.PHONY : src/algo_genetique.cpp.o

src/algo_genetique.i: src/algo_genetique.cpp.i

.PHONY : src/algo_genetique.i

# target to preprocess a source file
src/algo_genetique.cpp.i:
	$(MAKE) -f CMakeFiles/myproject.dir/build.make CMakeFiles/myproject.dir/src/algo_genetique.cpp.i
.PHONY : src/algo_genetique.cpp.i

src/algo_genetique.s: src/algo_genetique.cpp.s

.PHONY : src/algo_genetique.s

# target to generate assembly for a file
src/algo_genetique.cpp.s:
	$(MAKE) -f CMakeFiles/myproject.dir/build.make CMakeFiles/myproject.dir/src/algo_genetique.cpp.s
.PHONY : src/algo_genetique.cpp.s

src/individual.o: src/individual.cpp.o

.PHONY : src/individual.o

# target to build an object file
src/individual.cpp.o:
	$(MAKE) -f CMakeFiles/myproject.dir/build.make CMakeFiles/myproject.dir/src/individual.cpp.o
.PHONY : src/individual.cpp.o

src/individual.i: src/individual.cpp.i

.PHONY : src/individual.i

# target to preprocess a source file
src/individual.cpp.i:
	$(MAKE) -f CMakeFiles/myproject.dir/build.make CMakeFiles/myproject.dir/src/individual.cpp.i
.PHONY : src/individual.cpp.i

src/individual.s: src/individual.cpp.s

.PHONY : src/individual.s

# target to generate assembly for a file
src/individual.cpp.s:
	$(MAKE) -f CMakeFiles/myproject.dir/build.make CMakeFiles/myproject.dir/src/individual.cpp.s
.PHONY : src/individual.cpp.s

src/main.o: src/main.cpp.o

.PHONY : src/main.o

# target to build an object file
src/main.cpp.o:
	$(MAKE) -f CMakeFiles/myproject.dir/build.make CMakeFiles/myproject.dir/src/main.cpp.o
.PHONY : src/main.cpp.o

src/main.i: src/main.cpp.i

.PHONY : src/main.i

# target to preprocess a source file
src/main.cpp.i:
	$(MAKE) -f CMakeFiles/myproject.dir/build.make CMakeFiles/myproject.dir/src/main.cpp.i
.PHONY : src/main.cpp.i

src/main.s: src/main.cpp.s

.PHONY : src/main.s

# target to generate assembly for a file
src/main.cpp.s:
	$(MAKE) -f CMakeFiles/myproject.dir/build.make CMakeFiles/myproject.dir/src/main.cpp.s
.PHONY : src/main.cpp.s

src/path.o: src/path.cpp.o

.PHONY : src/path.o

# target to build an object file
src/path.cpp.o:
	$(MAKE) -f CMakeFiles/myproject.dir/build.make CMakeFiles/myproject.dir/src/path.cpp.o
.PHONY : src/path.cpp.o

src/path.i: src/path.cpp.i

.PHONY : src/path.i

# target to preprocess a source file
src/path.cpp.i:
	$(MAKE) -f CMakeFiles/myproject.dir/build.make CMakeFiles/myproject.dir/src/path.cpp.i
.PHONY : src/path.cpp.i

src/path.s: src/path.cpp.s

.PHONY : src/path.s

# target to generate assembly for a file
src/path.cpp.s:
	$(MAKE) -f CMakeFiles/myproject.dir/build.make CMakeFiles/myproject.dir/src/path.cpp.s
.PHONY : src/path.cpp.s

src/population.o: src/population.cpp.o

.PHONY : src/population.o

# target to build an object file
src/population.cpp.o:
	$(MAKE) -f CMakeFiles/myproject.dir/build.make CMakeFiles/myproject.dir/src/population.cpp.o
.PHONY : src/population.cpp.o

src/population.i: src/population.cpp.i

.PHONY : src/population.i

# target to preprocess a source file
src/population.cpp.i:
	$(MAKE) -f CMakeFiles/myproject.dir/build.make CMakeFiles/myproject.dir/src/population.cpp.i
.PHONY : src/population.cpp.i

src/population.s: src/population.cpp.s

.PHONY : src/population.s

# target to generate assembly for a file
src/population.cpp.s:
	$(MAKE) -f CMakeFiles/myproject.dir/build.make CMakeFiles/myproject.dir/src/population.cpp.s
.PHONY : src/population.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... rebuild_cache"
	@echo "... myproject"
	@echo "... src/AbstractState.o"
	@echo "... src/AbstractState.i"
	@echo "... src/AbstractState.s"
	@echo "... src/AnimationState.o"
	@echo "... src/AnimationState.i"
	@echo "... src/AnimationState.s"
	@echo "... src/CreateGraphState.o"
	@echo "... src/CreateGraphState.i"
	@echo "... src/CreateGraphState.s"
	@echo "... src/Display.o"
	@echo "... src/Display.i"
	@echo "... src/Display.s"
	@echo "... src/algo_genetique.o"
	@echo "... src/algo_genetique.i"
	@echo "... src/algo_genetique.s"
	@echo "... src/individual.o"
	@echo "... src/individual.i"
	@echo "... src/individual.s"
	@echo "... src/main.o"
	@echo "... src/main.i"
	@echo "... src/main.s"
	@echo "... src/path.o"
	@echo "... src/path.i"
	@echo "... src/path.s"
	@echo "... src/population.o"
	@echo "... src/population.i"
	@echo "... src/population.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

