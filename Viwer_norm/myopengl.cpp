#include "myopengl.h"

Myopengl::Myopengl(QWidget *parent )
    : QOpenGLWidget{parent}
{

}

void Myopengl::initializeGL()
{
    float r, g, b, a =1.0f;
    initializeOpenGLFunctions();
    qColorToRGB(Qt::black,r,g,b);
    glClearColor(r, g, b, a);
//    glEnable(GL_)

}
void Myopengl::resizeGL(int w, int h)
{

}
void Myopengl::paintGL()
{

    exit_st res = s21_parse("/Users/fixierad/Projects/3D_viewer_C/Obj/Man.obj");
    double coordinates[res.amount_struct_ver *3];
    int j = 0;
    set_scale(&res, 0.05);
      for (int i = 1; i < res.amount_struct_ver + 1; i++) {
        coordinates[j] = res.v[i].x;
        j++;
        coordinates[j] = res.v[i].y;
        j++;
        coordinates[j] = res.v[i].z;
        j++;
      }

      glEnableClientState(GL_VERTEX_ARRAY);

      glVertexPointer(3, GL_DOUBLE, 0, &coordinates);
      glColor3d(0, 0, 3);
      glPointSize(3);
         glLineWidth(1.5);
      glDrawArrays(GL_POINTS, 0, res.amount_struct_ver);
      glDisableClientState(GL_VERTEX_ARRAY);
//
//    glPointSize(3);
//    set_scale(&res,0.05);

//    glEnableClientState(GL_VERTEX_ARRAY);
//    for (int k = 0; k < res.amount_struct_pol;k++){
//        double  arrayx [21] = {0};
//        for (int i = 0 ; i < res.p[k].amount_pol;i++){
//        for(int m = 0; m < 3; m ++){
//             if (m%3 == 0){
//            arrayx[(i*3)+m] =    res.v[res.p[k].poligon[i]].x       ;
//             } else if (m%3 == 1 ){
//                   arrayx[(i*3)+m] =   res.v[res.p[k].poligon[i]].y;
//             } else {
//                  arrayx[(i*3)+m] =   res.v[res.p[k].poligon[i]].z;
//             }
//        }
//        }

//        glVertexPointer(3, GL_DOUBLE, 0, arrayx);
//        glDrawArrays(GL_LINE_STRIP,0,res.p[k].amount_pol);
//    }
//    double ver []= {0,0,0, 0,0.5,0.0, 0.5,0.5,0,  0.3,0.3,0.5,   0,0,0, 0,0.5,0.0 };
//    glLineWidth(1.5);
//    glPointSize(3);
//    glEnableClientState(GL_VERTEX_ARRAY);
//    glVertexPointer(3, GL_DOUBLE, 0, ver);
//   int  indices[] = {0,1,1,2,2,0,1,3};

//   // glDrawElements(GL_LINES, 8, GL_UNSIGNED_INT, indices);
//    glDrawArrays(GL_LINE_LOOP,0,1);
//    glDrawArrays(GL_LINE_LOOP,1,2);
//    glDrawArrays(GL_LINE_LOOP,2,3);
//    glDrawArrays(GL_LINE_LOOP,2,3);
//    glDrawArrays(GL_LINE_LOOP,3,4);
//    for (int k = 0 ;k < this->amount_struct_pol;k++){

//    }


//    GLfloat vertices[] = {0};          // 8 of vertex coords
//    GLubyte indices[] = {0,1,2, 2,3,0,   // first half (18 indices)
//                         0,3,4, 4,5,0,
//                         0,5,6, 6,1,0,

//                         1,6,7, 7,2,1,   // second half (18 indices)
//                         7,4,3, 3,2,7,
//                         4,7,6, 6,5,4};
//glLineWidth(1.5);
//glPointSize(1);

//    // activate and specify pointer to vertex array
//    glEnableClientState(GL_VERTEX_ARRAY);
//    glVertexPointer(3, GL_DOUBLE, 0, vertices);
////    glDrawArrays(GL_TRIANGLES,0,3);
//    // draw first half, range is 6 - 0 + 1 = 7 vertices used

//    glDrawRangeElements(GL_TRIANGLES, 0, 6, 18, GL_UNSIGNED_BYTE, indices);

//    // draw second half, range is 7 - 1 + 1 = 7 vertices used
//    glDrawRangeElements(GL_TRIANGLES, 1, 7, 18, GL_UNSIGNED_BYTE, indices+18);

////     deactivate vertex arrays after drawing
//    glDisableClientState(GL_VERTEX_ARRAY);
}
void Myopengl::qColorToRGB(const QColor &C, float &r, float &g, float &b) const
{
   int red =  C.red();
   int green =  C.green();
    int blue = C.blue();
   r=  normaliza_0_1(red, 1.0f, 255.0f);
     g=  normaliza_0_1(green, 1.0f, 255.0f);
    b=  normaliza_0_1(blue, 1.0f, 255.0f);
}
int Myopengl::normaliza_0_1(float val, float min,float max ) const{
    return (val -min) / (max -min);
}
