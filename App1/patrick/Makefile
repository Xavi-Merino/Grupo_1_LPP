edit : main.o read_file.o cuenta_lineas.o rellena_array.o \
       print_menu.o buscar_libro.o agregar_libro.o editar_libro.o\
	   eliminar_libro.o eliminar_sede.o eliminar_seccion.o csv_out.o
        gcc -o edit main.o read_file.o cuenta_lineas.o rellena_array.o \
       print_menu.o buscar_libro.o agregar_libro.o editar_libro.o\
	   eliminar_libro.o eliminar_sede.o eliminar_seccion.o csv_out.o

main.o : main.c function.h
        gcc -c main.c

read_file.o : readfile.c function.h
        gcc -c read_file.c

cuenta_lineas.o : cuenta_lineas.c  function.h
        gcc -c cuenta_lineas.c

rellena_array.o : rellena_array.c function.h
        gcc -c rellena_array.c

print_menu.o : print_menu.c function.h
        gcc -c print_menu.c

buscar_libro.o : buscar_libro.c  function.h
        gcc -c buscar_libro.c

agregar_libro.o : agregar_libro.c function.h
        gcc -c agregar_libro.c

editar_libro.o : editar_libro.c function.h
        gcc -c editar_libro.c

eliminar_libro.o : eliminar_libro.c function.h
		gcc -c eliminar_libro.c

eliminar_sede.o : eliminar_sede.c function.h
		gcc -c eliminar_sede.c

eliminar_seccion.o : eliminar_seccion.c function.h
		gcc -c eliminar_seccion.c

csv_out.o : csv_out.c function.h
		gcc -c csv_out.c

		
clean :
        rm edit main.o read_file.o cuenta_lineas.o rellena_array.o print_menu.o buscar_libro.o \
          agregar_libro.o editar_libro.o eliminar_libro.o eliminar_sede.o eliminar_seccion.o csv_out.csv_out  