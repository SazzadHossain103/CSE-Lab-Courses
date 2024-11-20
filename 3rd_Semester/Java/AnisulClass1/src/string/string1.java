
package string;

public class string1 {
    public static void main(String[] args) {
        String s1 = "Sazzad";
        String s2,s3,s4;
        s2=" Hossain";
        s3=" i love you";
        
        int len = s1.length();
        System.out.println(s1);
        System.out.println("len = "+len);
        
        //equalsIngnoreCase() contains()
        if(s1.equals(s2)){
            System.out.println("Equals");
        }
        else{
            System.out.println("Not equals");
        }
        s4=s1.concat(s3);
        System.out.println(s4);
        System.out.println(s4.toUpperCase());
        boolean con=s1.contains(s3); // kono string khuja
        boolean b=s1.isEmpty();
        
       // concat(); add kora
       // toUpperCase();
       // toLowerCase();
       // startsWith(); kono string r suru ki diya 
       // endsWhith();
       // indexOf('z'); koto tomo index ase ber kore
       // lastIndexOf('a'); 
       // trim(); fast and last space dlt kore
       // charAt(0); index r char ber kore
       // codePointAt(0); string index r ascci value ber kore
       // replace('z','j');
       
       boolean t=s1.startsWith("Saz");
        System.out.println(t);
        //String [] ss = new String [5];
        String[] frd ={"sazzad","ramim","sohan"};
        for(String a : frd){
            System.out.println(a);
        }
    }
}
