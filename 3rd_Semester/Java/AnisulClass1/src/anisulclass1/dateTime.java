
package anisulclass1;

import java.text.DateFormat;
import java.text.SimpleDateFormat;
import java.time.LocalTime;
import java.time.format.DateTimeFormatter;
import java.util.Date;

public class dateTime {
    public static void main(String[] args) {
        
        Date d = new Date();
        DateFormat df = new SimpleDateFormat("dd/MM/YYYY");
        String date = df.format(d);
        System.out.println(date);
        
        LocalTime t = LocalTime.now();
        DateTimeFormatter tf = DateTimeFormatter.ofPattern("hh:mm:ss");
        String time = t.format(tf);
        System.out.println(time);
    }
}
