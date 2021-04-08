#include "function.h"

int eliminar_libro(struct struct_libro array_libros[], int arr_size)
{
    char titulo[100];
    char temp;

    printf("\nIntroduzca el titulo del libro del cual desea eliminar elementos: ");
    scanf("%c", &temp);
    scanf("%[^\n]%*c", titulo);
    printf("\nEl libro seleccionado es : %s", titulo);

    for (int i = 0; i <= arr_size; i++)
    {
        if (strcmp(titulo, array_libros[i].titulo) == 0)
        {
            int opcion = 0;
            printf("\n\n---estas seguro de que quieres eliminarlo?---");
            printf("\n1) Si");
            printf("\n2) Volver al menu");
            printf("\nIngrese numero: ");
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
                        array_libros[c] = array_libros[c + 1];
                }
                printf("\nSe a eliminado de manera exitosa\n");
            }

            if (opcion == 2)
            {
                return 0;
            }
        }
    }
    return 0;
}
