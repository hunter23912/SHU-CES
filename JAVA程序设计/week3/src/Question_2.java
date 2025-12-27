import java.util.Scanner;

//第二题
//三角形
class Triangle{
    double x,y,z;
    boolean isTriangle=false;
     Triangle(double x,double y,double z){
        this.x=x;
        this.y=y;
        this.z=z;
        if(x+y>z&&x+z>y&&z+y>x)this.isTriangle=true;
        else this.isTriangle=false;
    }
    public double getPerimeter(){
         return x+y+z;
    }
    public void modify(double x,double y,double z){
        this.x=x;
        this.y=y;
        this.z=z;
    }
}
//圆形
class Circle{
    double r,area;
    public Circle(double r){
        this.r=r;
        this.area= Math.PI*r*r;
    }
    public void modify(double r){
        this.r=r;
        this.area= Math.PI*r*r;
    }
}
//圆锥体
class Cone{
    Circle c;
    double h;
    public Cone(Circle c,double h){
        this.c=c;
        this.h=h;
    }
    public double getVolum(){
        return c.area*h/3;
    }
}

public class Question_2 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        //三角形
        System.out.println("三角形：\n请输入三角形的三条边:");
        double x=0,y=0,z=0;
        x=sc.nextDouble();
        y=sc.nextDouble();
        z=sc.nextDouble();
        Triangle t=new Triangle(x,y,z);
        System.out.println("周长为："+t.getPerimeter());
        System.out.println("这个图形"+(t.isTriangle==true?"是":"不是")+"三角形");
        System.out.println("请输入修改后的三条边：");
        x=sc.nextDouble();
        y=sc.nextDouble();
        z=sc.nextDouble();
        t.modify(x,y,z);
        System.out.println("这个图形"+(t.isTriangle==true?"是":"不是")+"三角形");
        //圆和圆锥;
        System.out.println("圆：\n请输入圆的半径:");
        double r=sc.nextDouble();
        Circle ci=new Circle(r);
        System.out.println("圆的面积为："+ci.area);
        System.out.println("圆锥：\n请输入圆锥的高：");
        double h=sc.nextDouble();
        System.out.println("请输入圆锥的底面半径：");
        r=sc.nextDouble();
        ci.modify(r);
        Cone cc=new Cone(ci,h);
        System.out.println("圆锥体的体积为："+cc.getVolum());




    }
}
