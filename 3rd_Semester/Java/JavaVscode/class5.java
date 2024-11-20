public class class5 {
    public static void main(String[] args) {
        omanush jubiyer = new omanush();
        System.out.println(jubiyer.name);
    }
}

 class manush {
    String name;
    int hat;
    int pa;

    manush() {
        this("ami default", 5, 6);
    }

    manush(String n, int h, int p) {
        this.name = n;
        this.hat = h;
        this.pa = p;
    }
}

 class omanush extends manush {// inheritance
    int cokh;

    omanush() {
        this.cokh = 3;
    }

    omanush(String n, int h, int p, int cc) {
        this.cokh = cc;
    }
}
