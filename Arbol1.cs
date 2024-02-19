using System;

class Nodo  // Arbol de busqueda
{
    private int dato;
    private Nodo izq;
    private Nodo der;

    public Nodo(int d)
    {
        dato = d;
        izq = der = null;
    } 

    public void ConectaIzq(Nodo ap)
    {
        izq = ap;
    }

    public void ConectaDer(Nodo ap)
    {
        der = ap;
    }

    public Nodo Izq()
    {
        return izq;
    }

    public Nodo Der()
    {
        return der;
    }

    public int Dato()
    {
        return dato;
    }

    public void Agregar(int d)
    {
        if (d < dato)
            if (izq == null)
                izq = new Nodo(d);
            else
                izq.Agregar(d);
        else
            if (d > dato)
               if (der == null)
                   der = new Nodo(d);
               else
                   der.Agregar(d);
            else
                Console.WriteLine("Dato ya existente");
    }
}

class Arbol
{
    private Nodo raiz;

    public Nodo Raiz()
    {
        return raiz;
    }

    private void Prev(Nodo ap)
    {
        if (ap != null)
        {
            Console.Write(" " + ap.Dato());
            Prev(ap.Izq());
            Prev(ap.Der());
        }
    }

    public void Previo()
    {
        Console.Write("Previo:");
        Prev(raiz);
        Console.WriteLine();    
    }

    public void AgregaNodo(int d)
    {
        if (raiz == null)
            raiz = new Nodo(d);
        else
            raiz.Agregar(d);        
    }


    public Nodo Busqueda(Nodo ap, int d)
    {
        if (ap != null)
            if (d > ap.Dato())
                return Busqueda(ap.Der(), d);
            else if (d < ap.Dato())
                return Busqueda(ap.Izq() ,d);
            else
                return ap;
        else
            return null;

    }


    public Nodo Busca(int d)
    {
        return Busqueda(raiz, d);
    }

}


class Program
{
    static void Main()
    {
        Arbol a1 = new Arbol();
        Nodo ap1;
        int n, i, d;
        Console.Write("Numero de datos ");
        n = int.Parse(Console.ReadLine());
        for (i = 0; i < n; i++)
        {
            Console.Write("Dato ");
            d = int.Parse(Console.ReadLine());
            a1.AgregaNodo(d);
        }
        a1.Previo();
        Console.Write("Dato ");
        d = int.Parse(Console.ReadLine());
        ap1 = a1.Busca(d);
        if (ap1 == null)
            Console.WriteLine("Dato inexistente");
    }
}

