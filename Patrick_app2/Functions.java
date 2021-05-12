import java.io.*;
import java.util.*;

public class Functions {

    static Scanner input = new Scanner(System.in);

    public List<Books> getBooks(String filePath) {

        String line = "";
        List<Books> bookList = new ArrayList<>();

        try (BufferedReader reader = new BufferedReader(new FileReader(filePath))) {
            line = reader.readLine();
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

    private Books getOneBook(String[] bookData) {
        String titulo = bookData[0];
        String autor = bookData[1];
        int anio = Integer.parseInt(bookData[2]);
        int numeroEstante = Integer.parseInt(bookData[3]);
        String seccionEstante = bookData[4];
        int piso = Integer.parseInt(bookData[5]);
        String edificio = bookData[6];
        String sede = bookData[7];
        Books book = new Books(titulo, autor, anio, numeroEstante, seccionEstante, piso, edificio, sede);
        return book;
    }

    public Books addOneBook() {

        System.out.println("Introduzca titulo: ");
        String titulo = "\"" + input.nextLine() + "\"";

        System.out.println("Introduzca autor: ");
        String autor = "\"" + input.nextLine() + "\"";

        System.out.println("Introduzca anio: ");
        int anio = input.nextInt();

        System.out.println("Introduzca numero del estante: ");
        int numeroEstante = input.nextInt();

        System.out.println("Introduzca seccion del Estante: ");
        input.nextLine();
        String seccionEstante = "\"" + input.nextLine() + "\"";

        System.out.println("Introduzca el piso: ");
        int piso = input.nextInt();

        System.out.println("Introduzca la letra del edificio: ");
        input.nextLine();
        String edificio = "\"" + input.nextLine() + "\"";

        System.out.println("Introduzca la sede: ");
        String sede = "\"" + input.nextLine() + "\"";

        Books book = new Books(titulo, autor, anio, numeroEstante, seccionEstante, piso, edificio, sede);
        return book;
    }

    public Books removeOneBook(List<Books> bookList, String bookToDelete) {
        for (Books book : bookList) {
            if (book.getTitulo().equals(bookToDelete))
                return book;
        }
        return null;
    }

    public String bookToChoose() {
        String titulo = "\"" + input.nextLine() + "\"";
        return titulo;
    }

    public void displayOneBook(List<Books> bookList, String bookToDisplay) {
        for (Books book : bookList) {
            if (book.getTitulo().equals(bookToDisplay)) {
                System.out.println("Usted busco el libro: " + book.getTitulo());
                System.out.println("El(Los) autor(es) del libro es: " + book.getAutor());
                System.out.println("Fue publicado el anio: " + book.getAnio());
                System.out.println("Este libro esta ubicado en la sede " + book.getSede() + ", en el edificio "
                        + book.getEdificio() + ", en el piso " + book.getPiso() + ", en estante de "
                        + book.getSeccionEstante() + " y seccion " + book.getNumeroEstante());
            }
        }
    }

    public void saveBooks(List<Books> bookList, String filePathOut) {

        try (FileWriter fw = new FileWriter(filePathOut)) {
            BufferedWriter bw = new BufferedWriter(fw);
            PrintWriter pw = new PrintWriter(bw);
            pw.println("titulo" + "," + "autor" + "," + "anio" + "," + "numeroEstante" + "," + "seccionEstante" + ","
                    + "piso" + "," + "edificio" + "," + "sede");
            for (Books books : bookList) {
                pw.println(books.getTitulo() + ',' + books.getAutor() + ',' + books.getAnio() + ','
                        + books.getNumeroEstante() + ',' + books.getSeccionEstante() + ',' + books.getPiso() + ','
                        + books.getEdificio() + ',' + books.getSede());
            }
            pw.flush();
            pw.close();
        } catch (Exception e) {
            e.printStackTrace();
        }

    }

    public void deleteSede(List<Books> bookList) {
        String n = '\"' + input.nextLine() + '\"';
        boolean thereisntabook = true;
        for (Books book : bookList) {
            if (book.getSede().equals(n)) {
                thereisntabook = false;
                System.out.println("No podemos eliminar la sede porque " + book.getTitulo() + " esta alli.");
            }
        }
        if (thereisntabook) {
            System.out.println("No existe tal sede dentro en la biblioteca UAI.");
        }
    }

    public void deleteSeccion(List<Books> bookList) {
        String n = '\"' + input.nextLine() + '\"';
        boolean thereisntabook = true;
        for (Books book : bookList) {
            if (book.getSeccionEstante().equals(n)) {
                thereisntabook = false;
                System.out.println("No podemos eliminar la seccion porque " + book.getTitulo() + " esta alli.");
            }
        }
        if (thereisntabook) {
            System.out.println("No existe tal seccion dentro de la biblioteca.");
        }
    }

    public void deletePiso(List<Books> bookList) {
        int n = input.nextInt();
        boolean thereisntabook = true;
        for (Books book : bookList) {
            if (book.getPiso() == n) {
                thereisntabook = false;
                System.out.println("No podemos eliminar el piso porque " + book.getTitulo() + " esta alli.");
            }
        }
        if (thereisntabook) {
            System.out.println("No existe tal piso dentro de la biblioteca.");
        }
    }

}
