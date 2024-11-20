public class firstClass
{
    public static void main(String[] args) {
        
        //System.out.println("sazzad");
        
 /*        mobile ph = new mobile("iphone",6,50);
        mobile s = new mobile(5,63);
        System.out.println(s.size);
        System.out.println(ph.name);
        System.out.println(s.camera);
        System.out.println(ph.camera);

        mobile myph = new mobile();
        myph.change("samsung");
        System.out.println(myph.name);
        System.out.println(myph.size);
    */    
    mobile1 ph = new mobile1("iphone",5,13);
    //mobile sazzad = new mobile();// constructor to constructor call
    //mobile sohan = new mobile(sazzad);// constructor obj pass

    System.out.println(ph.name);
    }
}

class mobile
{
    
    String name;
    int size;
    int camera;

    void change(String name)
    {
        this.name = name;
    }
    mobile(mobile obj)// constructor obj pass
    {
        this.name = obj.name;
        this.size = obj.size;
        this.camera = obj.camera;       
    }
    mobile()// constructor to constructor call
    {
        this("samsung",9,45);
    }
 /*    mobile()
    {
        this.name = "VIVO";
        this.size = 7;
        this.camera = 50;
    }*/
    mobile(String name,int size, int camera)
    {
        this.name = name;
        this.size = size;
        this.camera = camera;
    }
    mobile(int size, int camera)
    {
        this.size = size;
        this.camera = camera;
    }
}