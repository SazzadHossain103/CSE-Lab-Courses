
package javaapplication1;

public class NewClass {
    
    public static void main(String[] args)
    {
        //System.out.println("\"sazzad\" \n hossain");
        //System.out.println("01407499929");
                
        mobile ph = new mobile("iphone",6,50);
        mobile s = new mobile(5,63);
        System.out.println(s.size);
        System.out.println(ph.name);
        System.out.println(s.camera);
        System.out.println(ph.camera);
        
        mobile myph = new mobile();
        myph.change("sumsung");
        System.out.println(myph.name);
        System.out.println(myph.size);
        
    }
    
}
