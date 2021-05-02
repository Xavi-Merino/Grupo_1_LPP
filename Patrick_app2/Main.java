import java.io.*;
import java.util.*;

public class Main {
    static Functions fun = new Functions();

    public static void main(String[] args) {

        String filePath = System.getProperty("user.dir") + File.separator + args[0];
        // System.out.println(filePath);
        List<Books> bookList = Functions.getBooks(filePath);

        for (Books books : bookList) {
            System.out.println(books);
        }

        Menus menu = new Menus();
        Scanner input = new Scanner(System.in);

        int n_menu = 0;

        boolean flag = true;
        while (flag == true) {

            menu.Inicio();
            n_menu = input.nextInt();

            switch (n_menu) {
                case 1:
                    menu.Agregar();
                    bookList.add(Functions.addOneBook(input));

                    for (Books books : bookList) {
                        System.out.println(books);
                    }

                    break;

                default:
                    flag = false;
                    break;
            }
        }

        input.close();

    }

}