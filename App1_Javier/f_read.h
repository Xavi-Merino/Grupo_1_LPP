#ifndef f_read_H
#define f_read_H
struct struct_libro {
    char titulo[100];
    char autor[50];
    int anio;
    int estante_numero;
    char estante_seccion[50];
    int piso;
    char edificio[1];
    char sede[20];
};

char f_read();


struct struct_libro *info_libro;
#endif