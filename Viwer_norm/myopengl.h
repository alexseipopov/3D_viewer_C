#ifndef MYOPENGL_H
#define MYOPENGL_H

#include <QColor>
#include <QOpenGLFunctions>
#include <QOpenGLWidget>
#include <mainwindow.h>
#include <QThread>
#include <QMoveEvent>

#include <GLU.h>
#include <QGraphicsSceneMouseEvent>
#include <stdlib.h>

#include "s21_3DViewer.h"

class Myopengl : public QOpenGLWidget, public QOpenGLFunctions {
 public:
   double thickness  = 1 ;
  Myopengl(QWidget *parent = nullptr);
  double scale =1;
  QColor background_color = QColorConstants::Black;
    QColor points_color;
    QColor line_color;
  int striple = 0;
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
  QPoint mPos;
 //         QTimer tmr;
          void mousePressEvent(QMouseEvent*) override;
          void mouseMoveEvent(QMouseEvent*) override;



};

#endif  // MYOPENGL_H
