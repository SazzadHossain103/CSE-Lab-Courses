public class class2 {
    public static void main(String[] args) {
        
        mobile1 ph = new mobile1("iphone",5,13);
        //mobile sazzad = new mobile();// constructor to constructor call
        //mobile sohan = new mobile(sazzad);// constructor obj pass
    
        System.out.println(ph.name);

    }
}
class mobile1
{
    String name;
    int size;
    int camera;
    
    mobile1(mobile1 obj)// constructor obj pass
    {
        this.name = obj.name;
        this.size = obj.size;
        this.camera = obj.camera;       
    }
    mobile1()// constructor to constructor call
    {
        this("samsung",9,45);
    }
    mobile1(String name,int size, int camera)
    {
        this.name = name;
        this.size = size;
        this.camera = camera;
    }
    mobile1(int size, int camera)
    {
        this.size = size;
        this.camera = camera;
    }
}