# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.22.3/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.22.3/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/xyamix/Documents/My_Projects/SuperCold

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/xyamix/Documents/My_Projects/SuperCold/build

# Include any dependencies generated for this target.
include CMakeFiles/sfml_game.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/sfml_game.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/sfml_game.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/sfml_game.dir/flags.make

CMakeFiles/sfml_game.dir/src/Bullet/Bullet.cpp.o: CMakeFiles/sfml_game.dir/flags.make
CMakeFiles/sfml_game.dir/src/Bullet/Bullet.cpp.o: ../src/Bullet/Bullet.cpp
CMakeFiles/sfml_game.dir/src/Bullet/Bullet.cpp.o: CMakeFiles/sfml_game.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/xyamix/Documents/My_Projects/SuperCold/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/sfml_game.dir/src/Bullet/Bullet.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/sfml_game.dir/src/Bullet/Bullet.cpp.o -MF CMakeFiles/sfml_game.dir/src/Bullet/Bullet.cpp.o.d -o CMakeFiles/sfml_game.dir/src/Bullet/Bullet.cpp.o -c /Users/xyamix/Documents/My_Projects/SuperCold/src/Bullet/Bullet.cpp

CMakeFiles/sfml_game.dir/src/Bullet/Bullet.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sfml_game.dir/src/Bullet/Bullet.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/xyamix/Documents/My_Projects/SuperCold/src/Bullet/Bullet.cpp > CMakeFiles/sfml_game.dir/src/Bullet/Bullet.cpp.i

CMakeFiles/sfml_game.dir/src/Bullet/Bullet.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sfml_game.dir/src/Bullet/Bullet.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/xyamix/Documents/My_Projects/SuperCold/src/Bullet/Bullet.cpp -o CMakeFiles/sfml_game.dir/src/Bullet/Bullet.cpp.s

CMakeFiles/sfml_game.dir/src/Enemies/EyeEnemy.cpp.o: CMakeFiles/sfml_game.dir/flags.make
CMakeFiles/sfml_game.dir/src/Enemies/EyeEnemy.cpp.o: ../src/Enemies/EyeEnemy.cpp
CMakeFiles/sfml_game.dir/src/Enemies/EyeEnemy.cpp.o: CMakeFiles/sfml_game.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/xyamix/Documents/My_Projects/SuperCold/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/sfml_game.dir/src/Enemies/EyeEnemy.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/sfml_game.dir/src/Enemies/EyeEnemy.cpp.o -MF CMakeFiles/sfml_game.dir/src/Enemies/EyeEnemy.cpp.o.d -o CMakeFiles/sfml_game.dir/src/Enemies/EyeEnemy.cpp.o -c /Users/xyamix/Documents/My_Projects/SuperCold/src/Enemies/EyeEnemy.cpp

CMakeFiles/sfml_game.dir/src/Enemies/EyeEnemy.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sfml_game.dir/src/Enemies/EyeEnemy.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/xyamix/Documents/My_Projects/SuperCold/src/Enemies/EyeEnemy.cpp > CMakeFiles/sfml_game.dir/src/Enemies/EyeEnemy.cpp.i

CMakeFiles/sfml_game.dir/src/Enemies/EyeEnemy.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sfml_game.dir/src/Enemies/EyeEnemy.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/xyamix/Documents/My_Projects/SuperCold/src/Enemies/EyeEnemy.cpp -o CMakeFiles/sfml_game.dir/src/Enemies/EyeEnemy.cpp.s

CMakeFiles/sfml_game.dir/src/Game/Game.cpp.o: CMakeFiles/sfml_game.dir/flags.make
CMakeFiles/sfml_game.dir/src/Game/Game.cpp.o: ../src/Game/Game.cpp
CMakeFiles/sfml_game.dir/src/Game/Game.cpp.o: CMakeFiles/sfml_game.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/xyamix/Documents/My_Projects/SuperCold/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/sfml_game.dir/src/Game/Game.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/sfml_game.dir/src/Game/Game.cpp.o -MF CMakeFiles/sfml_game.dir/src/Game/Game.cpp.o.d -o CMakeFiles/sfml_game.dir/src/Game/Game.cpp.o -c /Users/xyamix/Documents/My_Projects/SuperCold/src/Game/Game.cpp

