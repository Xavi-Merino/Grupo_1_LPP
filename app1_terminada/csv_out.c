#include "function.h"

int csv_out(struct struct_libro array_libros[], int arr_size)
{
    FILE *fp = fopen("prueba.csv", "w");
    int i;

    fprintf(fp, "titulo,autor,anio,estante_numero,estante_seccion,piso,edificio,sede\n");

    for (i = 1; i < arr_size; i++)
    {
        fprintf(fp, "%s,%s,%i,%i,%s,%i,%s,%s", array_libros[i].titulo,
                array_libros[i].autor, array_libros[i].anio, array_libros[i].estante_numero,
                array_libros[i].estante_seccion, array_libros[i].piso, array_libros[i].edificio, array_libros[i].sede);
    }

    fclose(fp);
    return 0;
}
