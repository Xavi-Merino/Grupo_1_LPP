class Menus {
    public Menus() {
        // empty
    };

    public static void headerMenuInicial() {
        System.out.println("------------------------------");
        System.out.println("|       Biblioteca UAI       |");
        System.out.println("------------------------------\n");
    }

    public static void Inicio() {
        System.out.println("\nBienvenido/a a la Biblioteca UAI. Que desea hacer?");
        System.out.println("   1. Deseas agregar un libro?");
        System.out.println("   2. Deseas editar un libro?");
        System.out.println("   3. Deseas eliminar un libro?");
        System.out.println("   4. Deseas buscar un libro?");
        System.out.println("   5. Deseas eliminar una sede?");
        System.out.println("   6. Deseas eliminar una seccion?");
        System.out.println("   7. Deseas eliminar un piso?");
        System.out.println("   (otro numero) Salir y guardar\n");
    }

    public static void Agregar() {
        System.out.println("\nIntroduzca los datos del libro que quiere agregar:");
    }

    public static void Editar() {
        System.out.println();
        System.out.println("1) Cambiar titulo");
        System.out.println("2) Cambiar autor");
        System.out.println("3) Cambiar anio");
        System.out.println("4) Cambiar numero de estante");
        System.out.println("5) Cambiar seccion");
        System.out.println("6) Cambiar piso");
        System.out.println("7) Cambiar edificio");
        System.out.println("8) Cambiar sede");
        System.out.println("9) Volver al menu");
    }

}
