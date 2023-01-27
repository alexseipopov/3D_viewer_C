#include "s21_3DViewer.h"

int main() {
  int status = 0;
  int amount_ver = 0;
  int amount_pol = 0;
  exit_st st = {0};
  st = s21_parse("test.obj");
  for (int i = 0; i < st.amount_struct_ver*3; i++) {
    printf("v %lf ", st.vertex[i]);
    printf("%lf ", st.vertex[i + 1]);
    printf("%lf\n", st.vertex[i + 2]);
    i += 2;
  }
  return 0;
}

exit_st s21_parse(char *filename) {
  exit_st *st = (exit_st *)calloc(1, sizeof(exit_st));
  int status = 0;
  status = s21_fill_amount(filename, st);
  s21_init_struct(st);
  // KOSTIIIIIL
  st->minmaxX[1] = -9999;
  st->minmaxY[1] = -9999;
  st->minmaxZ[1] = -9999;
  st->minmaxX[0] = 9999;
  st->minmaxY[0] = 9999;
  st->minmaxZ[0] = 9999;
  ssize_t read = 0;
  char *line = NULL;
  size_t size_line = 0;
  FILE *file = fopen(filename, "r");
  char *ptr = line;
  int poligons_counter = 0;
  int i = 0;
  while ((read = getline(&line, &size_line, file)) != -1) {
    ptr = line;
    if (*ptr == 'v') {
     i = parse_vertex(i, ptr, st);
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
  if ((st->vertex = (double *)calloc(st->amount_struct_ver * 4,
                                     sizeof(double))) == NULL) {
    status = 1;
  }
  return status;
}

int parse_vertex(int i, char *ptr, exit_st *st) {
  ptr++;
  if (*ptr == ' ') {
    while (*ptr != '\0') {
      if (!isdigit(*ptr) && *ptr != '-') {
        ptr++;
      } else {
        st->vertex[i] = strtod(ptr, &ptr);
        // if(st->minmaxX[0]>st->vertex[i]){
        //   st->minmaxX[0]= st->vertex[i];
        //   //Может не совсем правильно работать
        // } else if(st->minmaxX[1]<st->vertex[i]){
        //   st->minmaxX[1]= st->vertex[i];
        // }
         
        while (*ptr == ' ') {
          ptr++;
        }
        i++;
        st->vertex[i] = strtod(ptr, &ptr);
        // if(st->minmaxY[0]>st->vertex[i]){
        //   st->minmaxY[0]= st->vertex[i];
        // } else if(st->minmaxY[1]<st->vertex[i]){
        //   st->minmaxY[1]= st->vertex[i];
        // }
        while (*ptr == ' ') {
          ptr++;
        }
        i++;
        st->vertex[i] = strtod(ptr, &ptr);
        // if(st->minmaxZ[0]>v->x){
        //   st->minmaxZ[0]= v->x;
        // } else if(st->minmaxZ[1]<v->x){
        //   st->minmaxZ[1]= v->x;
        // }
        i++;
        }
      }
    }
  
  return i;
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