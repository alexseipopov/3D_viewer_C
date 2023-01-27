#include "s21_3DViewer.h"

int main() {
  int status = 0;
  int amount_ver = 0;
  int amount_pol = 0;
  exit_st *st = (exit_st *)calloc(1, sizeof(exit_st));
  status = s21_parse(st, "test.obj");
  // printf("%d",st->amount_struct_ver);
  //  for (int i = 0; i < st->amount_struct_ver *3; i++) {
  //    printf("v %lf ", st->vertex[i]);
  //    printf("%lf ", st->vertex[i + 1]);
  //    printf("%lf\n", st->vertex[i + 2]);
  //    i += 2;
  //  }
  for (int i = 0; i < st->amount_struct_pol; i++) {
    printf(" %d", st->poligons[i]);
  }
  s21_remove_struct(st);
  free(st);
  return 0;
}

int s21_parse(exit_st *st, char *filename) {
  int status = 0;
  ssize_t read = 0;
  char *line = NULL;
  size_t size_line = 0;
  FILE *file = fopen(filename, "r");
  char *ptr = line;
  int poligons_counter = 0;
  int vertex_counter = 0;
  int capacity_ver = 3;
  int capacity_pol = 3;
  s21_init_struct(st);
  if (!status) {
    while ((read = getline(&line, &size_line, file)) != -1) {
      ptr = line;
      if (*ptr == 'v') {
        parse_vertex(&vertex_counter, ptr, st, &capacity_ver);
        st->amount_struct_ver++;
      } else if (*ptr == 'f') {
        parse_poligons(ptr, st, &poligons_counter, &capacity_pol);
      }
    }
  }
  free(line);
  fclose(file);

  st->amount_struct_pol = poligons_counter;
  return status;
}

int s21_init_struct(exit_st *st) {
  int status = 0;
  st->amount_struct_pol = 0;
  st->amount_struct_ver = 0;
  // KOSTIIIIIL
  st->minmaxX[1] = -9999;
  st->minmaxY[1] = -9999;
  st->minmaxZ[1] = -9999;
  st->minmaxX[0] = 9999;
  st->minmaxY[0] = 9999;
  st->minmaxZ[0] = 9999;
  if ((st->poligons = (int *)calloc(3, sizeof(int))) == NULL) {
    status = 1;
  }
  if ((st->vertex = (double *)calloc(3, sizeof(double))) == NULL) {
    status = 1;
  }
  return status;
}

int parse_vertex(int *vertex_counter, char *ptr, exit_st *st,
                 int *capacity_ver) {
  int status = 0;
  ptr++;
  if (*ptr == ' ') {
    while (*ptr != '\0') {
      if (!isdigit(*ptr) && *ptr != '-') {
        ptr++;
      } else {
        if (*vertex_counter < *capacity_ver) {
          st->vertex[*vertex_counter] = strtod(ptr, &ptr);
          *vertex_counter += 1;
          while (*ptr == ' ') {
            ptr++;
          }
        } else {
          double *tmp;
          *capacity_ver *= 2;
          if ((tmp = realloc(st->vertex, *capacity_ver * sizeof(double))) ==
              NULL) {
            return 1;
          } else {
            st->vertex = tmp;
          }
        }
      }
    }
  }
  return status;
}

int parse_poligons(char *ptr, exit_st *st, int *poligons_counter,
                   int *capacity_pol) {
  ptr++;
  int i = 0;
  int status = 0;
  int first_poligon = 0;
  int tmp_pol = 0;
  if (*ptr == ' ') {
    while (*ptr != '\0') {
      if (!isdigit(*ptr)) {
        ptr++;
      } else {
        if (*poligons_counter < *capacity_pol - 1) {
          if (i == 0) {
            st->poligons[*poligons_counter] = strtol(ptr, &ptr, 0);
            first_poligon = st->poligons[*poligons_counter];
            *poligons_counter += 1;
            i++;
          } else {
            tmp_pol = strtol(ptr, &ptr, 0);
            st->poligons[*poligons_counter] = tmp_pol;
            *poligons_counter += 1;
            st->poligons[*poligons_counter] = tmp_pol;
            *poligons_counter += 1;
          }
          while (*ptr != ' ') {
            ptr++;
          }
        } else {
          int *tmp;
          *capacity_pol *= 2;
          if ((tmp = realloc(st->poligons, *capacity_pol * sizeof(int))) ==
              NULL) {
            return 1;
          } else {
            st->poligons = tmp;
          }
        }
      }
    }
    st->poligons[*poligons_counter] = first_poligon;
    *poligons_counter += 1;
  }
  return status;
}

void s21_remove_struct(exit_st *st) {
  free(st->vertex);
  free(st->poligons);
}