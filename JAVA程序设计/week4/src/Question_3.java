import java.util.Scanner;

public class Question_3 {
    public static void main(String[] args) {
        System.out.println("请输入点a的横纵坐标：");
        Scanner sc=new Scanner(System.in);
        double x1,y1,x2,y2;
        x1=sc.nextDouble();
        y1=sc.nextDouble();
        Point a=new Point(x1,y1);
        System.out.println("请输入点b的横纵坐标：");
        x2=sc.nextDouble();
        y2=sc.nextDouble();
        Point b=new Point(x2,y2);
        Line l=new Line(a,b);
        System.out.println("a、b两点之间直线的长度为："+l.getLength());

    }
}
class Point{
    double x,y;
    Point(double x,double y){
        this.x=x;this.y=y;
    }
}
class Line{
    Point st,end;
    Line(Point st,Point end){
        this.st=st;
        this.end=end;
    }
    double getLength(){
        return Math.sqrt(Math.pow(st.x-end.x,2)+ Math.pow(st.y-end.y,2));
    }
}