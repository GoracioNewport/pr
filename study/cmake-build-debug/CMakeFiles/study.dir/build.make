# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /snap/clion/169/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/169/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /mnt/hdd/pr/study

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/hdd/pr/study/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/study.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/study.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/study.dir/flags.make

CMakeFiles/study.dir/tinkoff/classes/thematicContests/sqrt/B.cpp.o: CMakeFiles/study.dir/flags.make
CMakeFiles/study.dir/tinkoff/classes/thematicContests/sqrt/B.cpp.o: ../tinkoff/classes/thematicContests/sqrt/B.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/hdd/pr/study/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/study.dir/tinkoff/classes/thematicContests/sqrt/B.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/study.dir/tinkoff/classes/thematicContests/sqrt/B.cpp.o -c /mnt/hdd/pr/study/tinkoff/classes/thematicContests/sqrt/B.cpp

CMakeFiles/study.dir/tinkoff/classes/thematicContests/sqrt/B.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/study.dir/tinkoff/classes/thematicContests/sqrt/B.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/hdd/pr/study/tinkoff/classes/thematicContests/sqrt/B.cpp > CMakeFiles/study.dir/tinkoff/classes/thematicContests/sqrt/B.cpp.i

CMakeFiles/study.dir/tinkoff/classes/thematicContests/sqrt/B.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/study.dir/tinkoff/classes/thematicContests/sqrt/B.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/hdd/pr/study/tinkoff/classes/thematicContests/sqrt/B.cpp -o CMakeFiles/study.dir/tinkoff/classes/thematicContests/sqrt/B.cpp.s

# Object files for target study
study_OBJECTS = \
"CMakeFiles/study.dir/tinkoff/classes/thematicContests/sqrt/B.cpp.o"

# External object files for target study
study_EXTERNAL_OBJECTS =

study: CMakeFiles/study.dir/tinkoff/classes/thematicContests/sqrt/B.cpp.o
study: CMakeFiles/study.dir/build.make
study: CMakeFiles/study.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/hdd/pr/study/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable study"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/study.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/study.dir/build: study
.PHONY : CMakeFiles/study.dir/build

CMakeFiles/study.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/study.dir/cmake_clean.cmake
.PHONY : CMakeFiles/study.dir/clean

CMakeFiles/study.dir/depend:
	cd /mnt/hdd/pr/study/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/hdd/pr/study /mnt/hdd/pr/study /mnt/hdd/pr/study/cmake-build-debug /mnt/hdd/pr/study/cmake-build-debug /mnt/hdd/pr/study/cmake-build-debug/CMakeFiles/study.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/study.dir/depend

