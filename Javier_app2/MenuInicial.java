class MenuInicial{
    boolean exit;
   /* este no se usara, se creo InputMenuHandler para aplicarlo a todos los menus private int getInput(){
        Scanner tempScanner = new Scanner(System.in);
        int opcion = -1;
        while(opcion < 0 || opcion > 5){
            try{
                System.out.print("\nseleccione que desea hacer: ");
                opcion = Integer.parseInt(tempScanner.nextLine());
            }
            catch(NumberFormatException e){
                System.out.println("OPCION INVALIDA, vuelva a intentar\n");
                imprimeOpciones();
            }
        }
        return opcion;
    }*/
 
    public void displayMenu(){
        InputMenuHandler opcionMenuHandler = new InputMenuHandler();
        headerMenuInicial();
        while(!exit){ 
            opcionesMenuInicial();
            int opcion = opcionMenuHandler.opcionMenu(6);
            // como hago para pasar la opcion a submenus??;
        }
    }
    /* imprime header del menu inicial */
    private void headerMenuInicial()  {
        System.out.println("------------------------------");
        System.out.println("|       Biblioteca UAI       |");
        System.out.println("------------------------------\n");                 
    }
    /* imprime imprimeOpciones del menu */
    private void opcionesMenuInicial(){
        System.out.println("1) Agregar/Quitar un Libro");
        System.out.println("2) Editar un libro");
        System.out.println("3) Agregar/Quitar sede");
        System.out.println("4) Agregar/Quitar seccion");
        System.out.println("5) Agregar/Quitar piso");
        System.out.println("0) Salir");
    }
    
    public void opcionesSubMenu1(){    
        System.out.println("1) Agregar libro");
        System.out.println("2) Quitar libro");
        System.out.println("0) Volver al menu principal");
    }
    
   /* private void subMenu(int opcion){
        switch(opcion){
            case 1:
            InputMenuHandler opcionSubMenu1_Handler = new InputMenuHandler();
            opcionesSubMenu1();
            int opcionSubMenu1 = opcionSubMenu1_Handler.opcionMenu(3);

        }
    }*/
}