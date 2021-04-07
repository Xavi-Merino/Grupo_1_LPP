#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "function.h"

int cuenta_lineas(FILE *libro_csv) {
  int contador = 0;
  for (char c = fgetc(libro_csv); c != EOF; c = fgetc(libro_csv)) {
    if (c == '\n') {
      contador++;
    }
  }
  return contador;
}
