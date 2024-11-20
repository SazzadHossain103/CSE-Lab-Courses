public class class6 {
    public static void main(String[] args) {
        //manush obj = new omanush();
        omanush obj = new omanush();
        //obj.doctor();
        obj.bmw();

        omanush obj2 = new omanush();
        //System.out.println(obj2.hack());

        obj2.set("sohan tor pass hack korse");
        System.out.println(obj2.hack());


    }
}
abstract class manush{
    abstract void doctor();
    abstract void bmw();
}
class omanush extends manush{
    void doctor(){
        System.out.println("doctor hoiya gesi");
    }
    void bmw(){
        System.out.println("car");
    }

    private String pass = "jjake3";
    //getter
    public String hack(){
        return pass;
    }
    //setter
    public void set(String s){
        this.pass=s;
    }
}