CMakeFiles/sfml_game.dir/src/Game/Game.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sfml_game.dir/src/Game/Game.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/xyamix/Documents/My_Projects/SuperCold/src/Game/Game.cpp > CMakeFiles/sfml_game.dir/src/Game/Game.cpp.i

CMakeFiles/sfml_game.dir/src/Game/Game.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sfml_game.dir/src/Game/Game.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/xyamix/Documents/My_Projects/SuperCold/src/Game/Game.cpp -o CMakeFiles/sfml_game.dir/src/Game/Game.cpp.s

CMakeFiles/sfml_game.dir/src/GameObject/GameObject.cpp.o: CMakeFiles/sfml_game.dir/flags.make
CMakeFiles/sfml_game.dir/src/GameObject/GameObject.cpp.o: ../src/GameObject/GameObject.cpp
CMakeFiles/sfml_game.dir/src/GameObject/GameObject.cpp.o: CMakeFiles/sfml_game.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/xyamix/Documents/My_Projects/SuperCold/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/sfml_game.dir/src/GameObject/GameObject.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/sfml_game.dir/src/GameObject/GameObject.cpp.o -MF CMakeFiles/sfml_game.dir/src/GameObject/GameObject.cpp.o.d -o CMakeFiles/sfml_game.dir/src/GameObject/GameObject.cpp.o -c /Users/xyamix/Documents/My_Projects/SuperCold/src/GameObject/GameObject.cpp

CMakeFiles/sfml_game.dir/src/GameObject/GameObject.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sfml_game.dir/src/GameObject/GameObject.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/xyamix/Documents/My_Projects/SuperCold/src/GameObject/GameObject.cpp > CMakeFiles/sfml_game.dir/src/GameObject/GameObject.cpp.i

CMakeFiles/sfml_game.dir/src/GameObject/GameObject.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sfml_game.dir/src/GameObject/GameObject.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/xyamix/Documents/My_Projects/SuperCold/src/GameObject/GameObject.cpp -o CMakeFiles/sfml_game.dir/src/GameObject/GameObject.cpp.s

CMakeFiles/sfml_game.dir/src/Player/Player.cpp.o: CMakeFiles/sfml_game.dir/flags.make
CMakeFiles/sfml_game.dir/src/Player/Player.cpp.o: ../src/Player/Player.cpp
CMakeFiles/sfml_game.dir/src/Player/Player.cpp.o: CMakeFiles/sfml_game.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/xyamix/Documents/My_Projects/SuperCold/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/sfml_game.dir/src/Player/Player.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/sfml_game.dir/src/Player/Player.cpp.o -MF CMakeFiles/sfml_game.dir/src/Player/Player.cpp.o.d -o CMakeFiles/sfml_game.dir/src/Player/Player.cpp.o -c /Users/xyamix/Documents/My_Projects/SuperCold/src/Player/Player.cpp

CMakeFiles/sfml_game.dir/src/Player/Player.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sfml_game.dir/src/Player/Player.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/xyamix/Documents/My_Projects/SuperCold/src/Player/Player.cpp > CMakeFiles/sfml_game.dir/src/Player/Player.cpp.i

CMakeFiles/sfml_game.dir/src/Player/Player.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sfml_game.dir/src/Player/Player.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/xyamix/Documents/My_Projects/SuperCold/src/Player/Player.cpp -o CMakeFiles/sfml_game.dir/src/Player/Player.cpp.s

CMakeFiles/sfml_game.dir/src/SettingsManager/SettingsManager.cpp.o: CMakeFiles/sfml_game.dir/flags.make
CMakeFiles/sfml_game.dir/src/SettingsManager/SettingsManager.cpp.o: ../src/SettingsManager/SettingsManager.cpp
CMakeFiles/sfml_game.dir/src/SettingsManager/SettingsManager.cpp.o: CMakeFiles/sfml_game.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/xyamix/Documents/My_Projects/SuperCold/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/sfml_game.dir/src/SettingsManager/SettingsManager.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/sfml_game.dir/src/SettingsManager/SettingsManager.cpp.o -MF CMakeFiles/sfml_game.dir/src/SettingsManager/SettingsManager.cpp.o.d -o CMakeFiles/sfml_game.dir/src/SettingsManager/SettingsManager.cpp.o -c /Users/xyamix/Documents/My_Projects/SuperCold/src/SettingsManager/SettingsManager.cpp

