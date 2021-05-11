
import java.util.*;

public class Editarlibro {

    static Scanner input = new Scanner(System.in);

    public int opcionEditar() {
        int opcionElegida;
        System.out.println("1) Cambiar titulo");
        System.out.println("2) Cambiar autor");
        System.out.println("3) Cambiar anio");
        System.out.println("4) Cambiar numero de estante");
        System.out.println("5) Cambiar seccion");
        System.out.println("6) Cambiar piso");
        System.out.println("7) Cambiar edificio");
        System.out.println("8) Cambiar sede");
        System.out.println("9) Volver al menu");
        System.out.println("Ingrese que quiere editar de el libro:");
        return opcionElegida = input.nextInt();
    }

    public Books editarLibro(List<Books> bookList, String bookToEdit) {
        int opcionElegida = opcionEditar();
        for (Books book : bookList) {
            if (book.getTitulo().equals(bookToEdit)) {
                if (opcionElegida == 1) {
                    System.out.println("Ingrese el titulo nuevo");
                    String temp = input.nextLine();
                    String titulo = input.nextLine();
                    book.setTitulo(titulo);
                }
                if (opcionElegida == 2) {
                    System.out.println("Ingrese el autor nuevo");
                    String temp = input.nextLine();
                    String autor = input.nextLine();
                    book.setAutor(autor);
                }
                if (opcionElegida == 3) {
                    System.out.println("Ingrese el anio nuevo");
                    String temp = input.nextLine();
                    int anio = input.nextInt();
                    book.setAnio(anio);
                }
                if (opcionElegida == 4) {
                    System.out.println("Ingrese el numero de estante nuevo");
                    String temp = input.nextLine();
                    int numeroEstante = input.nextInt();
                    book.setNumeroEstante(numeroEstante);
                }
                if (opcionElegida == 5) {
                    System.out.println("Ingrese la seccion nueva");
                    String temp = input.nextLine();
                    String seccionEstante = input.nextLine();
                    book.setSeccionEstante(seccionEstante);
                }
                if (opcionElegida == 6) {
                    System.out.println("Ingrese el piso nuevo");
                    String temp = input.nextLine();
                    int piso = input.nextInt();
                    book.setPiso(piso);
                }
                if (opcionElegida == 7) {
                    System.out.println("Ingrese el edificio nuevo");
                    String temp = input.nextLine();
                    String edificio = input.nextLine();
                    book.setEdificio(edificio);
                }
                if (opcionElegida == 8) {
                    System.out.println("Ingrese la sede nueva");
                    String temp = input.nextLine();
                    String sede = input.nextLine();
                    book.setSede(sede);
                }
            }
        }
        return null;
    }
}