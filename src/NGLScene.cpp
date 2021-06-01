#include <QMouseEvent>
#include <QGuiApplication>
#include <QFont>
#include <QFileDialog>

#include "NGLScene.h"
#include <ngl/Transformation.h>
#include <ngl/NGLInit.h>
#include <ngl/VAOPrimitives.h>
#include <ngl/ShaderLib.h>

NGLScene::NGLScene(QWidget *parent) :
	QOpenGLWidget(parent)
	
{
	setFocusPolicy(Qt::StrongFocus);
	setFocus();
	m_objFileName = "../models/cow.obj";
	m_textureFileName = "../textures/helix_base.tif";
	this->resize(parent->size());
	dotB = 0.001;
	dotR = 0.85;
	dotG = 0.65;

	ccG = 0.93;
	ccR = 0.93;
	ccB = 0.93;
	alpha = 1;
	uad = 0.09;
	ubd = 0.15;
	utol = 1.05;
}

NGLScene::NGLScene(const std::string &_oname, const std::string &_tname)
{
  //setTitle("cow");
  m_showBBox=false;
  m_showBSphere= false;
  m_objFileName=_oname;
  m_textureFileName=_tname;
  dotB = 0;
  dotR = 0;
  dotG = 0;

  ccG = 0;
  ccR = 0;
  ccB = 0;
  alpha = 0;
  uad = 0;
  ubd = 0;
  utol = 0;

}


NGLScene::~NGLScene()
{
  std::cout<<"Shutting down NGL, removing VAO's and Shaders\n";

}

