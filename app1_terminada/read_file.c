#include "function.h"

FILE *read_file(char **argv) {
  FILE *archivo_csv = fopen(argv[1], "r");

  if (archivo_csv == NULL) {
    printf("\nEl archivo no pudo ser abierto\n");
    exit(1);
  }

  return archivo_csv;
}