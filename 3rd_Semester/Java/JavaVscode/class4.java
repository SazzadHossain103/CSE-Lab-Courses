public class class4 {
    
    static class uits{ //Inerclass
        String s;
        public uits(String name){
            this.s=name;
        }
    }

    static int i=4;
    static int j=5;

    static{//static block static constructor
        System.out.println("ami kaj kortasi");
        j=i+2; //j=6
    }

    public static void main(String[] args) {
        class4 rifat = new class4();
        //rifat.i=3;
        System.out.println(rifat.i + " "+rifat.j);
        class4.i += 2;

        class4 ramim = new class4();
        System.out.println(ramim.i +" "+ ramim.j);

        uits sohan = new uits("sazzad");
        System.out.println(sohan.s);
    }
}
