#include "function.h"

char rellena_array(FILE *libro_csv, struct struct_libro array_libros[]) {
  int i = 0;
  char buff[1024];
  fgets(buff, 1024, (FILE *)libro_csv);
  while (fgets(buff, 1024, libro_csv)) {
    int field_count = 0;
    char *field = strtok(buff, ",");

    while (field) {
      if (field_count == 0) {
        strcpy(array_libros[i].titulo, field);
        if (field[0] == '"') {
          while (field[strlen(field) - 1] != '"') {
            field = strtok(NULL, ",");
            strcat(array_libros[i].titulo, ",");
            strcat(array_libros[i].titulo, field);
          }
        }
      } else if (field_count == 1) {
        strcpy(array_libros[i].autor, field);
        if (field[0] == '"') {
          while (field[strlen(field) - 1] != '"') {
            field = strtok(NULL, ",");
            strcat(array_libros[i].autor, ",");
            strcat(array_libros[i].autor, field);
          }
        }
      } else if (field_count == 2)
        array_libros[i].anio = atoi(field);
      else if (field_count == 3)
        array_libros[i].estante_numero = atoi(field);
      else if (field_count == 4)
        strcpy(array_libros[i].estante_seccion, field);
      else if (field_count == 5)
        array_libros[i].piso = atoi(field);
      else if (field_count == 6)
        strcpy(array_libros[i].edificio, field);
      else if (field_count == 7)
        strcpy(array_libros[i].sede, field);
      field = strtok(NULL, ",");
      field_count++;
    }
    i++;
  }
  return 0;
}
