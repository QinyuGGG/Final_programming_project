# Final_programming_project

Use the ngl library to load the model file. I loaded a cat and a cow in the project. The project can make the cow and cat look more beautiful in real applications. I use Noisy Elliptical Dots to make this looks cool. I make this program using NCCA ngl library with Qt Creator. And the IDE was vs2017.

Usage:

I'm going to use vcpk in most cases for our install of 3rd party libs this is going to check the environment variable for CMAKE_TOOLCHAIN_FILE and this must point to where vcpkg.cmake is in the University this is set in your .bash_profile to export CMAKE_TOOLCHAIN_FILE=/public/devel/2020/vcpkg/scripts/buildsystems/vcpkg.cmake

Build:

Use cmake to create vs2017 project files. Then open it in the vs2017 .press build.

Run:

Change the directory to the build/debug ,then click the Cow.exe,you will see the program show the cow model. The default loaded model file is models/cow.obj，The model file can be changed by using the keyboard，Press the key ‘O’ to open a new model. After load a new model,the opengl will draw the model.

