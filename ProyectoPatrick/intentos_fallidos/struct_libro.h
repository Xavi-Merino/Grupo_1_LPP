extern struct libro {
  char* titulo[75];
  char* autor[50];
  int anio;
  int estante_numero;
  char* estante_seccion[50];
  int piso;
  char* edificio[1];
  char* sede[10];
} libro;

extern struct struct_libro {
  char* titulo[75];
  char* autor[50];
  int anio;
  int estante_numero;
  char* estante_seccion[50];
  int piso;
  char* edificio[1];
  char* sede[10];
} struct_libro;

extern struct biblioteca {
  struct libro* libro;
  struct biblioteca* siguiente;
} biblioteca;