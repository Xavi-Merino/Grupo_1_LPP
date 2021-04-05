#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct struct_libro
{
    char titulo[100];
    char autor[100];
    int anio;
    int estante_numero;
    char estante_seccion[50];
    int piso;
    char edificio[10];
    char sede[20];
};

FILE *read_file(void)
{
    FILE *archivo_csv = fopen("ejemplo1.csv", "r");
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

char f_populate(FILE *libro_csv, struct struct_libro values[])
{
    int i = 0;
    char buff[1024];
    fgets(buff, 1024, (FILE *)libro_csv);
    while (fgets(buff, 1024, libro_csv))
    {
        int field_count = 0;

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
            int skip = 0;
            if (field_count == 0)
            {
                strcpy(values[i].titulo, field);
                if (field[0] == '"')
                {
                    while (field[strlen(field) - 1] != '"')
                    {
                        field = strtok(NULL, ",");
                        strcat(values[i].titulo, ",");
                        strcat(values[i].titulo, field);
                    }
                }
            }
            else if (field_count == 1)
            {
                strcpy(values[i].autor, field);
                if (field[0] == '"')
                {
                    while (field[strlen(field) - 1] != '"')
                    {
                        field = strtok(NULL, ",");
                        strcat(values[i].autor, ",");
                        strcat(values[i].autor, field);
                    }
                }
            }
            else if (field_count == 2)
                values[i].anio = atoi(field);
            else if (field_count == 3)
                values[i].estante_numero = atoi(field);
            else if (field_count == 4)
                strcpy(values[i].estante_seccion, field);
            else if (field_count == 5)
                values[i].piso = atoi(field);
            else if (field_count == 6)
                strcpy(values[i].edificio, field);
            else if (field_count == 7)
                strcpy(values[i].sede, field);
            field = strtok(NULL, ",");
            field_count++;
        }
        i++;
    }
    return 0;
}

void printmenu()
{
  printf("Bienvenido/a a la Biblioteca UAI. ¿Qué desea hacer?\n");

  printf("   1. ¿Deseas agregar algo?\n");
  printf("   2. ¿Deseas quitar algo?\n");
  printf("   3. ¿Deseas editar algo de algun libro?\n");
  printf("   4. ¿Desea buscar un libro?\n");
  printf("   5. Salir\n");
}

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


int agregar_libro(struct struct_libro libro_agregado[], int *index)
{
    char temp;
    //cuantos libros quiere agregar?
    printf("Cuantos libros quiere agregar?\n");
    printf("Ingrese numero: ");
    int n_a;
    scanf("%i", &n_a);
    scanf("%c", &temp);
    printf("-------------------\n");

    n_a += *index;
    int cont = 1;
    for (int p = *index; p < n_a; p++)
    {

        printf("--------libro %i-----------\n", cont);
        printf("Ingrese el titulo del libro: ");
        scanf("%[^\n]%*c", libro_agregado[p].titulo);

        printf("Ingrese autor del libro: ");
        scanf("%[^\n]%*c", libro_agregado[p].autor);

        printf("Ingrese anio del libro: ");
        scanf("%d", &libro_agregado[p].anio);
        scanf("%c", &temp);

        printf("Ingrese el numero del estante en donde se encuentra el libro: ");
        scanf("%d", &libro_agregado[p].estante_numero);
        scanf("%c", &temp);

        printf("Ingrese la seccion(en letras) en la cual se encuentra el libro: ");
        scanf("%s", libro_agregado[p].estante_seccion);

        printf("Ingrese el piso del edificio en donde se encuentra el libro: ");
        scanf("%d", &libro_agregado[p].piso);
        scanf("%c", &temp);

        printf("Ingrese la letra del edificio en donde se encuentra el libro: ");
        scanf("%s", libro_agregado[p].edificio);
        scanf("%c", &temp);

        printf("Ingrese la sede en donde se encuentra el libro: ");
        scanf("%[^\n]%*c", libro_agregado[p].sede);

        printf("Se agrego: '%s' de manera exitosa!\n", libro_agregado[p].titulo);
        ++(*index);
        ++cont;
    }

    return 0;
};

