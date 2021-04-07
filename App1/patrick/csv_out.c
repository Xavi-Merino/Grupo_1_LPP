#include "function.h"

int csv_out(struct struct_libro array_libros[], int original_size) {
  FILE *fp;
  int i;
  fp = fopen("prueba.csv", "w");
  fprintf(
      fp,
      "titulo,autor,anio,estante_numero,estante_seccion,piso,edificio,sede\n");

  for (i = 0; i < original_size; i++) {
    fprintf(fp, "%s,%s,%d,%d,%s,%d,%s,%s\n", array_libros[i].titulo,
            array_libros[i].autor, array_libros[i].anio,
            array_libros[i].estante_numero, array_libros[i].estante_seccion,
            array_libros[i].piso, array_libros[i].edificio,
            array_libros[i].sede);
  }

  fclose(fp);
  return 0;
}
