 public class class3{
 public static void main(String[] args) {
    ramim first = new ramim();
    ramim ss = new ramim(first);
    
    System.out.println(ss.hat);
    System.out.println(first.kan);
    System.out.println(ss.kan);
} 
}
class ramim
{
    int hat;
    int pa;
    static int kan;

    ramim(ramim ss)
    {
        this.hat=ss.hat;
        this.pa=ss.pa;
        //ramim.kan=2;

    }
    ramim()
    {
        this(3,4);
    }
    ramim(int hat,int pa)
    {
        this.hat=hat;
        this.pa=pa;
        ramim.kan=3;
        //this.kan=kan;

    }
    
}