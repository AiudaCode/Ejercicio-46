import javax.swing.JOptionPane;

public class Main
{
    // método para llenar la lista
    public static void llenar(Niño nod)
    {
        int e;
        // con el ciclo do while comprobare que la edad este entre el rango de 1 y 6 años
        do
        {
            e = Integer.parseInt(JOptionPane.showInputDialog(null,"Ingrese edad del niño:")); 
        }
        while (e < 1 || e > 6);
        // encapsulo la variable e
        nod.setEdad(e); 
        // se pide el nombre del niño
        String n = JOptionPane.showInputDialog(null,"Ingrese nombre del niño:");
        // encapsulo la variable n
        nod.setNombre(n);
        // se pide el registro civil del niño
        int n_r = Integer.parseInt(JOptionPane.showInputDialog(null,"Ingrese número de registro civil del niño:")); 
        // encapsulo la variable n_r
        nod.setRegistroCivil(n_r);
        // se pide la altura del niño
        float a = Float.parseFloat(JOptionPane.showInputDialog(null,"Ingrese altura del niño:")); 
        // se encapsula la variable a
        nod.setAltura(a);
        // se pide el peso del niño
        int p = Integer.parseInt(JOptionPane.showInputDialog(null,"Ingrese peso del niño:"));
        // se encapsula la variable p
        nod.setPeso(p);
        // se pide el numero de identificacion del padre
        int id = Integer.parseInt(JOptionPane.showInputDialog(null,"Ingrese número de identificación del padre/madre del niño:"));
        // se encapsula la variable id
        nod.setIdPadre(id);
        // se pide el nombre del padre o la madre del niño
        String n_p = JOptionPane.showInputDialog(null,"Ingrese nombre del padre/madre del niño:"); 
        // se encapsula la variable n_p
        nod.setNombrePadre(n_p);
        int m;
        // con el ciclo do while comprobare que se ingrese el municipio correcto
        do
        {
            m = Integer.parseInt(JOptionPane.showInputDialog(null,
                "Ingrese municipio donde vive el niño\n" +
                "1. Sahagún\n" +
                "2. Montería\n" +
                "3. Lorica\n"));
        }
        while (m < 1 || m > 3);
        // se encapsula la variable m
        nod.setMunicipio(m);
    }
    
    // método para mostrar el municipio
    public static String mostrarMunicipio(int opc)
    {
        // mediante el valor que se pase como parametro opc, el switch escore el caso
        switch (opc)
        {
            case 1:
                return "Sahagún";
            case 2:
                return "Montería";
            default:
                return "Lorica";
        }
    }
    
    // método para mostrar la informacion del niño
    public static void mostrar(Niño nod)
    {
        // declaro una variable de tipo String datos y la inicializo en ""
        String datos = ""; 
        // le acumulo a la variable datos los valores convertidos a String del niño
        datos += String.valueOf(
                "Nombre: " + nod.getNombre() + "\n" +
                "Edad: " + nod.getEdad() + "\n" +
                "Registro Civil: " + nod.getRegistroCivil() + "\n" +
                "Altura: " + nod.getAltura() + "\n" +
                "Peso: " + nod.getPeso() + "\n" +
                "Nombre representante: " + nod.getNombrePadre() + "\n" +
                "ID representante: " + nod.getIdPadre() + "\n" +
                "Municipio: " + mostrarMunicipio(nod.getMunicipio()) + "\n\n");
        // muestro con mensaje de dialogo la variable datos
        JOptionPane.showMessageDialog(null,datos); 
    } 
    
    // método para listar todos la lista
    public static void listar(ProgramaDepartamental obj)
    {
        // declaro e inicializo la variable temp en el valor que tenga la cabeza
        Niño temp = obj.getCabeza(); 
        // mientras haya un nodo en la lista
        while (temp != null)
        {
            // entonces mostrara la informacion del nodo temp
            mostrar(temp);
            // y se salta al siguiente nodo temp
            temp = temp.getSiguiente();
        }
    }
    
