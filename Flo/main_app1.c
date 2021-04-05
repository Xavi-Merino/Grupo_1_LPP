#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "struct_libro.h"

/* NO VA A FUNCIONAR SI EL TITULO TIENE COMA EN EL NOMBRE*/

struct struct_libro
{
    char titulo[75];
    char autor[50];
    int anio;
    int estante_numero;
    char estante_seccion[50];
    int piso;
    char edificio[25];
    char sede[20];
} struct_libro;

FILE *read_file(void)
{
  FILE *archivo_csv = fopen("ejemplo.csv", "r");
  if (archivo_csv == NULL)
  {
    printf("el archivo no pudo ser abierto");
    exit(1);
  }

  return archivo_csv;
}

int cuenta_lineas(FILE *libro_csv)
{
  int contador = 0;
  for (char c = fgetc(libro_csv); c != EOF; c = fgetc(libro_csv))
  {
    if (c == '\n')
    {
      contador++;
    }
  }
  return contador;
}

char f_populate(FILE *libro_csv, struct struct_libro values[], int n_lineas) /* im having trouble here */
{
  int i = 0;
  char buff[n_lineas];
  fgets(buff, 200, (FILE *)libro_csv);
  while (fgets(buff, n_lineas, libro_csv))
  {
    int field_count = 0;
    if (n_lineas == 1)
      continue;

    int commas = 0;

    if (*buff == '"')
    {
      int index = 1;
      while (*(buff + index) != '"')
      {

        if (*(buff + index) == ',')
        {
          ++commas;
        }
        ++index;
      }
    }

    char *field = strtok(buff, ",");

    while (field)
    {

      if (field_count == 0)
      {
        strcpy(values[i].titulo, field);
        while (commas--)
        {
          field = strtok(NULL, ",");
          strcat(values[i].titulo, field);
        }
      }

      if (field_count == 1)
        strcpy(values[i].autor, field);
      if (field_count == 2)
        values[i].anio = atoi(field);
      if (field_count == 3)
        values[i].estante_numero = atoi(field);
      if (field_count == 4)
        strcpy(values[i].estante_seccion, field);
      if (field_count == 5)
        values[i].piso = atoi(field);
      if (field_count == 6)
        strcpy(values[i].edificio, field);
      if (field_count == 7)
        strcpy(values[i].sede, field);
      field = strtok(NULL, ",");
      field_count++;
    }
    i++;
  }
  return 0;
}

//Menú principal
void printmenu()
{
  printf("Bienvenido/a a la Biblioteca UAI. ¿Qué desea hacer?\n");

  printf("   1. ¿Deseas agregar algo?\n");
  printf("   2. ¿Deseas quitar algo?\n");
  printf("   3. ¿Deseas editar algo de algun libro?\n");
  printf("   4. ¿Desea buscar un libro?\n");
  printf("   5. Salir\n");
}

//Submenu 1
void print_agregar_cosas()
{
  printf("¿Qué desea agregar?\n");

  printf("   1. Agregar un libro a la Bibloteca\n");
  printf("   2. Agregar una sede\n");
  printf("   3. Agregar secciones\n");
  printf("   4. Agregar un piso\n");
}

//Submenu 2
void print_quitar_cosas()
{
  printf("¿Qué desea quitar?\n");

  printf("   1. Quitar un libro de la Biblioteca\n");
  printf("   2. Quitar una sede (sólo si no hay libros)\n");
  printf("   3. Eliminar secciones (sólo si no hay libros)\n");
  printf("   4. Eliminar piso (sólo si no hay libros)\n");
}

//Submenu 3
void print_editar_libro()
{ // A qué se refiere con editar
  printf("¿Que campo quiere editar?\n");
  printf("   1. Cambiar el titulo de un libro\n");
  printf("   2. Cambiar la seccion de un libro\n");
  printf("   3. Cambiar el piso del libro\n");
  printf("   4. Cambiar la sede del libro\n");
  printf("   5. Cambiar el autor de un libro\n");
  printf("   6. Cambiar el año de un libro\n");
  printf("   7. Cambiar el el numero del estante de un libro\n");

  //titulo,autor,anio,estante_numero,estante_seccion,piso,edificio,sede
}