int editar_libro(struct struct_libro values[], int arr_size)
{
    char titulo[20];
    char temp;

    printf("para editar un libro, ingrese el titulo: ");
    scanf("%[^\n]%*c", titulo);
    printf("Editaremos: %s\n", titulo);
    printf("-------------------\n");

    for (int i = 0; i <= arr_size; i++)
    {
        if (strcmp(titulo, values[i].titulo) == 0)
        {
            int opcion = 0;
            printf("---Eliga el numero de la opcion que quiere editar---\n");
            printf("1) Cambiar titulo\n");
            printf("2) Cambiar autor\n");
            printf("3) Cambiar anio\n");
            printf("4) Cambiar numero de estante\n");
            printf("5) Cambiar seccion\n");
            printf("6) Cambiar piso\n");
            printf("7) Cambiar edificio\n");
            printf("8) Cambiar sede\n");
            printf("8) Volver al menu\n");
            printf("-------------------\n");
            scanf("%d", &opcion);
            if (opcion == 1)
            {
                char cambio_titulo[75];
                printf("El titulo actual del libro es: %s\n", values[i].titulo);
                printf("Ingrese el nuevo titulo: ");
                scanf("%c", &temp);
                scanf("%[^\n]%*c", cambio_titulo);
                strcpy(values[i].titulo, cambio_titulo);
                printf("Nuevo titulo: %s \n", values[i].titulo);
            }
            else if (opcion == 2)
            {
                char cambio_autor[50];
                printf("El/los autores actuales son: %s\n", values[i].autor);
                printf("Ingrese el nuevo autor: ");
                scanf("%c", &temp);
                scanf("%[^\n]%*c", cambio_autor); /*raios, no acepta nombres con espacio*/
                strcpy(values[i].autor, cambio_autor);
                printf("Nuevo autor: %s \n", values[i].autor);
            }
            else if (opcion == 3)
            {
                int cambio_anio;
                printf("El anio actual es: %d \n", values[i].anio);
                printf("Ingrese el nuevo anio: ");
                scanf("%c", &temp);
                scanf("%d", &cambio_anio);
                values[i].anio = cambio_anio;
                printf("Nuevo anio: %d \n", values[i].anio);
            }
            else if (opcion == 4)
            {
                int cambio_estante;
                printf("El numero de estante actual es: %d \n", values[i].estante_numero);
                printf("Ingrese el nuevo numero de estante: ");
                scanf("%c", &temp);
                scanf("%d", &cambio_estante);
                values[i].estante_numero = cambio_estante;
                printf("El libro ahora se encuentra en el estante: %d \n", values[i].estante_numero);
            }
            else if (opcion == 5)
            {
                char cambio_seccion[50];
                printf("El libro se encuentra actualmente en la seccion de: %s\n", values[i].estante_seccion);
                printf("Ingrese la seccion a la cual desea mover el libro: ");
                scanf("%c", &temp);
                scanf("%[^\n]%*c", cambio_seccion);
                strcpy(values[i].estante_seccion, cambio_seccion);
                printf("El libro se encuentra ahora en la seccion: %s \n", values[i].estante_seccion);
            }
            else if (opcion == 6)
            {
                int cambio_piso;
                printf("El numero del piso actual es: %d \n", values[i].estante_numero);
                printf("Ingrese a que piso cambiara el libro: ");
                scanf("%c", &temp);
                scanf("%d", &cambio_piso);
                values[i].piso = cambio_piso;
                printf("El libro se encuentra ahora en el piso: %d \n", values[i].estante_numero);
            }
            else if (opcion == 7)
            {
                char cambio_edificio[1];
                printf("El libro se encuentra actualmente en el edificio: %s\n", values[i].edificio);
                printf("Ingrese a que edificio movera el libro: ");
                scanf("%c", &temp);
                scanf("%[^\n]%*c", cambio_edificio);
                strcpy(values[i].edificio, cambio_edificio);
                printf("El libro se encuentra ahora en el edificio: %s \n", values[i].edificio);
            }
            else if (opcion == 8)
            {
                char cambio_sede[20];
                printf("El libro se encuentra actualmente en la sede: %s\n", values[i].sede);
                printf("Ingrese a que sede movera el libro: ");
                scanf("%c", &temp);
                scanf("%[^\n]%*c", cambio_sede);
                strcpy(values[i].sede, cambio_sede);
                printf("El libro se encuentra ahora en la sede: %s \n", values[i].sede);
            }
            else if (opcion == 9)
            {
                return 0;
            }
        }
    }

    return 0;
}

int eliminar_libro(struct struct_libro values[], int arr_size)
{
    char titulo[20];
    char temp;
    printf("-------------------\n");
    printf("Introduzca el titulo del libro del cual desea eliminar elementos: ");

    scanf("%[^\n]%*c", titulo);
    printf("El libro seleccionado es : %s\n", titulo);
    printf("-------------------\n");

    for (int i = 0; i <= arr_size; i++)
    {
        if (strcmp(titulo, values[i].titulo) == 0)
        {
            int opcion = 0;
            printf("Introduzca numero del campo que desea eliminar\n");
            printf("1) Titulo del libro (Esto eliminara completamente todos los datos del libro)\n");
            printf("2) Eliminar autor\n");
            printf("3) Eliminar anio\n");
            printf("4) Eliminar numero de estante\n");
            printf("5) Eliminar seccion\n");
            printf("6) Eliminar piso\n");
            printf("7) Eliminar edificio\n");
            printf("8) Eliminar sede\n");
            printf("8) Volver al menu\n");
            printf("-------------------\n");
            scanf("%d", &opcion);
            if (opcion == 1)
            {
                int c;
                int numero_libro;
                printf("El numero del libro es: %i\n", i);
                scanf("%c", &temp);
                printf("Para confirmar que quiere eliminar el libro escriba el numero del libro: \n");
                scanf("%i", &numero_libro);
                if (numero_libro >= arr_size + 1)
                    printf("Se equivoco de numero porfavor intentelo denuevo.\n");
                else
                {
                    for (c = numero_libro - 1; c < arr_size - 1; c++)
                        values[c] = values[c + 1];
                }
                printf("ahora el titulo en el espacio %i es %s\n", i, values[i].titulo);
            }

            if (opcion == 9)
            {
                return 0;
            }
        }
    }
    return 0;
}

int eliminar_sede(void)
{
    printf("no se pueden eliminar sedes\n");
}

int main(int argc, char **argv)
{
    printf("--------Inicio---------\n");
    FILE *libro_csv = read_file(); /*cambiar la forma*/
    int arr_size = cuenta_lineas(libro_csv);
    rewind(libro_csv);
    //debug

    struct struct_libro values[arr_size + 1024];

    f_populate(libro_csv, values);
    //debug
    int original_size = arr_size;

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
      agregar_libro(values, &arr_size);
      break;

    case 2:
      editar_libro(values, arr_size);
      break;

    case 3:
      eliminar_libro(values, arr_size);
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

    case 5: ;
        eliminar_sede();


    case 6:
      flag = 0;
      break;

    default:
      break;
    }
  }

  return 0;
}
