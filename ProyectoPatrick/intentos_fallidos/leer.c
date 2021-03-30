#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "struct_libro.h"

const char* getfield(char* line, int num) {
  const char* tok;
  for (tok = strtok(line, ";"); tok && *tok; tok = strtok(NULL, ";\n")) {
    if (!--num) return tok;
  }
  return NULL;
}

int main() {
  struct libro libros[50];
  int i = 0;

  FILE* stream = fopen("ejemplo.csv", "r");

  char line[1024];
  while (fgets(line, 1024, stream)) {
    char* tmp = strdup(line);

    printf("%s\n", getfield(tmp, 3));

    // strcpy(libros[i].titulo, getfield(tmp, 1));
    // strcpy(libros[i].autor, getfield(tmp, 2));
    // libros[i].anio = atoi(getfield(tmp, 3));
    // libros[i].estante_numero = atoi(getfield(tmp, 4));
    // strcpy(libros[i].estante_seccion, getfield(tmp, 5));
    // libros[i].piso = atoi(getfield(tmp, 6));
    // strcpy(libros[i].edificio, getfield(tmp, 7));
    // strcpy(libros[i].sede, getfield(tmp, 8));

    free(tmp);
    i++;
  }

  // for (int k = 0; k < j; k++) {
  //   printf("%s\n", libros[k].autor);
  // }
}