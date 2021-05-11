import java.io.*;
import java.util.*;

public class Main {
    static Functions fun = new Functions();
    static Scanner input = new Scanner(System.in);
    static Editarlibro edit = new Editarlibro();

    public static void main(String[] args) {

        String filePath = System.getProperty("user.dir") + File.separator + args[0];
        List<Books> bookList = fun.getBooks(filePath);

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
                    edit.editarLibro(bookList, fun.bookToChoose());
                    System.out.println("Introduzca titulo del libro que quiere editar: ");
                    break;
                case 3:
                    // eliminar
                    bookList.remove(fun.removeOneBook(bookList, fun.bookToChoose()));
                    System.out.println("Introduzca titulo del libro que quiere eliminar: ");
                    break;
                case 4:
                    // buscar
                    fun.displayOneBook(bookList, fun.bookToChoose());
                    break;
                default:
                    flag = false;
                    break;
            }
        }

        // guardar
        String filePathOut = fun.createFile();
        fun.saveBooks(bookList, filePathOut);
    }

}