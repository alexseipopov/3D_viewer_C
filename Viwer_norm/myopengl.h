#ifndef MYOPENGL_H
#define MYOPENGL_H

#include <QColor>
#include <QOpenGLFunctions>
#include <QOpenGLWidget>
#include <mainwindow.h>
#include <stdlib.h>

#include "s21_3DViewer.h"
//#include <GLUT>>
class Myopengl : public QOpenGLWidget, public QOpenGLFunctions {
 public:
  Myopengl(QWidget *parent = nullptr);
//          double minmaxX[2];
//          double minmaxY[2];
//          double minmaxZ[2];
//          int amount_struct_pol;
//          int amount_struct_ver;
  ~Myopengl() {
    if (res) {
       s21_remove_struct(res);
        free(res);
    }
  }
          exit_st *res;
 protected:
  void initializeGL() override;
  void resizeGL(int w, int h) override;
  void paintGL() override;

 private:
  void qColorToRGB(const QColor &C, float &r, float &g, float &b) const;
  int normaliza_0_1(float val, float min, float max) const;


};

#endif  // MYOPENGL_H
