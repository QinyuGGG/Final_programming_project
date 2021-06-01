# Final_programming_project

Use the ngl library to load the model file. I loaded a cat and a cow in the project. The project can make the cow and cat look more beautiful in real applications. I use Noisy Elliptical Dots to make this looks cool. I make this program using NCCA ngl library with Qt Creator. And the IDE was vs2017.

Usage:

I'm going to use vcpk in most cases for our install of 3rd party libs this is going to check the environment variable for CMAKE_TOOLCHAIN_FILE and this must point to where vcpkg.cmake is in the University this is set in your .bash_profile to export CMAKE_TOOLCHAIN_FILE=/public/devel/2020/vcpkg/scripts/buildsystems/vcpkg.cmake

Build:

Use cmake to create vs2017 project files. Then open it in the vs2017 .press build.

Run:

Change the directory to the build/debug ,then click the Cow.exe,you will see the program show the cow model. The default loaded model file is models/cow.obj，The model file can be changed by using the keyboard，Press the key ‘O’ to open a new model. After load a new model,the opengl will draw the model.

Key Features:

use mouse and keyboard to control. Press the key ‘O’ to open a new model. Mouse wheel to zoom the camera. Left mouse to rotate the model. Right mouse to drag the model to a new position. use UI to change the textures, colors and the place of model.

Design & Algorithm:

I use the Qt5Widgets from the Qt library to create the program. The the project should include the file NGLConfig.cmake, I also need to use c++17 to compile the source files.

The program have three important cpp files, these file are main.cpp, NGLScene.cpp, NGLSceneMouseControls.cpp. I need to create a QApplication in the main function. Then create an OpenGL format specifier. Set to CoreProfile OpenGL so I can't use and old Immediate mode GL. After create the scene window, I can draw a model to the window.

The Noisy Elliptical Dots will be used like a texture to mapping the model body.I get a noise value based on the current fragment's model coordinates, I need. to creates a 3D noise texture and places it into Texture Unit 3, then our vertex and fragment shader can access it through the pre-created uniform variable called Noise3. I need a noise file noise3d.064.tex in which was created by the glman.

unsigned char*  
ReadTexture3D(char* filename, int* width, int* height, int* depth)  
{  
FILE* fp = fopen(filename, "rb");  
if (fp == NULL)  
return NULL;  
int nums, numt, nump;  
fread(&nums, 4, 1, fp);   
fread(&numt, 4, 1, fp);  
fread(&nump, 4, 1, fp);    
*width = nums;   
*height = numt;   
depth = nump;  
unsigned char texture = new unsigned char[4 * nums * numt * nump];  
fread(texture, 4 * nums * numt * nump, 1, fp);  
fclose(fp);  
return texture;  
}  

Then read the noise data to the memory,then Set up noise texture.   

glBindTexture(GL_TEXTURE_3D, NoiseTexture);   
glTexParameterf(GL_TEXTURE_3D, GL_TEXTURE_WRAP_S, GL_REPEAT);    
glTexParameterf(GL_TEXTURE_3D, GL_TEXTURE_WRAP_T, GL_REPEAT);    
glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_WRAP_R, GL_REPEAT);    
glTexParameterf(GL_TEXTURE_3D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);    
glTexParameterf(GL_TEXTURE_3D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);    
glTexImage3D(GL_TEXTURE_3D, 0, GL_RGBA8, nums, numt, nump, 0, GL_RGBA, GL_UNSIGNED_BYTE, texture);   

We now can use the texture on the model.   

As we should build the GUI with QT designer, I create a new ui,and let this file called mainwindow.ui.   I can show the code in the QT designer.Copy these code to a new file and put it into the CPP source file directory. As we should build the GUI with QT designer.I should create a new ui, and let this file called mainwindow.ui. I can show the code in the QT designer.Copy these code to a new file and put it into the CPP source file directory.  

Then we use the signal and slots to connect the object in the gui to our source code.   

connect(m_ui->bt_inc, SIGNAL(clicked()), m_gl, SLOT(changeIncZ()));   
connect(m_ui->bt_dec, SIGNAL(clicked()), m_gl, SLOT(changedecZ()));  
connect(m_ui->bt_reset, SIGNAL(clicked()), m_gl, SLOT(changeresetZ()));   
connect(m_ui->bt_quit, SIGNAL(clicked()), m_gl, SLOT(quit()));  
  
connect(m_ui->alphaBar, SIGNAL(valueChanged(int)), m_gl, SLOT(changealphaValue(int)));  
connect(m_ui->adBar, SIGNAL(valueChanged(int)), m_gl, SLOT(changeuadValue(int)));  
connect(m_ui->bdBar, SIGNAL(valueChanged(int)), m_gl, SLOT(changeubdValue(int)));   
connect(m_ui->tolBar, SIGNAL(valueChanged(int)), m_gl, SLOT(changeutolValue(int)));  
  
connect(m_ui->dcgValue, SIGNAL(valueChanged(double)), m_gl, SLOT(changedcgValue(double)));  
connect(m_ui->dcrValue, SIGNAL(valueChanged(double)), m_gl, SLOT(changedcrValue(double)));   
connect(m_ui->dcbValue, SIGNAL(valueChanged(double)), m_gl, SLOT(changedcbValue(double)));    
   
connect(m_ui->ccbValue, SIGNAL(valueChanged(double)), m_gl, SLOT(changeccbValue(double)));  
connect(m_ui->ccgValue, SIGNAL(valueChanged(double)), m_gl, SLOT(changeccgValue(double)));  
connect(m_ui->ccrValue, SIGNAL(valueChanged(double)), m_gl, SLOT(changeccrValue(double)));  
  
These function will update the value in the shaders.   
