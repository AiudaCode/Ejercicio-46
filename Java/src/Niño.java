public class Niño
{
    // atributos privados de la clase Niño
    private int edad;
    private String nombre;
    private int registro_civil;
    private float altura;
    private int peso;
    private int id_padre;
    private String nombre_padre;
    private int municipio;
    private Niño siguiente;
    private Niño anterior;
    
    public Niño()
    {
        // se le asigna valores por defecto en el constructor a los atributos de la clase Niño
        edad = 0;
        nombre = "";
        registro_civil = 0;
        altura = 0;
        peso = 0;
        id_padre = 0;
        nombre_padre = "";
        municipio = 0;
        siguiente = null;
        anterior = null;
    }
    
    // metodos Setters y Getters de los atributos de la clase
    public void setEdad(int val)
    {
        edad = val;
    }
    
    public int getEdad()
    {
        return edad;
    }
    
    public void setNombre(String val)
    {
        nombre = val;
    }
    
    public String getNombre()
    {
        return nombre;
    }
    
    public void setRegistroCivil(int val)
    {
        registro_civil = val;
    }
    
    public int getRegistroCivil()
    {
        return registro_civil;
    }
    
    public void setAltura(float val)
    {
        altura = val;
    }
    
    public float getAltura()
    {
        return altura;
    }
    
    public void setPeso(int val)
    {
        peso = val;
    }
    
    public int getPeso()
    {
        return peso;
    }
    
    public void setIdPadre(int val)
    {
        id_padre = val;
    }
    
    public int getIdPadre()
    {
        return id_padre;
    }
    
    public void setNombrePadre(String val)
    {
        nombre_padre = val;
    }
    
    public String getNombrePadre()
    {
        return nombre_padre;
    }
    
    public void setMunicipio(int val)
    {
        municipio = val;
    }
    
    public int getMunicipio()
    {
        return municipio;
    }
    
    public void setSiguiente(Niño val)
    {
        siguiente = val;
    }
    
    public Niño getSiguiente()
    {
        return siguiente;
    }
    
    public void setAnterior(Niño val)
    {
        anterior = val;
    }
    
    public Niño getAnterior()
    {
        return anterior;
    }
    
    // método para copiar toda la información de un nodo
    public void copiar(Niño nd)
    {
        edad = nd.getEdad();
        nombre = nd.getNombre();
        registro_civil = nd.getRegistroCivil();
        altura = nd.getAltura();
        peso = nd.getPeso();
        id_padre = nd.getIdPadre();
        nombre_padre = nd.getNombrePadre();
    }
}