#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "function.h"

struct struct_libro {
  char titulo[100];
  char autor[100];
  int anio;
  int estante_numero;
  char estante_seccion[50];
  int piso;
  char edificio[10];
  char sede[20];
};

void eliminar_sede(void) { printf("\nno se pueden eliminar sedes"); }
