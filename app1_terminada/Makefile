CC=gcc
CFLAGS=-I.
DEPS = function.h

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

app1:  main.o read_file.o cuenta_lineas.o rellena_array.o print_menu.o buscar_libro.o agregar_libro.o editar_libro.o eliminar_libro.o eliminar_sede.o eliminar_seccion.o csv_out.c 
	$(CC) -o app1  main.o read_file.o cuenta_lineas.o rellena_array.o print_menu.o buscar_libro.o agregar_libro.o editar_libro.o eliminar_libro.o eliminar_sede.o eliminar_seccion.o csv_out.c 

.PHONY: clean

clean:
	rm -f *.o