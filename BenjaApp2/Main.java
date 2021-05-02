import java.io.*;
import java.util.*;

public class Main {
    static Functions fun = new Functions();
    static Scanner input = new Scanner(System.in);

    public static void main(String[] args) {

        String filePath = System.getProperty("user.dir") + File.separator + args[0];
        // System.out.println(filePath);
        List<Books> bookList = fun.getBooks(filePath);

        System.out.println("\nlibros antes");

        for (Books books : bookList) {
            System.out.println(books.getTitulo());
        }

        Menus menu = new Menus();
        int menuNumber = 0;
        boolean flag = true;

        menu.deleteBook(); // prints out text
        String bookToDelete = input.nextLine(); // inputs name of book
        bookList.remove(fun.removeOneBook(bookList, bookToDelete)); // removes book from booklist

        System.out.println("\nlibros despues");

        for (Books books : bookList) {
            System.out.println(books.getTitulo());
        }

        // while (flag == true) {

        // menu.Inicio();
        // menuNumber = input.nextInt();

        // switch (menuNumber) {
        // case 1:
        // menu.Agregar();
        // bookList.add(fun.addOneBook(input));

        // for (Books books : bookList) {
        // System.out.println(books);
        // }

        // break;

        // break;
        // default:
        // flag = false;
        // break;
        // }
        // }

        // input.close();

    }

}