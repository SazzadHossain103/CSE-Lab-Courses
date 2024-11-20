
package array;

import java.util.ArrayList;
import java.util.Collections;

public class Arraylist {
    public static void main(String[] args) {
        ArrayList<Integer> num,num1,num2,num3;
        num = new ArrayList<Integer>();
        num1 = new ArrayList<Integer>();
        num2 = new ArrayList<Integer>();
        num3 = new ArrayList<Integer>();
    
        num.add(10);
        num.add(15);
        num.add(20);
        
        num1.add(5);
        num1.add(6);
        num1.add(7);
        
        System.out.println(num);
        System.out.println("size = "+num.size());
        
        //num.remove(1);
        //System.out.println(num);
        
        //num.clear();
        boolean empty = num.isEmpty();// ture or folse
        System.out.println("Empty = "+empty);
        
        boolean v = num.contains(20);// kono number khujar jonno
        System.out.println("Value ase = "+v);
        
        int x = num.indexOf(20);// index number 
        System.out.println("Value 20 r index = "+x);
        
        num.set(2,-30);//replace
        System.out.println("num = "+num);
        
        int a = num.get(1);
        System.out.println("Index 1 r value = "+a);
        
        num2.addAll(num1);
        System.out.println("num2 = "+num2);
        
        boolean r = num1.equals(num2);
        System.out.println("num1 & num2 are same = "+r);
        
        Collections.sort(num);
        System.out.println("Sorting num = "+num);
        
        Collections.reverse(num2);
        System.out.println("Reverse num2 = "+num2);
        
        num3.addAll(num);
        num3.addAll(num2);
        System.out.println("num3 = "+num3);
        Collections.sort(num3,Collections.reverseOrder());
        System.out.println("decsending num3 = "+num3);
    }    
}
