import java.io.*;

public class Main {

    public static void main(String[] args) {

        Functions fun = new Functions();
        String filePath = System.getProperty("user.dir") + File.separator + args[0];
        System.out.println(filePath);
        fun.reader(filePath);

    }

}