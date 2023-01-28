#include "myopengl.h"

Myopengl::Myopengl(QWidget *parent) : QOpenGLWidget{parent} {}

void Myopengl::initializeGL() {
  float r, g, b, a = 1.0f;

  initializeOpenGLFunctions();
  glEnable(GL_DEPTH_TEST);
  // glRotated(90,0,90,0);
  qColorToRGB(Qt::black, r, g, b);
  //    glClearColor(r, g, b, a);
  //    glEnable(GL_)
}
void Myopengl::resizeGL(int w, int h) {}
void Myopengl::paintGL() {
  exit_st *st = (exit_st *)calloc(1, sizeof(exit_st));
  s21_parse(st, "/Users/fixierad/Projects/3D_viewer_C/Obj/Mickey Mouse_2.obj");
  setting_to_center(st);
  double scale = normalize(st);
  set_scale(st, scale);
  glEnableClientState(GL_VERTEX_ARRAY);
  glVertexPointer(3, GL_DOUBLE, 0, st->vertex);
  glDrawElements(GL_LINES, st->amount_struct_pol, GL_UNSIGNED_INT,
                 st->poligons);
  glDisableClientState(GL_VERTEX_ARRAY);
  s21_remove_struct(st);
  free(st);

  //        double vertices[] = {0,0,0, 0.1,0.1,0.1,0,0,0, 0.2,0.2,0.2,0,0,0,
  //        0.3,0.3,0.13, 0,0,0, 0.1,0.1,0.1,0,0,0, 0.2,0.2,0.2,0,0,0,
  //        0.3,0.3,0.13};          // 8 of vertex coords int indices[] = {
  //        0,1,2, 2,3,0,   // first half (18 indices)
  //                             0,3,4, 4,5,0,
  //                             0,5,6, 6,1,0,

  //                             1,6,7, 7,2,1,   // second half (18 indices)
  //                             7,4,3, 3,2,7,
  //                             4,7,6, 6,5,4};
  // exit_st *st = (exit_st *)calloc(1, sizeof(exit_st));
  // s21_parse(st,"/Users/fixierad/Projects/3D_viewer_C/Mickey Mouse_2.obj");
  //      set_scale(st, 0.001);
  //      glEnableClientState(GL_VERTEX_ARRAY);
  //      glPointSize(3);
  //         glLineWidth(1.5);
  //      glVertexPointer(3, GL_DOUBLE, 0, st->vertex);
  //      glColor3d(0, 0, 3);

  //  glDrawElements(GL_LINES, st->amount_struct_pol, GL_INT, st->poligons);
  //      glDisableClientState(GL_VERTEX_ARRAY);

  //
  //    glPointSize(3);
  //    set_scale(st,0.05);

  //    glEnableClientState(GL_VERTEX_ARRAY);
  //    for (int k = 0; k < st->amount_struct_pol-1;k+=2){

  //         int a[2] = { st->poligons[k], st->poligons[k+1]};
  //         printf("%d %d \n",st->poligons[k], st->poligons[k+1] );
  //        glVertexPointer(3, GL_DOUBLE, 0, st->vertex);
  //         glDrawElements(GL_LINE_LOOP, 2, GL_INT, a);
  //    }
  //    double ver []= {0,0,0, 0,0.5,0.0, 0.5,0.5,0,  0.3,0.3,0.5,   0,0,0,
  //    0,0.5,0.0 }; glLineWidth(1.5); glPointSize(3);
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
  // glLineWidth(1.5);
  // glPointSize(1);

  //    // activate and specify pointer to vertex array
  //    glEnableClientState(GL_VERTEX_ARRAY);
  //    glVertexPointer(3, GL_DOUBLE, 0, vertices);
  ////    glDrawArrays(GL_TRIANGLES,0,3);
  //    // draw first half, range is 6 - 0 + 1 = 7 vertices used

  //    glDrawRangeElements(GL_TRIANGLES, 0, 6, 18, GL_UNSIGNED_BYTE, indices);

  //    // draw second half, range is 7 - 1 + 1 = 7 vertices used
  //    glDrawRangeElements(GL_TRIANGLES, 1, 7, 18, GL_UNSIGNED_BYTE,
  //    indices+18);

  ////     deactivate vertex arrays after drawing
  //    glDisableClientState(GL_VERTEX_ARRAY);
}
void Myopengl::qColorToRGB(const QColor &C, float &r, float &g,
                           float &b) const {
  int red = C.red();
  int green = C.green();
  int blue = C.blue();
  r = normaliza_0_1(red, 1.0f, 255.0f);
  g = normaliza_0_1(green, 1.0f, 255.0f);
  b = normaliza_0_1(blue, 1.0f, 255.0f);
}
int Myopengl::normaliza_0_1(float val, float min, float max) const {
  return (val - min) / (max - min);
}
