#include "function.h"

int editar_libro(struct struct_libro array_libros[], int arr_size)
{
    char titulo[20];
    char temp;

    printf("\npara editar un libro, ingrese el titulo: ");
    scanf("%c", &temp);
    scanf("%[^\n]%*c", titulo);
    printf("\nEditaremos: %s\n", titulo);

    for (int i = 0; i <= arr_size; i++)
    {
        if (strcmp(titulo, array_libros[i].titulo) == 0)
        {
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
            if (opcion == 1)
            {
                char cambio_titulo[100];
                printf("\nEl titulo actual del libro es: %s", array_libros[i].titulo);
                printf("\nIngrese el nuevo titulo: ");
                scanf("%c", &temp);
                scanf("%[^\n]%*c", cambio_titulo);
                strcpy(array_libros[i].titulo, cambio_titulo);
                printf("\nNuevo titulo: %s", array_libros[i].titulo);
            }
            else if (opcion == 2)
            {
                char cambio_autor[100];
                printf("\nEl/los autores actuales son: %s", array_libros[i].autor);
                printf("\nIngrese el nuevo autor: ");
                scanf("%c", &temp);
                scanf("%[^\n]%*c", cambio_autor); 
                strcpy(array_libros[i].autor, cambio_autor);
                printf("\nNuevo autor: %s", array_libros[i].autor);
            }
            else if (opcion == 3)
            {
                int cambio_anio;
                printf("\nEl anio actual es: %d", array_libros[i].anio);
                printf("\nIngrese el nuevo anio: ");
                scanf("%c", &temp);
                scanf("%d", &cambio_anio);
                array_libros[i].anio = cambio_anio;
                printf("\nNuevo anio: %d", array_libros[i].anio);
            }
            else if (opcion == 4)
            {
                int cambio_estante;
                printf("\nEl numero de estante actual es: %d", array_libros[i].estante_numero);
                printf("\nIngrese el nuevo numero de estante: ");
                scanf("%c", &temp);
                scanf("%d", &cambio_estante);
                array_libros[i].estante_numero = cambio_estante;
                printf("\nEl libro ahora se encuentra en el estante: %d", array_libros[i].estante_numero);
            }
            else if (opcion == 5)
            {
                char cambio_seccion[10];
                printf("\nEl libro se encuentra actualmente en la seccion de: %s", array_libros[i].estante_seccion);
                printf("\nIngrese la seccion a la cual desea mover el libro: ");
                scanf("%c", &temp);
                scanf("%[^\n]%*c", cambio_seccion);
                strcpy(array_libros[i].estante_seccion, cambio_seccion);
                printf("\nEl libro se encuentra ahora en la seccion: %s", array_libros[i].estante_seccion);
            }
            else if (opcion == 6)
            {
                int cambio_piso;
                printf("\nEl numero del piso actual es: %d", array_libros[i].estante_numero);
                printf("\nIngrese a que piso cambiara el libro: ");
                scanf("%c", &temp);
                scanf("%d", &cambio_piso);
                array_libros[i].piso = cambio_piso;
                printf("\nEl libro se encuentra ahora en el piso: %d", array_libros[i].estante_numero);
            }
            else if (opcion == 7)
            {
                char cambio_edificio[10];
                printf("\nEl libro se encuentra actualmente en el edificio: %s", array_libros[i].edificio);
                printf("\nIngrese a que edificio movera el libro: ");
                scanf("%c", &temp);
                scanf("%[^\n]%*c", cambio_edificio);
                strcpy(array_libros[i].edificio, cambio_edificio);
                printf("\nEl libro se encuentra ahora en el edificio: %s", array_libros[i].edificio);
            }
            else if (opcion == 8)
            {
                char cambio_sede[20];
                printf("\nEl libro se encuentra actualmente en la sede: %s", array_libros[i].sede);
                printf("\nIngrese a que sede (vina o santiago) movera el libro: ");
                scanf("%c", &temp);
                scanf("%[^\n]%*c", cambio_sede);
                strcpy(array_libros[i].sede, cambio_sede);
                printf("\nEl libro se encuentra ahora en la sede: %s", array_libros[i].sede);
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