void NGLScene::resizeGL( int _w, int _h )
{
  m_project=ngl::perspective( 45.0f, static_cast<float>( _w ) / _h, 0.05f, 350.0f );
  m_win.width  = static_cast<int>( _w * devicePixelRatio() );
  m_win.height = static_cast<int>( _h * devicePixelRatio() );
}
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
	*depth = nump;
	unsigned char* texture = new unsigned char[4 * nums * numt * nump];
	fread(texture, 4 * nums * numt * nump, 1, fp);
	fclose(fp);
	return texture;
}
void NGLScene::initializeGL()
{
  // we must call this first before any other GL commands to load and link the
  // gl commands from the lib, if this is not done program will crash
  ngl::NGLInit::initialize();

  glClearColor(0.4f, 0.4f, 0.4f, 1.0f);			   // Grey Background
  // enable depth testing for drawing
  glEnable(GL_DEPTH_TEST);
  // enable multisampling for smoother drawing
  glEnable(GL_MULTISAMPLE);

  // Now we will create a basic Camera from the graphics library
  // This is a static camera so it only needs to be set once
  // First create Values for the camera position
  ngl::Vec3 from(0,4,8);
  ngl::Vec3 to(0,0,0);
  ngl::Vec3 up(0,1,0);
  m_view=ngl::lookAt(from,to,up);
  // set the shape using FOV 45 Aspect Ratio based on Width and Height
  // The final two are near and far clipping planes of 0.5 and 10
  m_project=ngl::perspective(45.0f,720.0f/576.0f,0.05f,350.0f);


  //floor
  ngl::ShaderLib::createShaderProgram("FloorShader");

  ngl::ShaderLib::attachShader("FloorVertex", ngl::ShaderType::VERTEX);
  ngl::ShaderLib::attachShader("FloorFragment", ngl::ShaderType::FRAGMENT);
  ngl::ShaderLib::loadShaderSource("FloorVertex", "../shaders/FloorVertex.glsl");
  ngl::ShaderLib::loadShaderSource("FloorFragment", "../shaders/FloorFragment.glsl");

  ngl::ShaderLib::compileShader("FloorVertex");
  ngl::ShaderLib::compileShader("FloorFragment");
  ngl::ShaderLib::attachShaderToProgram("FloorShader", "FloorVertex");
  ngl::ShaderLib::attachShaderToProgram("FloorShader", "FloorFragment");

  // link the shader no attributes are bound
  ngl::ShaderLib::linkProgramObject("FloorShader");
  ngl::ShaderLib::use("FloorShader");

  ngl::ShaderLib::createShaderProgram("TextureShader");

  ngl::ShaderLib::attachShader("TextureVertex",ngl::ShaderType::VERTEX);
  ngl::ShaderLib::attachShader("TextureFragment",ngl::ShaderType::FRAGMENT);
  ngl::ShaderLib::loadShaderSource("TextureVertex","../shaders/TextureVertex.glsl");
  ngl::ShaderLib::loadShaderSource("TextureFragment","../shaders/TextureFragment.glsl");

  ngl::ShaderLib::compileShader("TextureVertex");
  ngl::ShaderLib::compileShader("TextureFragment");
  ngl::ShaderLib::attachShaderToProgram("TextureShader","TextureVertex");
  ngl::ShaderLib::attachShaderToProgram("TextureShader","TextureFragment");

  // link the shader no attributes are bound
  ngl::ShaderLib::linkProgramObject("TextureShader");
  ngl::ShaderLib::use("TextureShader");



  ngl::ShaderLib::use(ngl::nglColourShader);

  ngl::ShaderLib::setUniform("Colour",1.0f,1.0f,1.0f,1.0f);

  // first we create a mesh from an obj passing in the obj file and texture
  m_mesh.reset(  new ngl::Obj(m_objFileName,m_textureFileName));
  // now we need to create this as a VAO so we can draw it
  m_mesh->createVAO();
  m_mesh->calcBoundingSphere();
  ngl::VAOPrimitives::createSphere("sphere",1.0,20);
  // as re-size is not explicitly called we need to do this.
  glViewport(0,0,width(),height());
  m_text.reset(new ngl::Text("../fonts/Arial.ttf",16));
  m_text->setScreenSize(width(),height());
  m_text->setColour(1,1,1);
  GLuint		NoiseTexture = 0;
  // Set up the noise texture
  glActiveTexture(GL_TEXTURE3);
  glBindTexture(GL_TEXTURE_3D, NoiseTexture);
  // Set up noise texture
  glGenTextures(1, &NoiseTexture);
  int nums, numt, nump;
  unsigned char* texture = ReadTexture3D("noise3d.064.tex", &nums, &numt, &nump);
  if (texture == NULL)
  {
	  printf("Error creating noise texture.");
  }
  if (texture == NULL)
  {
	  printf("Error creating noise texture.");
  }
  glBindTexture(GL_TEXTURE_3D, NoiseTexture);
  glTexParameterf(GL_TEXTURE_3D, GL_TEXTURE_WRAP_S, GL_REPEAT);
  glTexParameterf(GL_TEXTURE_3D, GL_TEXTURE_WRAP_T, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_WRAP_R, GL_REPEAT);
  glTexParameterf(GL_TEXTURE_3D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  glTexParameterf(GL_TEXTURE_3D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexImage3D(GL_TEXTURE_3D, 0, GL_RGBA8, nums, numt, nump, 0, GL_RGBA, GL_UNSIGNED_BYTE, texture);


  

  unsigned long idx = floor_vertices.size();

  floor_vertices.push_back(ngl::Vec4(100, -2, 100, 1));
  floor_vertices.push_back(ngl::Vec4(100, -2, -100, 1));
  floor_vertices.push_back(ngl::Vec4(-100, -2, -100, 1));
  floor_vertices.push_back(ngl::Vec4(-100, -2, 100, 1));

  floor_normals.push_back(ngl::Vec4(0.0f, 1.0f, 0.0f, 0.0f));
  floor_normals.push_back(ngl::Vec4(0.0f, 1.0f, 0.0f, 0.0f));
  floor_normals.push_back(ngl::Vec4(0.0f, 1.0f, 0.0f, 0.0f));
  floor_normals.push_back(ngl::Vec4(0.0f, 1.0f, 0.0f, 0.0f));

  floor_faces.push_back(ngl::Vec3(idx, idx + 1, idx + 2));
  floor_faces.push_back(ngl::Vec3(idx, idx + 2, idx + 3));
  //floor
  glBindVertexArray(floor_vao);
  glGenBuffers(3, floor_buffer);
  glBindBuffer(GL_ARRAY_BUFFER, floor_buffer[0]);
  glBufferData(GL_ARRAY_BUFFER,
	  sizeof(float) * floor_vertices.size() * 4, floor_vertices.data(),
	  GL_STATIC_DRAW);
  glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 0, 0);
  glEnableVertexAttribArray(0);

  glBindBuffer(GL_ARRAY_BUFFER, floor_buffer[1]);
  glBufferData(GL_ARRAY_BUFFER,
	  sizeof(float) * floor_normals.size() * 4, floor_normals.data(),
	  GL_STATIC_DRAW);
  glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 0, 0);
  glEnableVertexAttribArray(1);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, floor_buffer[2]);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(uint32_t) * floor_faces.size() * 3,
	  floor_faces.data(), GL_STATIC_DRAW);
}
 