CMakeFiles/sfml_game.dir/src/SettingsManager/SettingsManager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sfml_game.dir/src/SettingsManager/SettingsManager.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/xyamix/Documents/My_Projects/SuperCold/src/SettingsManager/SettingsManager.cpp > CMakeFiles/sfml_game.dir/src/SettingsManager/SettingsManager.cpp.i

CMakeFiles/sfml_game.dir/src/SettingsManager/SettingsManager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sfml_game.dir/src/SettingsManager/SettingsManager.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/xyamix/Documents/My_Projects/SuperCold/src/SettingsManager/SettingsManager.cpp -o CMakeFiles/sfml_game.dir/src/SettingsManager/SettingsManager.cpp.s

CMakeFiles/sfml_game.dir/src/SpriteContoller/SpriteController.cpp.o: CMakeFiles/sfml_game.dir/flags.make
CMakeFiles/sfml_game.dir/src/SpriteContoller/SpriteController.cpp.o: ../src/SpriteContoller/SpriteController.cpp
CMakeFiles/sfml_game.dir/src/SpriteContoller/SpriteController.cpp.o: CMakeFiles/sfml_game.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/xyamix/Documents/My_Projects/SuperCold/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/sfml_game.dir/src/SpriteContoller/SpriteController.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/sfml_game.dir/src/SpriteContoller/SpriteController.cpp.o -MF CMakeFiles/sfml_game.dir/src/SpriteContoller/SpriteController.cpp.o.d -o CMakeFiles/sfml_game.dir/src/SpriteContoller/SpriteController.cpp.o -c /Users/xyamix/Documents/My_Projects/SuperCold/src/SpriteContoller/SpriteController.cpp

CMakeFiles/sfml_game.dir/src/SpriteContoller/SpriteController.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sfml_game.dir/src/SpriteContoller/SpriteController.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/xyamix/Documents/My_Projects/SuperCold/src/SpriteContoller/SpriteController.cpp > CMakeFiles/sfml_game.dir/src/SpriteContoller/SpriteController.cpp.i

CMakeFiles/sfml_game.dir/src/SpriteContoller/SpriteController.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sfml_game.dir/src/SpriteContoller/SpriteController.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/xyamix/Documents/My_Projects/SuperCold/src/SpriteContoller/SpriteController.cpp -o CMakeFiles/sfml_game.dir/src/SpriteContoller/SpriteController.cpp.s

CMakeFiles/sfml_game.dir/src/TileMap/TileMap.cpp.o: CMakeFiles/sfml_game.dir/flags.make
CMakeFiles/sfml_game.dir/src/TileMap/TileMap.cpp.o: ../src/TileMap/TileMap.cpp
CMakeFiles/sfml_game.dir/src/TileMap/TileMap.cpp.o: CMakeFiles/sfml_game.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/xyamix/Documents/My_Projects/SuperCold/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/sfml_game.dir/src/TileMap/TileMap.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/sfml_game.dir/src/TileMap/TileMap.cpp.o -MF CMakeFiles/sfml_game.dir/src/TileMap/TileMap.cpp.o.d -o CMakeFiles/sfml_game.dir/src/TileMap/TileMap.cpp.o -c /Users/xyamix/Documents/My_Projects/SuperCold/src/TileMap/TileMap.cpp

CMakeFiles/sfml_game.dir/src/TileMap/TileMap.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sfml_game.dir/src/TileMap/TileMap.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/xyamix/Documents/My_Projects/SuperCold/src/TileMap/TileMap.cpp > CMakeFiles/sfml_game.dir/src/TileMap/TileMap.cpp.i

CMakeFiles/sfml_game.dir/src/TileMap/TileMap.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sfml_game.dir/src/TileMap/TileMap.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/xyamix/Documents/My_Projects/SuperCold/src/TileMap/TileMap.cpp -o CMakeFiles/sfml_game.dir/src/TileMap/TileMap.cpp.s

