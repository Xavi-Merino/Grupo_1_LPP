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
        input.nextLine();
        String titulo = input.nextLine();

        System.out.println("Introduzca autor: ");
        String autor = input.nextLine();

        System.out.println("Introduzca anio: ");
        int anio = input.nextInt();

        System.out.println("Introduzca numero del estante: ");
        int numeroEstante = input.nextInt();

        System.out.println("Introduzca seccion del Estante: ");
        input.nextLine();
        String seccionEstante = input.nextLine();

        System.out.println("Introduzca el piso: ");
        int piso = input.nextInt();

        System.out.println("Introduzca la letra del edificio: ");
        input.nextLine();
        String edificio = input.nextLine();

        System.out.println("Introduzca la sede: ");
        String sede = input.nextLine();

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
        System.out.println("Introduzca titulo de el libro que quiere editar/eliminar: ");
        String titulo = input.nextLine();
        return titulo;
    }

    public void displayOneBook(List<Books> bookList, String bookToDisplay) {
        for (Books book : bookList) {
            if (book.getTitulo().equals(bookToDisplay))
                System.out.println(book);
        }
    }

    public String createFile() {
        try {
            System.out.print("Ingrese el nombre del nuevo archivo(sin .csv): ");
            String filename = input.nextLine();
            File myObj = new File(filename + ".csv");
            if (myObj.createNewFile()) {
                System.out.println("Archivo creado: " + myObj.getName());
            } else {
                System.out.println("Archivo ya existe.");
            }
            String filePathOut = System.getProperty("user.dir") + File.separator + filename + ".csv";
            return filePathOut;
        } catch (IOException e) {
            System.out.println("An error occurred.");
            e.printStackTrace();
        }
        return null;
    }

    public void saveBooks(List<Books> bookList, String filePathOut) {

        try (FileWriter fw = new FileWriter(filePathOut)) {
            BufferedWriter bw = new BufferedWriter(fw);
            PrintWriter pw = new PrintWriter(bw);
            pw.println("titulo" + "," + "autor" + "," + "anio" + "," + "numeroEstante" + "," + "seccionEstante" + ","
                    + "piso" + "," + "edificio" + "," + "sede");
            for (Books books : bookList) {
                pw.println(books.getTitulo() + books.getAutor() + books.getAnio() + books.getNumeroEstante()
                        + books.getSeccionEstante() + books.getPiso() + books.getEdificio() + books.getSede());
            }
            pw.flush();
            pw.close();
        } catch (Exception e) {
            e.printStackTrace();
        }

    }

}
