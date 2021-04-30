import java.io.*;
import java.util.*;

public class Functions {

    public Functions() {
        // empty
    }

    // static Scanner in = new Scanner(System.in);

    public static List<Books> getBooks(String filePath) {

        String line = "";
        List<Books> bookList = new ArrayList<>();

        try (BufferedReader reader = new BufferedReader(new FileReader(filePath))) {
            line = reader.readLine();
            // String first_line = line;
            while ((line = reader.readLine()) != null) {

                String[] bookData = line.split(",(?=([^\"]*\"[^\"]*\")*[^\"]*$)");

                for (String index : bookData) {
                    index.replaceAll(",", "");
                }

                Books book = getOneBook(bookData);
                bookList.add(book);

            }
        } catch (Exception e) {
            e.printStackTrace();
        }
        return bookList;
    }

    private static Books getOneBook(String[] bookData) {
        String titulo = bookData[0];
        String autor = bookData[1];
        int anio = Integer.parseInt(bookData[2]); // problema
        int numeroEstante = Integer.parseInt(bookData[3]);
        String seccionEstante = bookData[4];
        int piso = Integer.parseInt(bookData[5]);
        String edificio = bookData[6];
        String sede = bookData[7];
        Books book = new Books(titulo, autor, anio, numeroEstante, seccionEstante, piso, edificio, sede);
        return book;
    }

}
