import java.util.Scanner;

public class InputMenuHandler{
    int numero_opciones = 0;

    /* metodo para corroborar que la opcion ingresada sea correcta en los menu */
    protected int opcionMenu(int numero_opciones){
        Scanner tempScanner = new Scanner(System.in);
        int opcion = -1;
        while(opcion < 0 || opcion > numero_opciones){
            try{
                System.out.print("\nseleccione que desea hacer: ");
                opcion = Integer.parseInt(tempScanner.nextLine());
                if (opcion > numero_opciones){
                    System.out.println("OPCION INVALIDA, vuelva a intentar\n");
                }
            }
            catch(NumberFormatException e){
                System.out.println("OPCION INVALIDA, vuelva a intentar\n");
            }
        }
        return opcion;
    }

}