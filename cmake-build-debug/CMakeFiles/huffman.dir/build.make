# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


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
CMAKE_COMMAND = /home/borisshapa/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/191.7141.37/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/borisshapa/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/191.7141.37/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/borisshapa/cpp-course/huffman

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/borisshapa/cpp-course/huffman/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/huffman.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/huffman.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/huffman.dir/flags.make

CMakeFiles/huffman.dir/main.cpp.o: CMakeFiles/huffman.dir/flags.make
CMakeFiles/huffman.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/borisshapa/cpp-course/huffman/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/huffman.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/huffman.dir/main.cpp.o -c /home/borisshapa/cpp-course/huffman/main.cpp

CMakeFiles/huffman.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/huffman.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/borisshapa/cpp-course/huffman/main.cpp > CMakeFiles/huffman.dir/main.cpp.i

CMakeFiles/huffman.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/huffman.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/borisshapa/cpp-course/huffman/main.cpp -o CMakeFiles/huffman.dir/main.cpp.s

CMakeFiles/huffman.dir/lib/encoder.cpp.o: CMakeFiles/huffman.dir/flags.make
CMakeFiles/huffman.dir/lib/encoder.cpp.o: ../lib/encoder.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/borisshapa/cpp-course/huffman/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/huffman.dir/lib/encoder.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/huffman.dir/lib/encoder.cpp.o -c /home/borisshapa/cpp-course/huffman/lib/encoder.cpp

CMakeFiles/huffman.dir/lib/encoder.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/huffman.dir/lib/encoder.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/borisshapa/cpp-course/huffman/lib/encoder.cpp > CMakeFiles/huffman.dir/lib/encoder.cpp.i

CMakeFiles/huffman.dir/lib/encoder.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/huffman.dir/lib/encoder.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/borisshapa/cpp-course/huffman/lib/encoder.cpp -o CMakeFiles/huffman.dir/lib/encoder.cpp.s

CMakeFiles/huffman.dir/lib/decoder.cpp.o: CMakeFiles/huffman.dir/flags.make
CMakeFiles/huffman.dir/lib/decoder.cpp.o: ../lib/decoder.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/borisshapa/cpp-course/huffman/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/huffman.dir/lib/decoder.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/huffman.dir/lib/decoder.cpp.o -c /home/borisshapa/cpp-course/huffman/lib/decoder.cpp

CMakeFiles/huffman.dir/lib/decoder.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/huffman.dir/lib/decoder.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/borisshapa/cpp-course/huffman/lib/decoder.cpp > CMakeFiles/huffman.dir/lib/decoder.cpp.i

CMakeFiles/huffman.dir/lib/decoder.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/huffman.dir/lib/decoder.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/borisshapa/cpp-course/huffman/lib/decoder.cpp -o CMakeFiles/huffman.dir/lib/decoder.cpp.s

CMakeFiles/huffman.dir/utility/util.cpp.o: CMakeFiles/huffman.dir/flags.make
CMakeFiles/huffman.dir/utility/util.cpp.o: ../utility/util.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/borisshapa/cpp-course/huffman/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/huffman.dir/utility/util.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/huffman.dir/utility/util.cpp.o -c /home/borisshapa/cpp-course/huffman/utility/util.cpp

CMakeFiles/huffman.dir/utility/util.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/huffman.dir/utility/util.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/borisshapa/cpp-course/huffman/utility/util.cpp > CMakeFiles/huffman.dir/utility/util.cpp.i

CMakeFiles/huffman.dir/utility/util.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/huffman.dir/utility/util.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/borisshapa/cpp-course/huffman/utility/util.cpp -o CMakeFiles/huffman.dir/utility/util.cpp.s

CMakeFiles/huffman.dir/utility/main.cpp.o: CMakeFiles/huffman.dir/flags.make
CMakeFiles/huffman.dir/utility/main.cpp.o: ../utility/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/borisshapa/cpp-course/huffman/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/huffman.dir/utility/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/huffman.dir/utility/main.cpp.o -c /home/borisshapa/cpp-course/huffman/utility/main.cpp

CMakeFiles/huffman.dir/utility/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/huffman.dir/utility/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/borisshapa/cpp-course/huffman/utility/main.cpp > CMakeFiles/huffman.dir/utility/main.cpp.i

CMakeFiles/huffman.dir/utility/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/huffman.dir/utility/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/borisshapa/cpp-course/huffman/utility/main.cpp -o CMakeFiles/huffman.dir/utility/main.cpp.s

# Object files for target huffman
huffman_OBJECTS = \
"CMakeFiles/huffman.dir/main.cpp.o" \
"CMakeFiles/huffman.dir/lib/encoder.cpp.o" \
"CMakeFiles/huffman.dir/lib/decoder.cpp.o" \
"CMakeFiles/huffman.dir/utility/util.cpp.o" \
"CMakeFiles/huffman.dir/utility/main.cpp.o"

# External object files for target huffman
huffman_EXTERNAL_OBJECTS =

huffman: CMakeFiles/huffman.dir/main.cpp.o
huffman: CMakeFiles/huffman.dir/lib/encoder.cpp.o
huffman: CMakeFiles/huffman.dir/lib/decoder.cpp.o
huffman: CMakeFiles/huffman.dir/utility/util.cpp.o
huffman: CMakeFiles/huffman.dir/utility/main.cpp.o
huffman: CMakeFiles/huffman.dir/build.make
huffman: CMakeFiles/huffman.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/borisshapa/cpp-course/huffman/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable huffman"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/huffman.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/huffman.dir/build: huffman

.PHONY : CMakeFiles/huffman.dir/build

CMakeFiles/huffman.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/huffman.dir/cmake_clean.cmake
.PHONY : CMakeFiles/huffman.dir/clean

CMakeFiles/huffman.dir/depend:
	cd /home/borisshapa/cpp-course/huffman/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/borisshapa/cpp-course/huffman /home/borisshapa/cpp-course/huffman /home/borisshapa/cpp-course/huffman/cmake-build-debug /home/borisshapa/cpp-course/huffman/cmake-build-debug /home/borisshapa/cpp-course/huffman/cmake-build-debug/CMakeFiles/huffman.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/huffman.dir/depend
