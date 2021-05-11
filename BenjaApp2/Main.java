import java.io.*;
import java.util.*;

public class Main {
    static Functions fun = new Functions();
    static Scanner input = new Scanner(System.in);
    static Editarlibro edit = new Editarlibro();

    public static void main(String[] args) {

        String filePath = System.getProperty("user.dir") + File.separator + args[0];

        List<Books> bookList = fun.getBooks(filePath);

        // eliminar
        bookList.remove(fun.removeOneBook(bookList, fun.bookToChoose()));

        // editar
        edit.editarLibro(bookList, fun.bookToChoose());

        // agregar
        bookList.add(fun.addOneBook());

        // buscar
        fun.displayOneBook(bookList, fun.bookToChoose());

        // guardar
        String filePathOut = fun.createFile();
        fun.saveBooks(bookList, filePathOut);
    }

}