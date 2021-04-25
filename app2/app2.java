package app2;

import java.io.*;
import java.util.Scanner;

/* app2 */

public class app2 {

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        System.out.println("Cual es su systema operativo? eliga el numero");
        System.out.println("1-Windows");
        System.out.println("2-Linux");
        System.out.println("3-MacOS");
        int os = input.nextInt();

        String fileName = args[0];
        String filePath = null;

        String errmsg = "error escriba una opcion seleccionada";

        if (os == 1) {

            filePath = System.getProperty("user.dir") + "\\" + fileName;

        } else {
            System.out.println(errmsg);
        }

        if (os == 2 || os == 3) {

            filePath = System.getProperty("user.dir") + '/' + fileName;

        } else {
            System.out.println(errmsg);
        }

        String line = "";
        // System.out.println(filePath);

        try (BufferedReader reader = new BufferedReader(new FileReader(filePath))) {
            while ((line = reader.readLine()) != null) {

                String[] bookdata = line.split(",(?=([^\"]*\"[^\"]*\")*[^\"]*$)");
                for (String index : bookdata) {
                    index.replaceAll(",", "");
                    System.out.println(index);
                }
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

}