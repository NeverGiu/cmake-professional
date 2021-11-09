Original project(super_install_build) directory structure:
.
cmake
├── coffee.icns
├── Info.plist.in
└── messageConfig.cmake.in
CMakeCPack.cmake
CMakeLists.txt
INSTALL.md
LICENSE
log
src
├── CMakeLists.txt
├── hello-world.cpp
├── Message.cpp
└── Message.h
sup-build-cleaner.sh
sup-release-build.sh
tests
 ├── CMakeLists.txt
 └── use_target
     ├── CMakeLists.txt
     └── use_message.cpp

How to install the project ?

Step 1: run 'sup-build-cleaner.sh' to make sure your project here 
	has been cleaned and is prepared(If your downloaded project is the same 
	as the original project directory structure, please skip this step).

Step 2: run 'sup-release-build.sh', then jump to the 'build' directory,
	and legally enter the installation method according to the relevant prompts.

Step 3: if you want to rebuild project, please run 'sup-build-cleaner.sh' 
	and repeat Step 2.
						edit by nevergiu in 2021/11/10 at 00:53
