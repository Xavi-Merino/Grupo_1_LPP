#include "function.h"

int buscar_libro(struct struct_libro array_libros[], int arr_size) {
  char titulo[100];
  char temp;
  printf("\nPara buscar un libro, ingrese el titulo en doble comillas: ");
  scanf("%c", &temp);
  scanf("%[^\n]%*c", titulo);

  for (int i = 0; i <= arr_size; i++) {
    if (strcmp(titulo, array_libros[i].titulo) == 0) {
      printf("\ntitulo:             %s", array_libros[i].titulo);
      printf("\nautor:              %s", array_libros[i].autor);
      printf("\nanio:               %i", array_libros[i].anio);
      printf("\nnumero de estante:  %d", array_libros[i].estante_numero);
      printf("\nseccion de estante: %s", array_libros[i].estante_seccion);
      printf("\npiso:               %d", array_libros[i].piso);
      printf("\nedificio:           %s", array_libros[i].edificio);
      printf("\nsede:               %s", array_libros[i].sede);
    }
  }
  return 0;
}