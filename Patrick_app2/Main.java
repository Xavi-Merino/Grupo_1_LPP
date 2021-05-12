import java.io.*;
import java.nio.file.*;
import java.util.*;

public class Main {
    static Functions fun = new Functions();
    static Scanner input = new Scanner(System.in);
    static Editarlibro edit = new Editarlibro();

    public static void main(String[] args) {

        String filePath = System.getProperty("user.dir") + File.separator + args[0];
        List<Books> bookList = fun.getBooks(filePath);

        for (Books book : bookList) {
            System.out.println(book.getTitulo());
        }

        boolean flag = true;
        while (flag == true) {
            Menus.Inicio();
            int n_menu = 0;
            n_menu = Integer.parseInt(input.nextLine());

            switch (n_menu) {
                case 1:
                    // agregar
                    bookList.add(fun.addOneBook());
                    Menus.Agregar();
                    break;

                case 2:
                    // editar
                    System.out.println("Introduzca titulo del libro que quiere editar: ");
                    edit.editBook(bookList, fun.bookToChoose());
                    break;
                case 3:
                    // eliminar
                    System.out.println("Introduzca titulo del libro que quiere eliminar: ");
                    bookList.remove(fun.removeOneBook(bookList, fun.bookToChoose()));

                    break;
                case 4:
                    // buscar
                    System.out.println("Introduzca titulo del libro que quiere buscar: ");
                    fun.displayOneBook(bookList, fun.bookToChoose());
                    break;
                case 5:
                    // eliminar sede
                    System.out.println("Introduzca la sede que quiere eliminar: ");
                    fun.deleteSede(bookList);
                    break;

                case 6:
                    // eliminar seccion
                    System.out.println("Introduzca la seccion que quiere eliminar: ");
                    fun.deleteSeccion(bookList);
                    break;

                case 7:
                    // eliminar piso
                    System.out.println("Introduzca el piso que quiere eliminar: ");
                    fun.deletePiso(bookList);
                    break;

                default:
                    flag = false;
                    break;
            }
        }

        // eliminar archivo anterior
        Path path = FileSystems.getDefault().getPath(filePath);
        try {
            Files.delete(path);
        } catch (NoSuchFileException x) {
            System.err.format("%s: no such" + " file or directory%n", path);
        } catch (IOException x) {
            System.err.println(x);
        }

        // guardar
        String filePathOut = filePath;
        fun.saveBooks(bookList, filePathOut);
    }

}