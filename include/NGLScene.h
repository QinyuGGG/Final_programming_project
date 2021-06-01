#ifndef NGLSCENE_H_
#define NGLSCENE_H_
#include <ngl/Vec3.h>
#include <ngl/Mat4.h>
#include <ngl/Obj.h>
#include <ngl/Text.h>
#include <ngl/Transformation.h>
#include "WindowParams.h"
#include <QOpenGLWidget>
#include <memory>

//----------------------------------------------------------------------------------------------------------------------
/// @file NGLScene.h
/// @brief this class inherits from the Qt OpenGLWindow and allows us to use NGL to draw OpenGL
/// @author Jonathan Macey
/// @version 1.0
/// @date 10/9/13
/// Revision History :
/// This is an initial version used for the new NGL6 / Qt 5 demos
/// @class NGLScene
/// @brief our main glwindow widget for NGL applications all drawing elements are
/// put in this file
//----------------------------------------------------------------------------------------------------------------------

class NGLScene :  public QOpenGLWidget
{
	Q_OBJECT
  public:
	  NGLScene(QWidget *parent);
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief ctor for our NGL drawing class
    /// @param [in] parent the parent window to the class
    //----------------------------------------------------------------------------------------------------------------------
    NGLScene(const std::string &_oname, const std::string &_tname);
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief dtor must close down ngl and release OpenGL resources
    //----------------------------------------------------------------------------------------------------------------------
	~NGLScene() override;
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief the initialize class is called once when the window is created and we have a valid GL context
    /// use this to setup any default GL stuff
    //----------------------------------------------------------------------------------------------------------------------
    void initializeGL() override;
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief this is called everytime we want to draw the scene
    //----------------------------------------------------------------------------------------------------------------------
    void paintGL() override;
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief called when window is resized
    //----------------------------------------------------------------------------------------------------------------------
    void resizeGL(int _w, int _h) override;
public slots:
	void changedcgValue(double v) {
		dotG = v;
		updateScene();
	}
	void changedcrValue(double v) {
		dotR = v;
		updateScene();
	}
	void changedcbValue(double v) {
		dotB = v;
		updateScene();
	}
	void changeccgValue(double v) {
		ccG = v;
		updateScene();
	}
	void changeccrValue(double v) {
		ccR = v;
		updateScene();
	}
	void changeccbValue(double v) {
		ccB = v;
		updateScene();
	}
	void changeuadValue(int v) {
		uad = v / 1000.0;
		updateScene();
	}
	void changeubdValue(int v) {
		ubd = v / 1000.0;
		updateScene();
	}
	void changeutolValue(int v) {
		utol = v / 1000.0;
		updateScene();
	}
	void changealphaValue(int v) {
		alpha = v/1000.0;
		updateScene();
	}
	void changeresetZ() {
		m_modelPos.m_z = 0;
		updateScene();
	}
	void changeIncZ() {
		m_modelPos.m_z += 1;
		updateScene();
	}
	void changedecZ() {
		m_modelPos.m_z -=1;
		updateScene();
	}
	void quit() {
		exit(0);
	}


private:
	float cowZ;
	float dotB;
	float dotR;
	float dotG;

	float ccG;
	float ccR;
	float ccB;
	float alpha;
	float uad;
	float ubd;
	float utol;

    //----------------------------------------------------------------------------------------------------------------------
    /// @brief the windows params such as mouse and rotations etc
    //----------------------------------------------------------------------------------------------------------------------
    WinParams m_win;
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief used to store the global mouse transforms
    //----------------------------------------------------------------------------------------------------------------------
    ngl::Mat4 m_mouseGlobalTX;
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief Our Camera
    //----------------------------------------------------------------------------------------------------------------------
    ngl::Mat4 m_view;
    ngl::Mat4 m_project;
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief transformation stack for the gl transformations etc
    //----------------------------------------------------------------------------------------------------------------------
    ngl::Transformation m_transform;
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief the model position for mouse movement
    //----------------------------------------------------------------------------------------------------------------------
    ngl::Vec3 m_modelPos;
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief our model
    //----------------------------------------------------------------------------------------------------------------------
    std::unique_ptr<ngl::Obj> m_mesh;
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief flag to show bounding box
    //----------------------------------------------------------------------------------------------------------------------
    bool m_showBBox;
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief flag to show bounding sphere
    //----------------------------------------------------------------------------------------------------------------------
    bool m_showBSphere;
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief text for rendering
    //----------------------------------------------------------------------------------------------------------------------
    std::unique_ptr<ngl::Text> m_text;
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief method to load transform matrices to the shader
    //----------------------------------------------------------------------------------------------------------------------
    void loadMatricesToShader();
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief Qt Event called when a key is pressed
    /// @param [in] _event the Qt event to query for size etc
    //----------------------------------------------------------------------------------------------------------------------
    void keyPressEvent(QKeyEvent *_event) override;
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief this method is called every time a mouse is moved
    /// @param _event the Qt Event structure
    //----------------------------------------------------------------------------------------------------------------------
    void mouseMoveEvent (QMouseEvent * _event ) override;
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief this method is called everytime the mouse button is pressed
    /// inherited from QObject and overridden here.
    /// @param _event the Qt Event structure
    //----------------------------------------------------------------------------------------------------------------------
    void mousePressEvent ( QMouseEvent *_event) override;
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief this method is called everytime the mouse button is released
    /// inherited from QObject and overridden here.
    /// @param _event the Qt Event structure
    //----------------------------------------------------------------------------------------------------------------------
    void mouseReleaseEvent ( QMouseEvent *_event ) override;

    //----------------------------------------------------------------------------------------------------------------------
    /// @brief this method is called everytime the mouse wheel is moved
    /// inherited from QObject and overridden here.
    /// @param _event the Qt Event structure
    //----------------------------------------------------------------------------------------------------------------------
    void wheelEvent( QWheelEvent *_event) override;
	void updateScene();
    std::string m_objFileName;
    std::string m_textureFileName;
	GLuint floor_vao;
	GLuint floor_buffer[3];
	std::vector<ngl::Vec4> floor_vertices;
	std::vector<ngl::Vec4> floor_normals;
	std::vector<ngl::Vec3> floor_faces;


};



#endif
