import java.util.Objects;

public class Books {
    private String titulo;
    private String autor;
    private int anio;
    private int numeroEstante;
    private String seccionEstante;
    private int piso;
    private String edificio;
    private String sede;

    public Books() {
    }

    public Books(String titulo, String autor, int anio, int numeroEstante, String seccionEstante, int piso,
            String edificio, String sede) {
        this.titulo = titulo;
        this.autor = autor;
        this.anio = anio;
        this.numeroEstante = numeroEstante;
        this.seccionEstante = seccionEstante;
        this.piso = piso;
        this.edificio = edificio;
        this.sede = sede;
    }

    public String getTitulo() {
        return this.titulo;
    }

    public void setTitulo(String titulo) {
        this.titulo = titulo;
    }

    public String getAutor() {
        return this.autor;
    }

    public void setAutor(String autor) {
        this.autor = autor;
    }

    public int getAnio() {
        return this.anio;
    }

    public void setAnio(int anio) {
        this.anio = anio;
    }

    public int getNumeroEstante() {
        return this.numeroEstante;
    }

    public void setNumeroEstante(int numeroEstante) {
        this.numeroEstante = numeroEstante;
    }

    public String getSeccionEstante() {
        return this.seccionEstante;
    }

    public void setSeccionEstante(String seccionEstante) {
        this.seccionEstante = seccionEstante;
    }

    public int getPiso() {
        return this.piso;
    }

    public void setPiso(int piso) {
        this.piso = piso;
    }

    public String getEdificio() {
        return this.edificio;
    }

    public void setEdificio(String edificio) {
        this.edificio = edificio;
    }

    public String getSede() {
        return this.sede;
    }

    public void setSede(String sede) {
        this.sede = sede;
    }

    public Books titulo(String titulo) {
        setTitulo(titulo);
        return this;
    }

    public Books autor(String autor) {
        setAutor(autor);
        return this;
    }

    public Books anio(int anio) {
        setAnio(anio);
        return this;
    }

    public Books numeroEstante(int numeroEstante) {
        setNumeroEstante(numeroEstante);
        return this;
    }

    public Books seccionEstante(String seccionEstante) {
        setSeccionEstante(seccionEstante);
        return this;
    }

    public Books piso(int piso) {
        setPiso(piso);
        return this;
    }

    public Books edificio(String edificio) {
        setEdificio(edificio);
        return this;
    }

    public Books sede(String sede) {
        setSede(sede);
        return this;
    }

    @Override
    public boolean equals(Object o) {
        if (o == this)
            return true;
        if (!(o instanceof Books)) {
            return false;
        }
        Books books = (Books) o;
        return Objects.equals(titulo, books.titulo) && Objects.equals(autor, books.autor) && anio == books.anio
                && numeroEstante == books.numeroEstante && Objects.equals(seccionEstante, books.seccionEstante)
                && piso == books.piso && Objects.equals(edificio, books.edificio) && Objects.equals(sede, books.sede);
    }

    @Override
    public int hashCode() {
        return Objects.hash(titulo, autor, anio, numeroEstante, seccionEstante, piso, edificio, sede);
    }

    @Override
    public String toString() {
        return "{" + " titulo='" + getTitulo() + "'" + ", autor='" + getAutor() + "'" + ", anio='" + getAnio() + "'"
                + ", numeroEstante='" + getNumeroEstante() + "'" + ", seccionEstante='" + getSeccionEstante() + "'"
                + ", piso='" + getPiso() + "'" + ", edificio='" + getEdificio() + "'" + ", sede='" + getSede() + "'"
                + "}";
    }
}