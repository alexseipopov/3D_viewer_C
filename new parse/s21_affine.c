#include "s21_3DViewer.h"

// void rotation_x(vertex *v, double angle, exit_st *st) {
//   for (unsigned i = 0; i < st->amount_struct_ver; i++) {
//     double temp_y = st->v[i].y;
//     double temp_z = st->v[i].z;
//     st->v[i].y = cos(angle) * temp_y + sin(angle) * temp_z;
//     st->v[i].z = -sin(angle) * temp_y + cos(angle) * temp_z;
//   }
// }
// void rotation_y(vertex *v, double angle, exit_st *st) {
//   for (unsigned i = 0; i < st->amount_struct_ver; i++) {
//     double temp_x = st->v[i].x;
//     double temp_z = st->v[i].z;
//     st->v[i].y = cos(angle) * temp_x + sin(angle) * temp_z;
//     st->v[i].z = -sin(angle) * temp_x + cos(angle) * temp_z;
//   }
// }
// void rotation_z(vertex *v, double angle, exit_st *st) {
//   for (unsigned i = 0; i < st->amount_struct_ver; i++) {
//     double temp_x = st->v[i].x;
//     double temp_y = st->v[i].y;
//     st->v[i].y = cos(angle) * temp_x - sin(angle) * temp_y;
//     st->v[i].z = -sin(angle) * temp_x + cos(angle) * temp_y;
//   }
// }
// void setting_to_center(exit_st *st) {
//   double centX = st->minmaxX[0] + (st->minmaxX[1] - st->minmaxX[0]) / 2;
//   double centY = st->minmaxY[0] + (st->minmaxY[1] - st->minmaxY[0]) / 2;
//   double centZ = st->minmaxZ[0] + (st->minmaxZ[1] - st->minmaxZ[0]) / 2;
//   for (unsigned i = 0; i < st->amount_struct_ver; i++) {
//     st->v[i].x -= centX;
//     st->v[i].y -= centY;
//     st->v[i].z -= centZ;
//   }
// }
void set_scale(exit_st *st, double scale) {
  for (unsigned i = 0; i < st->amount_struct_ver; i+=3) {
    st->vertex[i] *= scale;
    st->vertex[i+1] *= scale;
   st->vertex[i+2] *= scale;
  }
}
// // TODO подумать как будет поступать нужная ось
// void move(exit_st *st, double a, char axis) {
//   for (unsigned i = 0; i < st->amount_struct_ver; i++) {
//     if (axis == 'x')
//       st->v[i].x += a;
//     else if (axis == 'y')
//       st->v[i].y += a;
//     else if (axis == 'z')
//       st->v[i].z += a;
//   }
// }