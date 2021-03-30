#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *read_file(void) {
  FILE *archivo_csv = fopen("ejemplo.csv", "r");
  if (archivo_csv == NULL) {
    printf("el archivo no pudo ser abierto");
    exit(1);
  }

  return archivo_csv;
}

int cuenta_lineas(FILE *libro_csv) {
  int contador = 0;
  for (char c = fgetc(libro_csv); c != EOF; c = fgetc(libro_csv)) {
    if (c == '\n') {
      contador++;
    }
  }
  return contador;
}

int main() {
  FILE *libro_csv = read_file();
  int n_lineas = cuenta_lineas(libro_csv);
  rewind(libro_csv);
  printf("tamano del array: %i\n", n_lineas);
  char buff[n_lineas];

  struct struct_libro values[n_lineas];

  int i = 0;
  fgets(buff, 200, (FILE *)libro_csv);
  while (fgets(buff, n_lineas, libro_csv)) {
    int field_count = 0;
    if (n_lineas == 1) continue;
    char *field = strtok(buff, ",");
    while (field) {
      if (field_count == 0) strcpy(values[i].titulo, field);
      if (field_count == 1) strcpy(values[i].autor, field);
      if (field_count == 2) values[i].anio = atoi(field);
      if (field_count == 3) values[i].estante_numero = atoi(field);
      if (field_count == 4) strcpy(values[i].estante_seccion, field);
      if (field_count == 5) values[i].piso = atoi(field);
      if (field_count == 6) strcpy(values[i].edificio, field);
      if (field_count == 7) strcpy(values[i].sede, field);
      field = strtok(NULL, ",");
      field_count++;
    }
    i++;
  }

  printf("%i\n", values[100].anio);
}