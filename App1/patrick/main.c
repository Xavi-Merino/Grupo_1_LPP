#include "function.h"

int main(int argc, char **argv) {
  printf("\n--------Inicio---------\n");
  // CSV a Array
  FILE *libro_csv = read_file(argv);

  int arr_size = cuenta_lineas(libro_csv);
  rewind(libro_csv);

  struct struct_libro array_libros[arr_size + 1024];
  rellena_array(libro_csv, array_libros);

  // Menu
  int flag = 1;
  int menu;

  while (flag) {
    print_menu();
    printf("\n\nIngrese el número de la acción: ");
    scanf("%d", &menu);

    switch (menu) {
      case 1:
        agregar_libro(array_libros, &arr_size);
        break;

      case 2:
        editar_libro(array_libros, arr_size);
        break;

      case 3:
        eliminar_libro(array_libros, arr_size);
        break;

      case 4:
        buscar_libro(array_libros, arr_size);
        break;

      case 5:
        eliminar_sede();
        break;

      case 6:
        flag = 0;
        break;

      default:
        break;
    }
  }

  csv_out(array_libros, arr_size);
  return 0;
}