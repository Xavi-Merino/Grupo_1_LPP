#include "function.h"

int agregar_libro(struct struct_libro array_libros[], int *index) {
  char temp;
  // cuantos libros quiere agregar?
  printf("\nCuantos libros quiere agregar?");
  printf("\nIngrese numero: ");
  int n_a;
  scanf("%i", &n_a);
  scanf("%c", &temp);

  n_a += *index;
  int cont = 1;
  for (int p = *index; p < n_a; p++) {
    printf("\n--------libro %i-----------\n", cont);
    printf("Ingrese el titulo del libro en doble comillas: ");
    scanf("%[^\n]%*c", array_libros[p].titulo);

    printf("Ingrese autor del libro: ");
    scanf("%[^\n]%*c", array_libros[p].autor);

    printf("Ingrese anio del libro: ");
    scanf("%d", &array_libros[p].anio);
    scanf("%c", &temp);

    printf("Ingrese el numero del estante en donde se encuentra el libro: ");
    scanf("%d", &array_libros[p].estante_numero);
    scanf("%c", &temp);

    printf("Ingrese la seccion(en letras) en la cual se encuentra el libro: ");
    scanf("%[^\n]%*c", array_libros[p].estante_seccion);

    printf("Ingrese el piso del edificio en donde se encuentra el libro: ");
    scanf("%d", &array_libros[p].piso);
    scanf("%c", &temp);

    printf("Ingrese la letra del edificio en donde se encuentra el libro: ");
    scanf("%s", array_libros[p].edificio);
    scanf("%c", &temp);

    printf(
        "Ingrese la sede (vina o santiago) en donde se encuentra el libro: ");
    scanf("%[^\n]%*c", array_libros[p].sede);

    printf("Se agrego: '%s' de manera exitosa!\n", array_libros[p].titulo);
    ++(*index);
    ++cont;
  }

  return 0;
};