CMakeFiles/sfml_game.dir/src/Utils/debug.cpp.o: CMakeFiles/sfml_game.dir/flags.make
CMakeFiles/sfml_game.dir/src/Utils/debug.cpp.o: ../src/Utils/debug.cpp
CMakeFiles/sfml_game.dir/src/Utils/debug.cpp.o: CMakeFiles/sfml_game.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/xyamix/Documents/My_Projects/SuperCold/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/sfml_game.dir/src/Utils/debug.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/sfml_game.dir/src/Utils/debug.cpp.o -MF CMakeFiles/sfml_game.dir/src/Utils/debug.cpp.o.d -o CMakeFiles/sfml_game.dir/src/Utils/debug.cpp.o -c /Users/xyamix/Documents/My_Projects/SuperCold/src/Utils/debug.cpp

CMakeFiles/sfml_game.dir/src/Utils/debug.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sfml_game.dir/src/Utils/debug.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/xyamix/Documents/My_Projects/SuperCold/src/Utils/debug.cpp > CMakeFiles/sfml_game.dir/src/Utils/debug.cpp.i

CMakeFiles/sfml_game.dir/src/Utils/debug.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sfml_game.dir/src/Utils/debug.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/xyamix/Documents/My_Projects/SuperCold/src/Utils/debug.cpp -o CMakeFiles/sfml_game.dir/src/Utils/debug.cpp.s

CMakeFiles/sfml_game.dir/src/external/SimplexNoise/SimplexNoise.cpp.o: CMakeFiles/sfml_game.dir/flags.make
CMakeFiles/sfml_game.dir/src/external/SimplexNoise/SimplexNoise.cpp.o: ../src/external/SimplexNoise/SimplexNoise.cpp
CMakeFiles/sfml_game.dir/src/external/SimplexNoise/SimplexNoise.cpp.o: CMakeFiles/sfml_game.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/xyamix/Documents/My_Projects/SuperCold/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/sfml_game.dir/src/external/SimplexNoise/SimplexNoise.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/sfml_game.dir/src/external/SimplexNoise/SimplexNoise.cpp.o -MF CMakeFiles/sfml_game.dir/src/external/SimplexNoise/SimplexNoise.cpp.o.d -o CMakeFiles/sfml_game.dir/src/external/SimplexNoise/SimplexNoise.cpp.o -c /Users/xyamix/Documents/My_Projects/SuperCold/src/external/SimplexNoise/SimplexNoise.cpp

CMakeFiles/sfml_game.dir/src/external/SimplexNoise/SimplexNoise.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sfml_game.dir/src/external/SimplexNoise/SimplexNoise.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/xyamix/Documents/My_Projects/SuperCold/src/external/SimplexNoise/SimplexNoise.cpp > CMakeFiles/sfml_game.dir/src/external/SimplexNoise/SimplexNoise.cpp.i

CMakeFiles/sfml_game.dir/src/external/SimplexNoise/SimplexNoise.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sfml_game.dir/src/external/SimplexNoise/SimplexNoise.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/xyamix/Documents/My_Projects/SuperCold/src/external/SimplexNoise/SimplexNoise.cpp -o CMakeFiles/sfml_game.dir/src/external/SimplexNoise/SimplexNoise.cpp.s

CMakeFiles/sfml_game.dir/src/main.cpp.o: CMakeFiles/sfml_game.dir/flags.make
CMakeFiles/sfml_game.dir/src/main.cpp.o: ../src/main.cpp
CMakeFiles/sfml_game.dir/src/main.cpp.o: CMakeFiles/sfml_game.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/xyamix/Documents/My_Projects/SuperCold/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/sfml_game.dir/src/main.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/sfml_game.dir/src/main.cpp.o -MF CMakeFiles/sfml_game.dir/src/main.cpp.o.d -o CMakeFiles/sfml_game.dir/src/main.cpp.o -c /Users/xyamix/Documents/My_Projects/SuperCold/src/main.cpp

