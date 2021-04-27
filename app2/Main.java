import java.io.*;
import java.util.*;

public class Main {
    static Functions fun = new Functions();

    public static void main(String[] args) {

        String filePath = System.getProperty("user.dir") + File.separator + args[0];
        // System.out.println(filePath);
        List<Books> bookList = fun.getBooks(filePath);

        for (Books books : bookList) {
            System.out.println(books);
        }

    }

}