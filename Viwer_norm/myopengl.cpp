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
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glEnableClientState(GL_VERTEX_ARRAY);
  glLineWidth(thickness);
  set_scale(res, scale);
  if (striple == 1) {
    glEnable(GL_LINE_STIPPLE);
    glLineStipple(1, 0x0101);
  } else {
    glDisable(GL_LINE_STIPPLE);
  }
  glVertexPointer(3, GL_DOUBLE, 0, res->vertex);
  glDrawElements(GL_LINES, res->amount_struct_pol, GL_UNSIGNED_INT,
                 res->poligons);

  glDisableClientState(GL_VERTEX_ARRAY);
}
void Myopengl::mouseMoveEvent(QMouseEvent *mo) {
  scale = 1;
  rotation_x(0.001 / M_PI * (mo->pos().y() - mPos.y()), res);
  rotation_y(0.001 / M_PI * (mo->pos().x() - mPos.x()), res);
  update();
  emit
}

void Myopengl::mousePressEvent(QMouseEvent *mo) {
  scale = 1;
  mPos = mo->pos();
}
