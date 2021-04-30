import java.util.Scanner;

class SubMenus{
    /* verifica que la opcion ingresada este en el submenu */
    /*private int getInput(){
        Scanner tempScanner = new Scanner(System.in);
        int opcion = -1;
        while(opcion < 0 || opcion > 3){
            try{
                System.out.print("\nseleccione que desea hacer: ");
                opcion = Integer.parseInt(tempScanner.nextLine());
            }
            catch(NumberFormatException e){
                System.out.println("OPCION INVALIDA, vuelva a intentar\n");
            }
        }
        return opcion;
    }*/
    boolean exitSubMenu;
    
    /* imprime agregar/quitar menu */    
    public void imprimeOpcionesSubMenu1(){    
        System.out.println("1) Agregar libro");
        System.out.println("2) Quitar libro");
        System.out.println("0) Volver al menu principal");
    }

    public void displaySubMenu1(int opcion){
        InputMenuHandler opcionSubMenu1Handler = new InputMenuHandler();
        while(!exitSubMenu){
            imprimeOpcionesSubMenu1();
            int opcionSubMenu1 = opcionSubMenu1Handler.opcionMenu(3);
            agregar_quitarLibro();
        }
    }

    private void agregar_quitarLibro(){
        switch(opcionSubMenu1){
            case 1:
        }
    }
    

    /* editar libro */
    public void imprimeOpcionesSubMenu2(){
        System.out.println("1) ");
        System.out.println("2) Quitar libro");
        System.out.println("0) Volver al menu principal");
    }
}