    // método para listar los niños por municipio
    public static void listarPorMunicipio(ProgramaDepartamental obj)
    {
        // como son 3 municipios, entonces recorrere con el ciclo for desde 1 hasta 3
        for (int i = 1; i <= 3; i++)
        {
            // muestro en un mensaje de dialogo, el municipio actual: mostrarMunicipio(i)
            JOptionPane.showMessageDialog(null, "[Niños del municipio de " + mostrarMunicipio(i) + "]");
            // declaro e inicializo la variable temp con el valor de la cabeza
            Niño temp = obj.getCabeza();
            // mientras haya un nodo en la lista
            while (temp != null)
            {
                // entonces, si el nodo temp pertenece al municipio i (i = 0: Sahagún, i = 1: Montería, i = 2: Lorica)
                if (temp.getMunicipio() == i)
                {
                    // se muestra la información del nodo temp
                    mostrar(temp);
                }
                // se salta al siguiente nodo temporal
                temp = temp.getSiguiente();
            }
            // muestro la cantidad de niños de cada municipio, llamando al metodo contarNiñosMunicipio y pasandole como parametro i
            JOptionPane.showMessageDialog(null, "Hay " + obj.contarNiñosMunicipio(i) + " niño(s) en el municipio de " + mostrarMunicipio(i));
        }
    }
    
    // método para listar cada niño si cumple las condiciones de peso bajo
    public static void listarPorCondicionesPeso(ProgramaDepartamental obj)
    {
        JOptionPane.showMessageDialog(null, "[Niños de 2 y 3 o 4 y 6 años en condiciones de bajo peso]");
        // como son 3 municipios, entonces recorrere con el ciclo for desde 1 hasta 3
        for (int i = 1; i <= 3; i++)
        {
            // declaro e inicializo la variable temp con el valor de la cabeza
            Niño temp = obj.getCabeza();
            // mientras haya un nodo en la lista
            while (temp != null)
            {
                // entonces, si el municipio es igual a i, y tiene una edad entre 2 y 3 años y pesa menos de 15 kg ó si tiene una edad entre 4 y 6 y pesa menos de 25 kg
                if (temp.getMunicipio() == i && ((temp.getEdad() >= 2 && temp.getEdad() <= 3) && temp.getPeso() < 15) || temp.getMunicipio() == i && ((temp.getEdad() >= 4 && temp.getEdad() <= 6) && temp.getPeso() < 25))
                {
                    // se mostrara la informacion del nodo temp
                    mostrar(temp);
                }
                // se salta al siguiente nodo temp
                temp = temp.getSiguiente();
            }
            // se muestra la cantidad de niños en condiciones de bajo peso por municipio
            JOptionPane.showMessageDialog(null, "Hay " + obj.contarNiñosMunicipioPeso(i) + " niño(s) en el municipio de " + mostrarMunicipio(i) + " en condiciones de bajo peso.");
        }
    }
    
    // método para listar cada niño si tiene una altura menor a 1 metro
    public static void listarPorAltura(ProgramaDepartamental obj)
    {
        JOptionPane.showMessageDialog(null, "[Niños entre 4 y 6 años que miden menos de 1 metro]");
        // como son 3 municipios, entonces recorrere con el ciclo for desde 1 hasta 3
        for (int i = 1; i <= 3; i++)
        {
            // declaro e inicializo la variable temp con el valor de la cabeza
            Niño temp = obj.getCabeza();
            // mientras haya un nodo en la lista
            while (temp != null)
            {
                // si el niño esta en el municipio i y tiene una edad entre 4 y 6 años y tiene una altura menor a 1 m
                if (temp.getMunicipio() == i && ((temp.getEdad() >= 4 && temp.getEdad() <= 6) && temp.getAltura() < 1))
                {
                    // entonces se mostrara la información del nodo temp
                    mostrar(temp);
                }
                // se salta al siguiente nodo temp
                temp = temp.getSiguiente();
            }
            // se muestra la cantidad de niños con una estatura menor a 1m por municipio
            JOptionPane.showMessageDialog(null, "Hay " + obj.contarNiñosPorAltura(i) + " niño(s) en el municipio de " + mostrarMunicipio(i) + " en condiciones de bajo peso.");
        }
    }
    
