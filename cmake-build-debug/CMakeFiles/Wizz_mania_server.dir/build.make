# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.31

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
CMAKE_COMMAND = /opt/homebrew/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/mathisserra/Desktop/Github/B2_Laplateforme/Wizz_mania_server

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/mathisserra/Desktop/Github/B2_Laplateforme/Wizz_mania_server/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Wizz_mania_server.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Wizz_mania_server.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Wizz_mania_server.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Wizz_mania_server.dir/flags.make

CMakeFiles/Wizz_mania_server.dir/codegen:
.PHONY : CMakeFiles/Wizz_mania_server.dir/codegen

CMakeFiles/Wizz_mania_server.dir/main.cpp.o: CMakeFiles/Wizz_mania_server.dir/flags.make
CMakeFiles/Wizz_mania_server.dir/main.cpp.o: /Users/mathisserra/Desktop/Github/B2_Laplateforme/Wizz_mania_server/main.cpp
CMakeFiles/Wizz_mania_server.dir/main.cpp.o: CMakeFiles/Wizz_mania_server.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/mathisserra/Desktop/Github/B2_Laplateforme/Wizz_mania_server/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Wizz_mania_server.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Wizz_mania_server.dir/main.cpp.o -MF CMakeFiles/Wizz_mania_server.dir/main.cpp.o.d -o CMakeFiles/Wizz_mania_server.dir/main.cpp.o -c /Users/mathisserra/Desktop/Github/B2_Laplateforme/Wizz_mania_server/main.cpp

CMakeFiles/Wizz_mania_server.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Wizz_mania_server.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/mathisserra/Desktop/Github/B2_Laplateforme/Wizz_mania_server/main.cpp > CMakeFiles/Wizz_mania_server.dir/main.cpp.i

CMakeFiles/Wizz_mania_server.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Wizz_mania_server.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/mathisserra/Desktop/Github/B2_Laplateforme/Wizz_mania_server/main.cpp -o CMakeFiles/Wizz_mania_server.dir/main.cpp.s

CMakeFiles/Wizz_mania_server.dir/Server.cpp.o: CMakeFiles/Wizz_mania_server.dir/flags.make
CMakeFiles/Wizz_mania_server.dir/Server.cpp.o: /Users/mathisserra/Desktop/Github/B2_Laplateforme/Wizz_mania_server/Server.cpp
CMakeFiles/Wizz_mania_server.dir/Server.cpp.o: CMakeFiles/Wizz_mania_server.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/mathisserra/Desktop/Github/B2_Laplateforme/Wizz_mania_server/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Wizz_mania_server.dir/Server.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Wizz_mania_server.dir/Server.cpp.o -MF CMakeFiles/Wizz_mania_server.dir/Server.cpp.o.d -o CMakeFiles/Wizz_mania_server.dir/Server.cpp.o -c /Users/mathisserra/Desktop/Github/B2_Laplateforme/Wizz_mania_server/Server.cpp

CMakeFiles/Wizz_mania_server.dir/Server.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Wizz_mania_server.dir/Server.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/mathisserra/Desktop/Github/B2_Laplateforme/Wizz_mania_server/Server.cpp > CMakeFiles/Wizz_mania_server.dir/Server.cpp.i

CMakeFiles/Wizz_mania_server.dir/Server.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Wizz_mania_server.dir/Server.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/mathisserra/Desktop/Github/B2_Laplateforme/Wizz_mania_server/Server.cpp -o CMakeFiles/Wizz_mania_server.dir/Server.cpp.s

CMakeFiles/Wizz_mania_server.dir/testThread.cpp.o: CMakeFiles/Wizz_mania_server.dir/flags.make
CMakeFiles/Wizz_mania_server.dir/testThread.cpp.o: /Users/mathisserra/Desktop/Github/B2_Laplateforme/Wizz_mania_server/testThread.cpp
CMakeFiles/Wizz_mania_server.dir/testThread.cpp.o: CMakeFiles/Wizz_mania_server.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/mathisserra/Desktop/Github/B2_Laplateforme/Wizz_mania_server/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Wizz_mania_server.dir/testThread.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Wizz_mania_server.dir/testThread.cpp.o -MF CMakeFiles/Wizz_mania_server.dir/testThread.cpp.o.d -o CMakeFiles/Wizz_mania_server.dir/testThread.cpp.o -c /Users/mathisserra/Desktop/Github/B2_Laplateforme/Wizz_mania_server/testThread.cpp

CMakeFiles/Wizz_mania_server.dir/testThread.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Wizz_mania_server.dir/testThread.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/mathisserra/Desktop/Github/B2_Laplateforme/Wizz_mania_server/testThread.cpp > CMakeFiles/Wizz_mania_server.dir/testThread.cpp.i

CMakeFiles/Wizz_mania_server.dir/testThread.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Wizz_mania_server.dir/testThread.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/mathisserra/Desktop/Github/B2_Laplateforme/Wizz_mania_server/testThread.cpp -o CMakeFiles/Wizz_mania_server.dir/testThread.cpp.s

# Object files for target Wizz_mania_server
Wizz_mania_server_OBJECTS = \
"CMakeFiles/Wizz_mania_server.dir/main.cpp.o" \
"CMakeFiles/Wizz_mania_server.dir/Server.cpp.o" \
"CMakeFiles/Wizz_mania_server.dir/testThread.cpp.o"

# External object files for target Wizz_mania_server
Wizz_mania_server_EXTERNAL_OBJECTS =

Wizz_mania_server: CMakeFiles/Wizz_mania_server.dir/main.cpp.o
Wizz_mania_server: CMakeFiles/Wizz_mania_server.dir/Server.cpp.o
Wizz_mania_server: CMakeFiles/Wizz_mania_server.dir/testThread.cpp.o
Wizz_mania_server: CMakeFiles/Wizz_mania_server.dir/build.make
Wizz_mania_server: CMakeFiles/Wizz_mania_server.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/mathisserra/Desktop/Github/B2_Laplateforme/Wizz_mania_server/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable Wizz_mania_server"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Wizz_mania_server.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Wizz_mania_server.dir/build: Wizz_mania_server
.PHONY : CMakeFiles/Wizz_mania_server.dir/build

CMakeFiles/Wizz_mania_server.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Wizz_mania_server.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Wizz_mania_server.dir/clean

CMakeFiles/Wizz_mania_server.dir/depend:
	cd /Users/mathisserra/Desktop/Github/B2_Laplateforme/Wizz_mania_server/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/mathisserra/Desktop/Github/B2_Laplateforme/Wizz_mania_server /Users/mathisserra/Desktop/Github/B2_Laplateforme/Wizz_mania_server /Users/mathisserra/Desktop/Github/B2_Laplateforme/Wizz_mania_server/cmake-build-debug /Users/mathisserra/Desktop/Github/B2_Laplateforme/Wizz_mania_server/cmake-build-debug /Users/mathisserra/Desktop/Github/B2_Laplateforme/Wizz_mania_server/cmake-build-debug/CMakeFiles/Wizz_mania_server.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/Wizz_mania_server.dir/depend

