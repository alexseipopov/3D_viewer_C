#ifndef MYOPENGL_H
#define MYOPENGL_H

#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QColor>
#include "s21_3DViewer.h"
//#include <GLUT>>
class Myopengl : public QOpenGLWidget, public QOpenGLFunctions
{
public:
    Myopengl(QWidget *parent = nullptr);
//    vertex *v;
//    poligons *p;
protected:
    void initializeGL()override;
    void resizeGL(int w, int h)override;
    void paintGL()override;

private:
        void qColorToRGB(const QColor &C, float &r, float &g, float &b) const;
        int normaliza_0_1(float val, float min,float max ) const;

//        double minmaxX[2];
//        double minmaxY[2];
//        double minmaxZ[2];
//        int amount_struct_pol;
//        int amount_struct_ver;


};

#endif // MYOPENGL_H
