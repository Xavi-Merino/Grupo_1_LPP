#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "struct_libro.h"

void printmenu() {
  printf("\nAcá están las opciones\n");
  printf("  1. Agregar un libro\n");
  printf("  2. Remover un libro\n");
}

struct biblioteca* nuevo_item() {
  struct biblioteca* temp =
      (struct biblioteca*)malloc(sizeof(struct biblioteca));
  return (temp);
}

struct libro* agregar_libro() {
  struct libro* temp = (struct libro*)malloc(sizeof(struct libro));

  printf("Ingrese el titulo del libro: ");
  scanf("%s", temp->titulo);
  printf("Ingrese autor del libro: ");
  scanf("%s", temp->autor);
  printf("Ingrese anio del libro: ");
  scanf("%d", &temp->anio);
  printf("Ingrese el numero del estante en donde se encuentra el libro: ");
  scanf("%d", &temp->estante_numero);
  printf("Ingrese la seccion en la cual se encuentra el libro: ");
  scanf("%s", temp->estante_seccion);
  printf("Ingrese el piso del edificio en donde se encuentra el libro: ");
  scanf("%d", &temp->piso);
  printf("Ingrese la letra del edificio en donde se encuentra el libro: ");
  scanf("%s", temp->edificio);
  printf("Ingrese la sede en donde se encuentra el libro: ");
  scanf("%s", temp->sede);

  printf("\nTitulo: %s\n Autor: %s\n  Anio: %i\n  ", temp->titulo, temp->autor,
         temp->anio);
  return (temp);
}

int main(int argc, char** argv) {
  // creando un menú de opciones
  struct biblioteca* root = nuevo_item();
  root->libro = NULL;
  root->siguiente = NULL;

  struct biblioteca* tail;
  tail = root;

  int i = 1;
  int menu;

  while (i) {
    printmenu();
    printf("\n---> ");
    scanf("%d", &menu);

    switch (menu) {
      case 1:
        printf("menu 1\n\n");
        if (tail->libro == NULL) {
          tail->libro = agregar_libro();
        } else {
          tail->siguiente = nuevo_item();
          tail->siguiente->libro = agregar_libro();
          tail = tail->siguiente;
          tail->siguiente = NULL;
        }
        break;
      case 2:
        printf("menu 2\n\n");
        i = 0;
        break;
      default:
        break;
    }
  }
}
