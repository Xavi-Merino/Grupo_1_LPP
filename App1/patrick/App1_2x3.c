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

FILE *read_file(char **argv) {
  FILE *archivo_csv = fopen(argv[1], "r");

  if (archivo_csv == NULL) {
    printf("\nEl archivo no pudo ser abierto\n");
    exit(1);
  }

  return archivo_csv;
}

int cuenta_lineas(FILE *libro_csv) {
  int contador = 0;
  for (char c = fgetc(libro_csv); c != EOF; c = fgetc(libro_csv)) {
    if (c == '\n') {
      contador++;
    }
  }
  return contador;
}

char rellena_array(FILE *libro_csv, struct struct_libro array_libros[]) {
  int i = 0;
  char buff[1024];
  fgets(buff, 1024, (FILE *)libro_csv);
  while (fgets(buff, 1024, libro_csv)) {
    int field_count = 0;
    char *field = strtok(buff, ",");

    while (field) {
      if (field_count == 0) {
        strcpy(array_libros[i].titulo, field);
        if (field[0] == '"') {
          while (field[strlen(field) - 1] != '"') {
            field = strtok(NULL, ",");
            strcat(array_libros[i].titulo, ",");
            strcat(array_libros[i].titulo, field);
          }
        }
      } else if (field_count == 1) {
        strcpy(array_libros[i].autor, field);
        if (field[0] == '"') {
          while (field[strlen(field) - 1] != '"') {
            field = strtok(NULL, ",");
            strcat(array_libros[i].autor, ",");
            strcat(array_libros[i].autor, field);
          }
        }
      } else if (field_count == 2)
        array_libros[i].anio = atoi(field);
      else if (field_count == 3)
        array_libros[i].estante_numero = atoi(field);
      else if (field_count == 4)
        strcpy(array_libros[i].estante_seccion, field);
      else if (field_count == 5)
        array_libros[i].piso = atoi(field);
      else if (field_count == 6)
        strcpy(array_libros[i].edificio, field);
      else if (field_count == 7)
        strcpy(array_libros[i].sede, field);
      field = strtok(NULL, ",");
      field_count++;
    }
    i++;
  }
  return 0;
}

void print_menu() {
  printf("\n\nBienvenido/a a la Biblioteca UAI. ¿Qué desea hacer?\n");
  printf("\n   1. ¿Deseas agregar un libro?");
  printf("\n   2. ¿Deseas editar un libro?");
  printf("\n   3. ¿Deseas eliminar un libro?");
  printf("\n   4. ¿Desea buscar un libro?");
  printf("\n   5. ¿Deseas eliminar una sede?");
  printf("\n   6. Salir");
}