    // método para mostrar el menu de opciones
    public static int menu()
    { 
        int opc; 
        do
        {
            opc = Integer.parseInt(JOptionPane.showInputDialog(null,
                "==================MENU==================\n" +
                "1. Agregar información del niño y su representante por el final.\n" +
                "2. Insertar entre dos nodos existentes.\n" +
                "3. Agregar información del niño y su representante por el principio.\n" +
                "4. Buscar por número de registro civil.\n" +
                "5. Ordenar la información, teniendo en cuenta el peso de los niños.\n" +
                "6. Eliminar la información de un niño y su representante.\n" +
                "7. Listado por municipios.\n" +
                "8. Listado por condiciones bajos de peso.\n" +
                "9. Listado por altura.\n" +
                "10. Mostrar toda la lista\n" +
                "11. Salir")); 
        }
        while (opc < 0 || opc > 11);
        return opc; 
    } 
    
    public static void main(String[] args)
    {
        // creo un objeto de la clase ProgramaDepartamental (instanciación)
        ProgramaDepartamental obj = new ProgramaDepartamental();
        // declaro una variable de tipo Niño
        Niño aux;
        // declaro dos variables de tipo entero opcion y num_reg
        int opcion, num_reg;
        do
        { 
           // se le asigna a la variable opcion el valor que retorne el metodo menu
           opcion = menu();
           // dependiendo del valor de la opcion se escogera un caso
           switch(opcion)
           {
                case 1:
                    aux = new Niño();
                    llenar(aux);
                    obj.agregarFinal(aux);
                    JOptionPane.showMessageDialog(null,"Se ha agregado correctamente la información");
                    break;
                case 2:
                    num_reg = Integer.parseInt(JOptionPane.showInputDialog(null,"Ingrese número de registro del nodo anterior al que desea agregar:")); 
                    aux = obj.buscar(num_reg);
                    if(aux != null)
                    {
                        aux = new Niño(); 
                        llenar(aux);
                        obj.agregarEntreNodos(obj.buscar(num_reg), aux); 
                        JOptionPane.showMessageDialog(null,"Se ha agregado correctamente la información");
                    }
                    else
                    {
                        JOptionPane.showMessageDialog(null,"No se ha encontrado el nodo!"); 
                    }
                    break;
                case 3:
                    aux = new Niño();
                    llenar(aux);
                    obj.agregarInicio(aux);
                    JOptionPane.showMessageDialog(null,"Se ha agregado correctamente la información");
                    break;
                case 4:
                    num_reg = Integer.parseInt(JOptionPane.showInputDialog(null,"Ingrese número de registro del nodo anterior al que desea agregar:")); 
                    aux = obj.buscar(num_reg);
                    if(aux != null)
                    {
                        mostrar(obj.buscar(num_reg)); 
                    }
                    else
                    {
                        JOptionPane.showMessageDialog(null,"No se ha encontrado el nodo!"); 
                    }
                    break;
                case 5:
                    aux = obj.getCabeza();
                    if (aux != null)
                    {
                        if(obj.contarNodos() > 1)
                        {
                            aux = obj.getCabeza();
                            obj.ordenarIntercambio(aux);
                            listar(obj);
                        }
                        else
                        {
                            JOptionPane.showMessageDialog(null, "Solo hay un niño, agregue por lo menos 1 niño mas para ordenar.");
                        }
                    }
                    break;
                case 6:
                    aux = obj.getCabeza();
                    obj.eliminarNodo(aux);
                    JOptionPane.showMessageDialog(null, "Se elimino correctamente.");
                    break;
                case 7:
                    listarPorMunicipio(obj);
                    break;
                case 8:
                    listarPorCondicionesPeso(obj);
                    break;
                case 9:
                    listarPorAltura(obj);
                    break;
                case 10:
                    listar(obj);
                    break;
                default:
                    break;
           } 
        }
        while (opcion != 11);
    }
}