import java.io.*;
import java.util.*;

public class Functions {

    static Scanner in = new Scanner(System.in);

    public void reader(String filePath) {

        String line = "";
        List<Books> bookList = getBookDetails(filePath);

        try (BufferedReader reader = new BufferedReader(new FileReader(filePath))) {

            while ((line = reader.readLine()) != null) {

                String[] bookdata = line.split(",(?=([^\"]*\"[^\"]*\")*[^\"]*$)");

                for (String index : bookdata) {
                    index.replaceAll(",", "");
                    // System.out.println(index);
                }

            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

}
