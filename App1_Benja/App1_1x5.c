#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct struct_libro
{
    char titulo[75];
    char autor[100];
    int anio;
    int estante_numero;
    char estante_seccion[50];
    int piso;
    char edificio[1];
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

int main()
{
    FILE *libro_csv = read_file();
    int arr_size = cuenta_lineas(libro_csv);
    printf("tamano del array: %i\n", arr_size);
    rewind(libro_csv);
    struct struct_libro values[arr_size];
    f_populate(libro_csv, values);

    printf("Nombre del titulo: %s\n", values[0].autor);
    printf("Nombre del titulo: %s\n", values[1].autor);
    printf("Nombre del titulo: %s\n", values[2].autor);

    return 0;
}