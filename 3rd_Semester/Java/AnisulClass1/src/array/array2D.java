
package array;

import java.util.Scanner;

public class array2D {
    public static void main(String[] args) {
        int [][] num = new int[2][2];
        num[0][0]=10;
        num[0][1]=10;
        num[1][0]=10;
        num[1][1]=10;
        
        for(int i=0; i<2; i++)
        {
            for(int j=0; j<2; j++)
            {
                System.out.print(" "+num[i][j]);
            }
            System.out.println();
        }
        
        Scanner input = new Scanner(System.in);
        int [][] a = new int[2][2];
        int [][] b = new int[2][2];
        for(int i=0; i<2; i++)
        {
            for(int j=0; j<2; j++)
            {
                a[i][j]=input.nextInt();
            }
        }
    }
}