void agregar_libro()
{
  struct struct_libro libro;

  printf("Ingrese el titulo del libro: ");
  scanf("%[^\n]%*c", libro.titulo);
  printf("ingrese autor del libro: ");
  scanf("%[^\n]%*c", libro.autor);
  printf("ingrese anio del libro: ");
  scanf("%i\n", &libro.anio);
  printf("ingrese el numero del estante en donde se encuentra el libro: ");
  scanf("%i\n", &libro.estante_numero);
  printf("ingrese la seccion en la cual se encuentra el libro: ");
  scanf("%[^\n]%*c", libro.estante_seccion);
  printf("\ningrese el piso del edificio en donde se encuentra el libro: ");
  scanf("%i\n", &libro.piso);
  printf("ingrese la letra del edificio en donde se encuentra el libro: ");
  scanf("%[^\n]%*c", libro.edificio);
  printf("ingrese la sede en donde se encuentra el libro: ");
  scanf("%[^\n]%*c", libro.sede);

  printf("Titulo: %s\n Autor: %s\n Anio: %i\n  ", libro.titulo, libro.autor,
         libro.anio);
};

// int quitarlibro(struct libro_data libro);
// int agregarsede(struct libro_data libro);
// int quitarsede(struct libro_data libro);

// int cambio_sede_libro(struct libro_data libro);
// int cambio_secc_libro(struct libro_data libro);
// int cambio_piso_libro(struct libro_data libro);
// int agregar_secc(struct libro_data libro);
// int eliminar_secc(struct libro_data libro);
// int agregar_pisos(struct libro_data libro);
// int eliminar_pisos(struct libro_data libro);
// int buscar_libro(struct libro_data libro);
// int inventario(struct libro_data libro);


int buscarlibro(struct struct_libro values[], int arr_size){
  char titulo[100];
  int fila;
  printf("para editar un libro, ingrese el titulo: \n");
  scanf("%s", titulo);
  for (int i = 0; i<= arr_size; i++ ){
      if(strcmp(titulo, values[i].titulo) == 0){
          printf("%d\n", i);
          fila = i;
      }
  }
  return fila;
}

int main(int argc, char **argv)
{
  FILE *libro_csv = read_file();
  int arr_size = cuenta_lineas(libro_csv);
  printf("tamano del array: %i\n", arr_size);
  rewind(libro_csv);
  printf("alo\n");
  struct struct_libro values[arr_size];
  f_populate(libro_csv, values, arr_size);

  printf("Nombre del titulo: %s\n", values[0].titulo);

  int flag = 1;
  int menu;

  while (flag)
  {
    printmenu();
    printf("\n");
    printf("Ingrese el número de la acción: ");
    scanf("%d", &menu);

    switch (menu)
    {
    case 1:
      agregar_libro();
      scanf("Ingrese su opción %d", &menu);
      // if (menu==1) agregar_libro();
      // if (menu==2) agregar_sede();
      // if (menu==3) agregar_secciones();
      // if (menu==4) agrega_piso();
      break;

    case 2:
      print_quitar_cosas();
      scanf("Ingrese su opción %d", &menu);
      //if(menu == 1) quitarlibro();
      //if(menu == 2) quitarsede();
      //if(menu == 3) eliminarseccion();
      //if(menu == 4) eliminarpiso();
      break;

    case 3:
      print_editar_libro();
      scanf("Ingrese su opción %d", &menu);

      //Falta editar esto para incluir el nombre del archivo y escoger el campo a editar.
      //editarlibro(values[], arr_size);
      
      break;

    case 4: ;
      int fila;
      fila = buscarlibro(values, arr_size);
      printf("Título: %s\nAutor: %s\nAño: %d\nNº Estante: %d\nSección: %s\nPiso: %d\nEdificio: %s\nSede: %s\n", 
        values[fila].titulo, 
        values[fila].autor,
        values[fila].anio,
        values[fila].estante_numero,
        values[fila].estante_seccion,
        values[fila].piso,
        values[fila].edificio,
        values[fila].sede);
      
      break;

    case 5:
      flag = 0;
      break;

    default:
      break;
    }
  }

  return 0;
}