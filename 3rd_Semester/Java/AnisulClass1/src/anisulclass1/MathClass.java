
package anisulclass1;

import java.util.Scanner;

public class MathClass {
    
    public static void main(String[] args) {
        int x=4;
        int y=3;
        
        int max=Math.max(x, y);
        System.out.println("Max = "+max);
        
        int min=Math.min(x, y);
        System.out.println("Min = "+min);
        
        double power=Math.pow(x, y);
        System.out.println("Power = "+power);
        
        double root=Math.sqrt(x);
        System.out.println("root x = "+root);
        
        double s=8.6;
        System.out.println("Round s = "+Math.round(s));
        
        int a=-8;
        System.out.println("abs a = "+Math.abs(a));
        
        double pi=Math.PI;
        System.out.println("Pi = "+pi);
        
        double e=Math.E;
        System.out.println("e = "+e);
    }
}