CMakeFiles/sfml_game.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sfml_game.dir/src/main.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/xyamix/Documents/My_Projects/SuperCold/src/main.cpp > CMakeFiles/sfml_game.dir/src/main.cpp.i

CMakeFiles/sfml_game.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sfml_game.dir/src/main.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/xyamix/Documents/My_Projects/SuperCold/src/main.cpp -o CMakeFiles/sfml_game.dir/src/main.cpp.s

# Object files for target sfml_game
sfml_game_OBJECTS = \
"CMakeFiles/sfml_game.dir/src/Bullet/Bullet.cpp.o" \
"CMakeFiles/sfml_game.dir/src/Enemies/EyeEnemy.cpp.o" \
"CMakeFiles/sfml_game.dir/src/Game/Game.cpp.o" \
"CMakeFiles/sfml_game.dir/src/GameObject/GameObject.cpp.o" \
"CMakeFiles/sfml_game.dir/src/Player/Player.cpp.o" \
"CMakeFiles/sfml_game.dir/src/SettingsManager/SettingsManager.cpp.o" \
"CMakeFiles/sfml_game.dir/src/SpriteContoller/SpriteController.cpp.o" \
"CMakeFiles/sfml_game.dir/src/TileMap/TileMap.cpp.o" \
"CMakeFiles/sfml_game.dir/src/Utils/debug.cpp.o" \
"CMakeFiles/sfml_game.dir/src/external/SimplexNoise/SimplexNoise.cpp.o" \
"CMakeFiles/sfml_game.dir/src/main.cpp.o"

# External object files for target sfml_game
sfml_game_EXTERNAL_OBJECTS =

sfml_game: CMakeFiles/sfml_game.dir/src/Bullet/Bullet.cpp.o
sfml_game: CMakeFiles/sfml_game.dir/src/Enemies/EyeEnemy.cpp.o
sfml_game: CMakeFiles/sfml_game.dir/src/Game/Game.cpp.o
sfml_game: CMakeFiles/sfml_game.dir/src/GameObject/GameObject.cpp.o
sfml_game: CMakeFiles/sfml_game.dir/src/Player/Player.cpp.o
sfml_game: CMakeFiles/sfml_game.dir/src/SettingsManager/SettingsManager.cpp.o
sfml_game: CMakeFiles/sfml_game.dir/src/SpriteContoller/SpriteController.cpp.o
sfml_game: CMakeFiles/sfml_game.dir/src/TileMap/TileMap.cpp.o
sfml_game: CMakeFiles/sfml_game.dir/src/Utils/debug.cpp.o
sfml_game: CMakeFiles/sfml_game.dir/src/external/SimplexNoise/SimplexNoise.cpp.o
sfml_game: CMakeFiles/sfml_game.dir/src/main.cpp.o
sfml_game: CMakeFiles/sfml_game.dir/build.make
sfml_game: /opt/homebrew/Cellar/sfml/2.5.1_1/lib/libsfml-graphics.dylib
sfml_game: /opt/homebrew/Cellar/sfml/2.5.1_1/lib/libsfml-window.dylib
sfml_game: /opt/homebrew/Cellar/sfml/2.5.1_1/lib/libsfml-audio.dylib
sfml_game: /opt/homebrew/Cellar/sfml/2.5.1_1/lib/libsfml-system.dylib
sfml_game: CMakeFiles/sfml_game.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/xyamix/Documents/My_Projects/SuperCold/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Linking CXX executable sfml_game"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/sfml_game.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/sfml_game.dir/build: sfml_game
.PHONY : CMakeFiles/sfml_game.dir/build

CMakeFiles/sfml_game.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/sfml_game.dir/cmake_clean.cmake
.PHONY : CMakeFiles/sfml_game.dir/clean

CMakeFiles/sfml_game.dir/depend:
	cd /Users/xyamix/Documents/My_Projects/SuperCold/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/xyamix/Documents/My_Projects/SuperCold /Users/xyamix/Documents/My_Projects/SuperCold /Users/xyamix/Documents/My_Projects/SuperCold/build /Users/xyamix/Documents/My_Projects/SuperCold/build /Users/xyamix/Documents/My_Projects/SuperCold/build/CMakeFiles/sfml_game.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/sfml_game.dir/depend

