#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "f_read.h"

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

char f_populate(FILE *libro_csv, struct struct_libro values[], int n_lineas)
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

void printmenu() {
  printf("1. Agregar un libro a la Bibloteca\n");
  printf("2. Quitar un libro de la Biblioteca\n");
  printf("3. Agregar una sede\n");
  printf("4. Quitar una sede (sólo si no hay libros)\n");
  printf("5. Editar un libro\n");  // A qué se refiere con editar
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

char editarlibro(struct struct_libro values[], int arr_size){
    char titulo[100];
    printf("para editar un libro, ingrese el titulo: \n");
    scanf("%99[^\n]", titulo); /*OJO los libros con comas se guardan sin comas, al buscarlos deben ser buscados con su nombre sin comas ....*/
    for (int i = 0; i<= arr_size; i++ ){
        
        if(strcmp(titulo, values[i].titulo) == 0){ /*problema con todos los char(no aceptan espacios)*/
            int opcion = 0;
            char temp; /*esto es para  limpiar el buffer despues de ingresar un int(en este caso opcion)*/
            printf("¿que desea cambiar de este libro?\n");
            printf("1) cambiar titulo\n");
            printf("2) cambiar autor\n");
            printf("3) cambiar anio\n");
            printf("4) cambiar numero de estante\n");
            printf("5) cambiar seccion\n");
            printf("6) cambiar piso\n");
            printf("7) cambiar edificio\n");
            printf("8) cambiar sede\n");
            scanf("%d", &opcion);
            scanf("%c", &temp); /*despues de pedir un int es necesario poner un limpiador de buffer*/
            if(opcion == 1 ){
                char cambio_titulo[75];
                printf("el titulo actual del libro es: %s\n", values[i].titulo);
                printf("ingrese el nuevo titulo: ");
                scanf("%99[^\n]", cambio_titulo );
                strcpy(values[i].titulo, cambio_titulo); 
                printf("nuevo titulo: %s \n", values[i].titulo);
            }
            else if(opcion == 2){
                char cambio_autor[50];
                printf("el/los autores acutales son: %s\n", values[i].autor);
                printf("ingrese el nuevo autor: ");
                scanf("%99[^\n]", cambio_autor );
                strcpy(values[i].autor, cambio_autor); 
                printf("nuevo autor :%s \n", values[i].autor);
            }
            else if(opcion == 3){
                int cambio_anio;
                printf("el anio actual es: %d \n", values[i].anio);
                printf("ingrese el nuevo anio: ");
                scanf("%d", &cambio_anio );
                values[i].anio = cambio_anio; 
                printf("nuevo anio: %d \n", values[i].anio);
            }
            else if(opcion == 4){
                int cambio_estante;
                printf("el numero de estante actual es: %d \n", values[i].estante_numero);
                printf("ingrese el nuevo numero de estante: ");
                scanf("%d", &cambio_estante );
                values[i].estante_numero = cambio_estante; 
                printf("el libro ahora se encuentra en el estante: %d \n", values[i].estante_numero);                
            }
            else if(opcion == 5){
                char cambio_seccion[50];
                printf("el libro se encuentra actualmente en la seccion de: %s\n", values[i].estante_seccion);
                printf("ingrese la seccion a la cual desea mover el libro: ");
                scanf("%99[^\n]", cambio_seccion ); 
                strcpy(values[i].estante_seccion, cambio_seccion); 
                printf("el libro se encuentra ahora en la seccion: %s \n", values[i].estante_seccion);                
            }
            else if(opcion == 6){
                int cambio_piso;
                printf("el numero del piso actual es: %d \n", values[i].estante_numero);
                printf("ingrese a que piso cambiara el libro: ");
                scanf("%d", &cambio_piso );
                values[i].piso = cambio_piso; 
                printf("el libro se encuentra ahora en el piso: %d \n", values[i].estante_numero);                
            }
            else if(opcion == 7){
                char cambio_edificio[1];
                printf("el libro se encuentra actualmente en el edificio: %s\n", values[i].edificio);
                printf("ingrese a que edificio movera el libro: ");
                scanf("%99[^\n]", cambio_edificio ); 
                strcpy(values[i].edificio, cambio_edificio); 
                printf("el libro se encuentra ahora en el edificio: %s \n", values[i].edificio);                
            }
            else if(opcion == 8){
                char cambio_sede[20];
                printf("el libro se encuentra actualmente en la sede: %s\n", values[i].sede);
                printf("ingrese a que sede movera el libro: ");
                scanf("%99[^\n]", cambio_sede );
                strcpy(values[i].sede, cambio_sede); 
                printf("el libro se encuentra ahora en la sede: %s \n", values[i].sede);                
            }
        }
        
    }

}

int main()
{
    FILE *libro_csv = read_file();
    int arr_size = cuenta_lineas(libro_csv);
    rewind(libro_csv);
    struct struct_libro values[arr_size];
    f_populate(libro_csv, values, arr_size);
    editarlibro(values, arr_size);


    return 0;
}