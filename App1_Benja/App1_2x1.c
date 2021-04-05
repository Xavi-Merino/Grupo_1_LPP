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
    FILE *archivo_csv = fopen("ejemplo.csv", "r");
    if (archivo_csv == NULL)
    {
        printf("\nel archivo no pudo ser abierto");
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

int agregar_libro(struct struct_libro values[], int *index)
{
    char temp;
    //cuantos libros quiere agregar?
    printf("\nCuantos libros quiere agregar?");
    printf("Ingrese numero: ");
    int n_a;
    scanf("%i", &n_a);
    scanf("%c", &temp);

    n_a += *index;
    int cont = 1;
    for (int p = *index; p < n_a; p++)
    {

        printf("\n--------libro %i-----------", cont);
        printf("Ingrese el titulo del libro: ");
        scanf("%[^\n]%*c", values[p].titulo);

        printf("Ingrese autor del libro: ");
        scanf("%[^\n]%*c", values[p].autor);

        printf("Ingrese anio del libro: ");
        scanf("%d", &values[p].anio);
        scanf("%c", &temp);

        printf("Ingrese el numero del estante en donde se encuentra el libro: ");
        scanf("%d", &values[p].estante_numero);
        scanf("%c", &temp);

        printf("Ingrese la seccion(en letras) en la cual se encuentra el libro: ");
        scanf("%s", values[p].estante_seccion);

        printf("Ingrese el piso del edificio en donde se encuentra el libro: ");
        scanf("%d", &values[p].piso);
        scanf("%c", &temp);

        printf("Ingrese la letra del edificio en donde se encuentra el libro: ");
        scanf("%s", values[p].edificio);
        scanf("%c", &temp);

        printf("Ingrese la sede (vina o santiago) en donde se encuentra el libro: ");
        scanf("%[^\n]%*c", values[p].sede);

        printf("Se agrego: '%s' de manera exitosa!\n", values[p].titulo);
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
    printf("\nEditaremos: %s", titulo);

    for (int i = 0; i <= arr_size; i++)
    {
        if (strcmp(titulo, values[i].titulo) == 0)
        {
            int opcion = 0;
            printf("\n---Eliga el numero de la opcion que quiere editar---");
            printf("\n1) Cambiar titulo");
            printf("\n2) Cambiar autor");
            printf("\n3) Cambiar anio");
            printf("\n4) Cambiar numero de estante");
            printf("\n5) Cambiar seccion");
            printf("\n6) Cambiar piso");
            printf("\n7) Cambiar edificio");
            printf("\n8) Cambiar sede");
            printf("\n8) Volver al menu");
            printf("\n-------------------");
            scanf("%d", &opcion);
            if (opcion == 1)
            {
                char cambio_titulo[100];
                printf("\nEl titulo actual del libro es: %s", values[i].titulo);
                printf("\nIngrese el nuevo titulo: ");
                scanf("%c", &temp);
                scanf("%[^\n]%*c", cambio_titulo);
                strcpy(values[i].titulo, cambio_titulo);
                printf("\nNuevo titulo: %s", values[i].titulo);
            }
            else if (opcion == 2)
            {
                char cambio_autor[100];
                printf("\nEl/los autores actuales son: %s", values[i].autor);
                printf("\nIngrese el nuevo autor: ");
                scanf("%c", &temp);
                scanf("%[^\n]%*c", cambio_autor); /*raios, no acepta nombres con espacio*/
                strcpy(values[i].autor, cambio_autor);
                printf("\nNuevo autor: %s", values[i].autor);
            }
            else if (opcion == 3)
            {
                int cambio_anio;
                printf("\nEl anio actual es: %d", values[i].anio);
                printf("\nIngrese el nuevo anio: ");
                scanf("%c", &temp);
                scanf("%d", &cambio_anio);
                values[i].anio = cambio_anio;
                printf("\nNuevo anio: %d", values[i].anio);
            }
            else if (opcion == 4)
            {
                int cambio_estante;
                printf("\nEl numero de estante actual es: %d", values[i].estante_numero);
                printf("\nIngrese el nuevo numero de estante: ");
                scanf("%c", &temp);
                scanf("%d", &cambio_estante);
                values[i].estante_numero = cambio_estante;
                printf("\nEl libro ahora se encuentra en el estante: %d", values[i].estante_numero);
            }
            else if (opcion == 5)
            {
                char cambio_seccion[10];
                printf("\nEl libro se encuentra actualmente en la seccion de: %s", values[i].estante_seccion);
                printf("\nIngrese la seccion a la cual desea mover el libro: ");
                scanf("%c", &temp);
                scanf("%[^\n]%*c", cambio_seccion);
                strcpy(values[i].estante_seccion, cambio_seccion);
                printf("\nEl libro se encuentra ahora en la seccion: %s", values[i].estante_seccion);
            }
            else if (opcion == 6)
            {
                int cambio_piso;
                printf("\nEl numero del piso actual es: %d", values[i].estante_numero);
                printf("\nIngrese a que piso cambiara el libro: ");
                scanf("%c", &temp);
                scanf("%d", &cambio_piso);
                values[i].piso = cambio_piso;
                printf("\nEl libro se encuentra ahora en el piso: %d", values[i].estante_numero);
            }
            else if (opcion == 7)
            {
                char cambio_edificio[10];
                printf("\nEl libro se encuentra actualmente en el edificio: %s", values[i].edificio);
                printf("\nIngrese a que edificio movera el libro: ");
                scanf("%c", &temp);
                scanf("%[^\n]%*c", cambio_edificio);
                strcpy(values[i].edificio, cambio_edificio);
                printf("\nEl libro se encuentra ahora en el edificio: %s", values[i].edificio);
            }
            else if (opcion == 8)
            {
                char cambio_sede[20];
                printf("\nEl libro se encuentra actualmente en la sede: %s", values[i].sede);
                printf("\nIngrese a que sede (vina o santiago) movera el libro: ");
                scanf("%c", &temp);
                scanf("%[^\n]%*c", cambio_sede);
                strcpy(values[i].sede, cambio_sede);
                printf("\nEl libro se encuentra ahora en la sede: %s", values[i].sede);
            }
            else if (opcion == 9)
            {
                scanf("%c", &temp);
                return 0;
            }
        }
    }

    return 0;
}

int eliminar_libro(struct struct_libro values[], int arr_size)
{
    char titulo[100];
    char temp;
    printf("\n-------------------");
    printf("Introduzca el titulo del libro del cual desea eliminar elementos: ");

    scanf("%[^\n]%*c", titulo);
    printf("\nEl libro seleccionado es : %s", titulo);
    printf("\n-------------------");

    for (int i = 0; i <= arr_size; i++)
    {
        if (strcmp(titulo, values[i].titulo) == 0)
        {
            int opcion = 0;
            printf("\nIntroduzca numero del campo que desea eliminar");
            printf("\n1) Libro (Esto eliminara completamente todos los datos del libro)");
            printf("\n8) Volver al menu");
            scanf("%d", &opcion);
            if (opcion == 1)
            {
                int c;
                int numero_libro;
                printf("\nEl numero del libro es: %i", i);
                scanf("%c", &temp);
                printf("\nPara confirmar que quiere eliminar el libro escriba el numero del libro: ");
                scanf("%i", &numero_libro);

                if (numero_libro >= arr_size)
                    printf("\nSe equivoco de numero porfavor intentelo denuevo.");
                else
                {
                    for (c = numero_libro; c < arr_size; c++)
                        values[c] = values[c + 1];
                }
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
    printf("\nno se pueden eliminar sedes");
}

int csv_out(struct struct_libro values[], int original_size)
{
    FILE *fp;
    int i;
    fp = fopen("/home/malware/App1/ejemplo.csv", "w");
    fprintf(fp, "titulo,autor,anio,estante_numero,estante_seccion,piso,edificio,sede\n");

    for (i = 0; i < original_size - 1; i++)
    {
        fprintf(fp, "%s,%s,%d,%d,%s,%d,%s,%s", values[i].titulo, values[i].autor, values[i].anio, values[i].estante_numero, values[i].estante_seccion, values[i].piso, values[i].edificio, values[i].sede);
    }
    fclose(fp);
    return 0;
}

int main(int argc, char **argv)
{
    printf("\n--------Inicio---------");
    FILE *libro_csv = read_file(); /*cambiar la forma*/
    int arr_size = cuenta_lineas(libro_csv);
    rewind(libro_csv);

    printf("\ntamano del array: %i", arr_size);

    struct struct_libro values[arr_size + 1024];

    f_populate(libro_csv, values);
    printf("\nel libro en el espacio 18 es %s\n", values[16].autor);
    printf("\nNombre del titulo: %s", values[0].titulo);
    printf("\nNombre del autor: %s", values[0].autor);
    printf("\n-------------------");
    int original_size = arr_size;

    /*deberia estar dentro del menu 1*/
    agregar_libro(values, &arr_size);
    printf("\ntitulo: %s", values[original_size].titulo);
    printf("\n-------------------");
    /*menu opcion 2*/
    editar_libro(values, arr_size);
    /*menu opcion 3*/
    eliminar_libro(values, arr_size);
    printf("\nel libro en el espacio es %s\n", values[0].titulo);
    csv_out(values, arr_size);
    return 0;
}