void NGLScene::loadMatricesToShader()
{

  ngl::Mat4 MVP=m_project * m_view *
                m_mouseGlobalTX*
                m_transform.getMatrix();

  ngl::ShaderLib::setUniform("MVP", MVP);
  
}
void NGLScene::updateScene() {
	//ngl::ShaderLib::use("TextureShader");
	update();
}
void NGLScene::paintGL()
{
  // clear the screen and depth buffer
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   glViewport(0,0,m_win.width,m_win.height);
   ngl::Mat4 rotX;
   ngl::Mat4 rotY;
   // create the rotation matrices
   rotX.rotateX(m_win.spinXFace);
   rotY.rotateY(m_win.spinYFace);
   // multiply the rotations
   m_mouseGlobalTX=rotY*rotX;
   // add the translations
   m_mouseGlobalTX.m_m[3][0] = m_modelPos.m_x;
   m_mouseGlobalTX.m_m[3][1] = m_modelPos.m_y;
   m_mouseGlobalTX.m_m[3][2] = m_modelPos.m_z;

  ngl::ShaderLib::use("TextureShader");
  m_transform.reset();
  loadMatricesToShader();
  ngl::ShaderLib::setUniform("Noise3", 3);
  ngl::ShaderLib::setUniform("uAd", this->uad);
  ngl::ShaderLib::setUniform("uBd", this->ubd);
  ngl::ShaderLib::setUniform("uTol", this->utol);
  ngl::ShaderLib::setUniform("uAlpha", this->alpha);

  ngl::ShaderLib::setUniform("uBodyGreen", this->ccG);
  ngl::ShaderLib::setUniform("uBodyBlue", this->ccB);
  ngl::ShaderLib::setUniform("uBodyRed", this->ccR);

  ngl::ShaderLib::setUniform("uDotBlue", this->dotB);
  ngl::ShaderLib::setUniform("uDotGreen", this->dotG);
  ngl::ShaderLib::setUniform("uDotRed", this->dotR);

  // draw the mesh
  m_mesh->draw();
  //m_bin->draw();
  // draw the mesh bounding box
  ngl::ShaderLib::use("nglColourShader");

  if(m_showBBox==true)
  {
    loadMatricesToShader();
    ngl::ShaderLib::setUniform("Colour",1.0f,1.0f,1.0f,1.0f);
    m_mesh->drawBBox();
  }
  if(m_showBSphere==true)
  {
    ngl::ShaderLib::setUniform("Colour",1.0f,1.0f,1.0f,1.0f);
    m_transform.reset();
      glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
        m_transform.setPosition(m_mesh->getSphereCenter());
        m_transform.setScale(m_mesh->getSphereRadius(),m_mesh->getSphereRadius(),m_mesh->getSphereRadius());
        loadMatricesToShader();
        ngl::VAOPrimitives::draw("sphere");
      glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
  }

  m_text->renderText(10,18,"Press \"O\" to open a new model.");
  ngl::ShaderLib::use("FloorShader");
  ngl::Mat4 MVP = m_project * m_view *
	  m_mouseGlobalTX*
	  m_transform.getMatrix();
  ngl::ShaderLib::setUniform("view", MVP);
  glDrawElements(GL_TRIANGLES, floor_faces.size() * 3, GL_UNSIGNED_INT, 0);
}

//----------------------------------------------------------------------------------------------------------------------

void NGLScene::keyPressEvent(QKeyEvent *_event)
{
  // this method is called every time the main window recives a key event.
  // we then switch on the key value and set the camera in the GLWindow
  switch (_event->key())
  {
  // escape key to quite
  case Qt::Key_Escape : QGuiApplication::exit(EXIT_SUCCESS); break;
  // turn on wirframe rendering
  case Qt::Key_W : glPolygonMode(GL_FRONT_AND_BACK,GL_LINE); break;
  // turn off wire frame
  case Qt::Key_S : glPolygonMode(GL_FRONT_AND_BACK,GL_FILL); break;
  // show full screen
  case Qt::Key_F : showFullScreen(); break;
  // show windowed
  case Qt::Key_N : showNormal(); break;
  case Qt::Key_B : m_showBBox^=true; break;
  case Qt::Key_P : m_showBSphere^=true; break;
  case Qt::Key_Space :
        m_win.spinXFace=0;
        m_win.spinYFace=0;
        m_modelPos.set(ngl::Vec3::zero());
  break;

  case Qt::Key_O :
  {
    QString filename = QFileDialog::getOpenFileName(
              nullptr,
              tr("load Obj"),
              QDir::currentPath(),
              tr("*.obj") );

    if (!filename.isNull())
    {
      m_mesh.reset(  new ngl::Obj(filename.toStdString()));
      // now we need to create this as a VAO so we can draw it
      m_mesh->createVAO();
      m_mesh->calcBoundingSphere();

    }
  }
  break;

  case Qt::Key_T :
  {
    QString filename = QFileDialog::getOpenFileName(
              nullptr,
              tr("load texture"),
              QDir::currentPath(),
              tr("Image Files (*.png *.jpg *.bmp *.tif)"));

    if (!filename.isNull())
    {
      m_mesh->setTexture(filename.toStdString());
    }
  }
  break;

  default : break;
  }
  // finally update the GLWindow and re-draw
  update();
}