int buscar_libro(struct struct_libro array_libros[], int arr_size) {
  char titulo[100];
  char temp;
  printf("\nPara buscar un libro, ingrese el titulo en doble comillas: ");
  scanf("%c", &temp);
  scanf("%[^\n]%*c", titulo);

  for (int i = 0; i <= arr_size; i++) {
    if (strcmp(titulo, array_libros[i].titulo) == 0) {
      printf("\ntitulo:             %s", array_libros[i].titulo);
      printf("\nautor:               %s", array_libros[i].autor);
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

int editar_libro(struct struct_libro array_libros[], int arr_size) {
  char titulo[20];
  char temp;

  printf("\npara editar un libro, ingrese el titulo: ");
  scanf("%c", &temp);
  scanf("%[^\n]%*c", titulo);
  printf("\nEditaremos: %s\n", titulo);

  for (int i = 0; i <= arr_size; i++) {
    if (strcmp(titulo, array_libros[i].titulo) == 0) {
      int opcion = 0;
      printf("\n---Elija el numero de la opcion que quiere editar---");
      printf("\n1) Cambiar titulo");
      printf("\n2) Cambiar autor");
      printf("\n3) Cambiar anio");
      printf("\n4) Cambiar numero de estante");
      printf("\n5) Cambiar seccion");
      printf("\n6) Cambiar piso");
      printf("\n7) Cambiar edificio");
      printf("\n8) Cambiar sede");
      printf("\n9) Volver al menu");
      printf("\nIngrese numero: ");

      scanf("%d", &opcion);
      if (opcion == 1) {
        char cambio_titulo[100];
        printf("\nEl titulo actual del libro es: %s", array_libros[i].titulo);
        printf("\nIngrese el nuevo titulo: ");
        scanf("%c", &temp);
        scanf("%[^\n]%*c", cambio_titulo);
        strcpy(array_libros[i].titulo, cambio_titulo);
        printf("\nNuevo titulo: %s", array_libros[i].titulo);
      } else if (opcion == 2) {
        char cambio_autor[100];
        printf("\nEl/los autores actuales son: %s", array_libros[i].autor);
        printf("\nIngrese el nuevo autor: ");
        scanf("%c", &temp);
        scanf("%[^\n]%*c",
              cambio_autor); /*raios, no acepta nombres con espacio*/
        strcpy(array_libros[i].autor, cambio_autor);
        printf("\nNuevo autor: %s", array_libros[i].autor);
      } else if (opcion == 3) {
        int cambio_anio;
        printf("\nEl anio actual es: %d", array_libros[i].anio);
        printf("\nIngrese el nuevo anio: ");
        scanf("%c", &temp);
        scanf("%d", &cambio_anio);
        array_libros[i].anio = cambio_anio;
        printf("\nNuevo anio: %d", array_libros[i].anio);
      } else if (opcion == 4) {
        int cambio_estante;
        printf("\nEl numero de estante actual es: %d",
               array_libros[i].estante_numero);
        printf("\nIngrese el nuevo numero de estante: ");
        scanf("%c", &temp);
        scanf("%d", &cambio_estante);
        array_libros[i].estante_numero = cambio_estante;
        printf("\nEl libro ahora se encuentra en el estante: %d",
               array_libros[i].estante_numero);
      } else if (opcion == 5) {
        char cambio_seccion[10];
        printf("\nEl libro se encuentra actualmente en la seccion de: %s",
               array_libros[i].estante_seccion);
        printf("\nIngrese la seccion a la cual desea mover el libro: ");
        scanf("%c", &temp);
        scanf("%[^\n]%*c", cambio_seccion);
        strcpy(array_libros[i].estante_seccion, cambio_seccion);
        printf("\nEl libro se encuentra ahora en la seccion: %s",
               array_libros[i].estante_seccion);
      } else if (opcion == 6) {
        int cambio_piso;
        printf("\nEl numero del piso actual es: %d",
               array_libros[i].estante_numero);
        printf("\nIngrese a que piso cambiara el libro: ");
        scanf("%c", &temp);
        scanf("%d", &cambio_piso);
        array_libros[i].piso = cambio_piso;
        printf("\nEl libro se encuentra ahora en el piso: %d",
               array_libros[i].estante_numero);
      } else if (opcion == 7) {
        char cambio_edificio[10];
        printf("\nEl libro se encuentra actualmente en el edificio: %s",
               array_libros[i].edificio);
        printf("\nIngrese a que edificio movera el libro: ");
        scanf("%c", &temp);
        scanf("%[^\n]%*c", cambio_edificio);
        strcpy(array_libros[i].edificio, cambio_edificio);
        printf("\nEl libro se encuentra ahora en el edificio: %s",
               array_libros[i].edificio);
      } else if (opcion == 8) {
        char cambio_sede[20];
        printf("\nEl libro se encuentra actualmente en la sede: %s",
               array_libros[i].sede);
        printf("\nIngrese a que sede (vina o santiago) movera el libro: ");
        scanf("%c", &temp);
        scanf("%[^\n]%*c", cambio_sede);
        strcpy(array_libros[i].sede, cambio_sede);
        printf("\nEl libro se encuentra ahora en la sede: %s",
               array_libros[i].sede);
      } else if (opcion == 9) {
        scanf("%c", &temp);
        return 0;
      }
    }
  }

  return 0;
}

int eliminar_libro(struct struct_libro array_libros[], int arr_size) {
  char titulo[100];
  char temp;

  printf(
      "\nIntroduzca el titulo del libro del cual desea eliminar elementos: ");
  scanf("%c", &temp);
  scanf("%[^\n]%*c", titulo);
  printf("\nEl libro seleccionado es : %s", titulo);

  for (int i = 0; i <= arr_size; i++) {
    if (strcmp(titulo, array_libros[i].titulo) == 0) {
      int opcion = 0;
      printf("\n\n---estas seguro de que quieres eliminarlo?---");
      printf("\n1) Si");
      printf("\n2) Volver al menu");
      printf("\nIngrese numero: ");
      scanf("%d", &opcion);
      if (opcion == 1) {
        int c;
        int numero_libro;
        printf("\nEl numero del libro es: %i", i);
        scanf("%c", &temp);
        printf(
            "\nPara confirmar que quiere eliminar el libro escriba el numero "
            "del libro: ");
        scanf("%i", &numero_libro);

        if (numero_libro >= arr_size)
          printf("\nSe equivoco de numero porfavor intentelo denuevo.");
        else {
          for (c = numero_libro; c < arr_size; c++)
            array_libros[c] = array_libros[c + 1];
        }
        printf("\nSe a eliminado de manera exitosa\n");
      }

      if (opcion == 2) {
        return 0;
      }
    }
  }
  return 0;
}

void eliminar_sede(void) { printf("\nno se pueden eliminar sedes"); }

int csv_out(struct struct_libro array_libros[], int original_size) {
  FILE *fp;
  int i;
  fp = fopen("prueba.csv", "w");
  fprintf(
      fp,
      "titulo,autor,anio,estante_numero,estante_seccion,piso,edificio,sede\n");

  for (i = 0; i < original_size - 1; i++) {
    fprintf(fp, "%s,%s,%d,%d,%s,%d,%s,%s", array_libros[i].titulo,
            array_libros[i].autor, array_libros[i].anio,
            array_libros[i].estante_numero, array_libros[i].estante_seccion,
            array_libros[i].piso, array_libros[i].edificio,
            array_libros[i].sede);
  }

  fclose(fp);
  return 0;
}

int main(int argc, char **argv) {
  printf("\n--------Inicio---------\n");
  // CSV a Array
  FILE *libro_csv = read_file(argv); /*cambiar la forma*/

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

  return 0;
}