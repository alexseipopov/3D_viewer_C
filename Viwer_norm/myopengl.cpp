#include "myopengl.h"
#include <QMoveEvent>
Myopengl::Myopengl(QWidget *parent) : QOpenGLWidget{parent} {
    res = (exit_st *)calloc(1, sizeof(exit_st));
}

void Myopengl::initializeGL() {


  initializeOpenGLFunctions();
  glLoadIdentity();
   glMatrixMode(GL_MODELVIEW);
  glEnable(GL_DEPTH_TEST);
  // glRotated(90,0,90,0);

}
void Myopengl::resizeGL(int w, int h) {}
void Myopengl::paintGL() {
    glClear(GL_COLOR_BUFFER_BIT |
             GL_DEPTH_BUFFER_BIT);
  glEnableClientState(GL_VERTEX_ARRAY);

    set_scale(res, scale);
  glVertexPointer(3, GL_DOUBLE, 0, res->vertex);
  glDrawElements(GL_LINES, res->amount_struct_pol, GL_UNSIGNED_INT,
                 res->poligons);
    glClearColor(background_color.redF(), background_color.greenF(),background_color.blueF(), 1);
  glDisableClientState(GL_VERTEX_ARRAY);

}
void Myopengl::mouseMoveEvent(QMouseEvent *mo){
//    rotation_x( M_PI /45 * (mo->pos().y() - mPos.y()), res);
//      rotation_y(  M_PI/45 * (mo->pos().x() - mPos.x()), res);
    rotation_x(0.01 / M_PI * (mo->pos().y() - mPos.y()), res);
      rotation_y( 0.01  / M_PI * (mo->pos().x() - mPos.x()), res);
//        rotation_y(0.0001  / M_PI * (mo->pos().x() - mPos.y()), res);
      update();
}

void Myopengl::mousePressEvent(QMouseEvent *mo) {
    mPos=mo->pos();
}
