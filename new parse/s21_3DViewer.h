#ifndef SRC_S21_3DVIEVER_H_
#define SRC_S21_3DVIEVER_H_

#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct exit_struct {
  double minmaxX[2];
  double minmaxY[2];
  double minmaxZ[2];
  int amount_struct_pol;
  int amount_struct_ver;
  double *vertex;
  int *poligons;
} exit_st;
//parse
int s21_parse(exit_st *st,char *filename);
int s21_init_struct(exit_st *st);
int parse_vertex(int *vertex_counter, char *ptr, exit_st *st, int *capacity_ver);
int parse_poligons(char *ptr, exit_st *st, int *poligons_counter,
                   int *capacity_pol);
void s21_remove_struct(exit_st *st);
//afine 
// void setting_to_center(exit_st *st);
// void set_scale(exit_st *st, double scale );
// void rotation_x(vertex *v, double angle, exit_st *st);
// void rotation_y(vertex *v, double angle, exit_st *st);
// void rotation_z(vertex *v, double angle, exit_st *st);
//void move(exit_st *st, double a, char axis);
#endif  // SRC_S21_3DVIEVER_H_