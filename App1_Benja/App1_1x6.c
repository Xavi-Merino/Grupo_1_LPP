#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct struct_libro
{
    char titulo[75];
    char autor[50];
    int anio;
    int estante_numero;
    char estante_seccion[50];
    int piso;
    char edificio[1];
    char sede[20];
};

FILE *read_file(char *filename)
{
    FILE *archivo_csv = fopen(filename, "r");
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

void printmenu()
{
    printf("1. Agregar un libro a la Bibloteca\n");
    printf("2. Quitar un libro de la Biblioteca\n");
    printf("3. Agregar una sede\n");
    printf("4. Quitar una sede (sólo si no hay libros)\n");
    printf("5. Editar un libro\n");
    printf("6. Cambiar un libro de sede\n");
    printf("7. Cambiar un libro de sección\n");
    printf("8. Cambiar un libro de piso\n");
    printf("9. Agregar secciones\n");
    printf("10. Eliminar secciones (sólo si no hay libros)\n");
    printf("11. Agregar un piso\n");
    printf("12. Eliminar piso (sólo si no hay libros)\n");
    printf("13. Buscar un libro\n");
    printf("14. Salir\n");
}

int agregar_libro(struct struct_libro libro_agregado[], int *index)
{

    //cuantos libros quiere agregar?
    printf("cuantos libros quiere agregar? ");
    int n_a;
    scanf("%i", &n_a);

    n_a += *index;

    for (int p = *index; p < n_a; p++)
    {

        printf("Ingrese el titulo del libro: ");
        scanf("%s", libro_agregado[p].titulo);

        printf("ingrese autor del libro: ");
        scanf("%s", libro_agregado[p].autor);

        printf("ingrese anio del libro: ");
        scanf("%d", &libro_agregado[p].anio);

        printf("ingrese el numero del estante en donde se encuentra el libro: ");
        scanf("%d", &libro_agregado[p].estante_numero);

        printf("ingrese la seccion en la cual se encuentra el libro: ");
        scanf("%s", libro_agregado[p].estante_seccion);

        printf("ingrese el piso del edificio en donde se encuentra el libro: ");
        scanf("%d", &libro_agregado[p].piso);

        printf("ingrese la letra del edificio en donde se encuentra el libro: ");
        scanf("%s", libro_agregado[p].edificio);

        printf("ingrese la sede en donde se encuentra el libro: ");
        scanf("%s", libro_agregado[p].sede);

        printf("Se agrego: '%s' de manera exitosa!\n", libro_agregado[p].titulo);
        ++(*index);
    }

    return 0;
};

int main(int argc, char **argv)
{
    FILE *libro_csv = read_file(); /*cambial la forma*/
    int arr_size = cuenta_lineas(libro_csv);
    rewind(libro_csv);
    struct struct_libro values[arr_size + 1024];
    f_populate(libro_csv, values, arr_size);
    int original_size = arr_size;

    /*deberia estar dentro del menu 1*/
    agregar_libro(values, &arr_size);

    // for (int x = original_size; x < arr_size; ++x)
    // {
    //     printf("titulo: %s\n", values[x].titulo);
    //     printf("auto: %s\n", values[x].autor);
    //     printf("n estante: %d\n", values[x].estante_numero);
    //     printf("s estante: %s\n", values[x].estante_seccion);
    //     printf("piso: %d\n", values[x].piso);
    //     printf("edificio: %s\n", values[x].edificio);
    //     printf("sede: %s\n", values[x].sede);
    //     printf("------------------------------------\n");
    // }

    return 0;
}