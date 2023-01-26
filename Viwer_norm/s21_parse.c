#include "s21_3DViewer.h"

//int main() {
//  int status = 0;
//  int amount_ver = 0;
//  int amount_pol = 0;
//  exit_st st = {0};
//  st = s21_parse("test.obj");
//  for(int i = 0; i< st.amount_struct_ver; i++) {
//    printf("v %lf %lf %lf\n", st.v[i].x, st.v[i].y, st.v[i].z );
//  }
//  return 0;
//}

exit_st s21_parse(char *filename) {
  exit_st *st = (exit_st *)calloc(1, sizeof(exit_st));
  int status = 0;
  status = s21_fill_amount(filename, st);
  s21_init_struct(st);
  //KOSTIIIIIL
  st->minmaxX[1]=-9999;
  st->minmaxY[1]=-9999;
  st->minmaxZ[1]=-9999;
  st->minmaxX[0]=9999;
  st->minmaxY[0]=9999;
  st->minmaxZ[0]=9999;
  ssize_t read = 0;
  char *line = NULL;
  size_t size_line = 0;
  FILE *file = fopen(filename, "r");
  char *ptr = line;
  int vertex_counter = 0;
  int poligons_counter = 0;
  while ((read = getline(&line, &size_line, file)) != -1) {
    ptr = line;
    if (*ptr == 'v') {
      parse_vertex(&(st->v[vertex_counter]), ptr,st);
      vertex_counter++;
    } else if (*ptr == 'f') {
      memory_for_pol(ptr, &(st->p[poligons_counter]));
      ptr = line;
      parse_poligons(ptr, &(st->p[poligons_counter]));
      poligons_counter++;
    }
  }
  return *st;
}

int s21_fill_amount(char *filename, exit_st *st) {
  int status = 0;
  ssize_t read = 0;
  char *line = NULL;
  size_t size_line = 0;
  FILE *file = fopen(filename, "r");
  if (file != NULL) {
    while ((read = getline(&line, &size_line, file)) != -1) {
      if (line[0] == 'v' && line[1] == ' ') {
        st->amount_struct_ver += 1;
      }
      if (line[0] == 'f' && line[1] == ' ') {
        st->amount_struct_pol += 1;
      }
    }
    free(line);
    fclose(file);
  } else {
    status = 1;
  }
  return status;
}

int s21_init_struct(exit_st *st) {
  int status = 0;
  if ((st->p = (poligons *)calloc(st->amount_struct_pol, sizeof(poligons))) ==
      NULL) {
  }
  if ((st->v = (vertex *)calloc(st->amount_struct_ver, sizeof(vertex))) ==
      NULL) {
    status = 1;
  }
  return status;
}

void parse_vertex(vertex *v, char *ptr, exit_st *st) {
  ptr++;
  if (*ptr == ' ') {
    while (*ptr != '\0') {
      if (!isdigit(*ptr) && *ptr != '-') {
        ptr++;
      } else {
        v->x = strtod(ptr, &ptr);
        if(st->minmaxX[0]>v->x){
          st->minmaxX[0]= v->x;
          //Может не совсем правильно работать
        } else if(st->minmaxX[1]<v->x){
          st->minmaxX[1]= v->x;
        }

        while (*ptr == ' ') {
          ptr++;
        }
        v->y = strtod(ptr, &ptr);
        if(st->minmaxY[0]>v->x){
          st->minmaxY[0]= v->x;
        } else if(st->minmaxY[1]<v->x){
          st->minmaxY[1]= v->x;
        }
        while (*ptr == ' ') {
          ptr++;
        }
        v->z = strtod(ptr, &ptr);
        if(st->minmaxZ[0]>v->x){
          st->minmaxZ[0]= v->x;
        } else if(st->minmaxZ[1]<v->x){
          st->minmaxZ[1]= v->x;
        }
      }
    }
  }
}
int memory_for_pol(char *ptr, poligons *p) {
  int status = 0;
  ptr++;
  int amount_pol = 0;
  while (*ptr != '\0') {
    if (!isdigit(*ptr)) {
      ptr++;
    } else {
      amount_pol++;

      while (*ptr != ' ') {
        ptr++;
      }
    }
  }
  if ((p->poligon = (int *)calloc(amount_pol, sizeof(int))) == NULL) {
    status = 1;
  } else {
    p->amount_pol = amount_pol;
  }

  return status;
}
void parse_poligons(char *ptr, poligons *p) {
  ptr++;
  int i = 0;
  while (*ptr != '\0') {
    if (!isdigit(*ptr)) {
      ptr++;
    } else {
      p->poligon[i] = strtol(ptr, &ptr, 0);
      i++;
      while (*ptr != ' ') {
        ptr++;
      }
    }
  }
}
