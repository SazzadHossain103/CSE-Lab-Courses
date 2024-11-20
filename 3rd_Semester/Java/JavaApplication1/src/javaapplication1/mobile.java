
package javaapplication1;

public class mobile {
    String name;
    int size;
    int camera;

    void change(String name)
    {
        this.name = name;
    }
    mobile()
    {
        this.name = "VIVO";
        this.size = 7;
        this.camera = 50;
    }
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
