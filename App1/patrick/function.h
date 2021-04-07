#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

FILE *read_file(char **argv);

int cuenta_lineas(FILE *libro_csv);

char rellena_array(FILE *libro_csv, struct struct_libro array_libros[]);

void print_menu();

int buscar_libro(struct struct_libro array_libros[], int arr_size);

int agregar_libro(struct struct_libro array_libros[], int *index);

int editar_libro(struct struct_libro array_libros[], int arr_size);

int eliminar_libro(struct struct_libro array_libros[], int arr_size);

void eliminar_sede(void);

int csv_out(struct struct_libro array_libros[], int original_size);
