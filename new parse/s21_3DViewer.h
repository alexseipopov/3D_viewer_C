#ifndef SRC_S21_3DVIEVER_H_
#define SRC_S21_3DVIEVER_H_

#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct poiligons_struct {
  int *poligon;
  int amount_pol;
} poligons;
typedef struct exit_struct {
  double minmaxX[2];
  double minmaxY[2];
  double minmaxZ[2];
  int amount_struct_pol;
  int amount_struct_ver;
  double *vertex;
  poligons *p;
} exit_st;
//parse
exit_st s21_parse(char *filename);
int s21_fill_amount(char *filename, exit_st *st);
int s21_init_struct(exit_st *st);
int parse_vertex(int i, char *ptr, exit_st *st);
int memory_for_pol(char *ptr, poligons *p);
void parse_poligons(char *ptr, poligons *p);

//afine 
void setting_to_center(exit_st *st);
void set_scale(exit_st *st, double scale );
// void rotation_x(vertex *v, double angle, exit_st *st);
// void rotation_y(vertex *v, double angle, exit_st *st);
// void rotation_z(vertex *v, double angle, exit_st *st);
void move(exit_st *st, double a, char axis);
#endif  // SRC_S21_3DVIEVER_H_