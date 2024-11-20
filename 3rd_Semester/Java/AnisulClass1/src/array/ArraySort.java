
package array;

import java.util.Arrays;

public class ArraySort {
    
    public static void main(String[] args) {
        int [] n = new int[5]; // diclear array
        String [] ss = new String [5];
        
        int [] num={5,8,6,7,2,-3,-5};
        Arrays.sort(num);
        
        for(int x : num )
        {
            System.out.print(x+" ");
        }
        System.out.println();
        for(int i=num.length-1; i>=0; i--)
        {
            System.out.print(num[i]+" ");
        }
        System.out.println();
        
        String[] names={"Sazzad","Sohan","Rimim","Keya","Mim","Elmi"};
        Arrays.sort(names);
        for(String s : names)
        {
            System.out.print(s+" ");
        }
        System.out.println();
    }
}
