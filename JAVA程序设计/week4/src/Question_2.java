import javafx.beans.binding.DoubleExpression;

import java.util.Scanner;

public class Question_2 {
    static double x;
    int y;
    void setx(double x){
        this.x=x;
    }
    void sety(int y){
        this.y=y;
    }
    double getx(){
        return x;
    }
    int gety() {
        return y;
    }
}
class test{
    public static void main(String[] args) {
        System.out.println("为第一个对象赋值\n请输入double类型的x和int类型的y：");
        Scanner sc=new Scanner(System.in);
        double x=sc.nextDouble();
        int y=sc.nextInt();
        Question_2 q1=new Question_2();
        q1.sety(y);
        q1.setx(x);
        System.out.println("为第二个对象赋值\n请输入double类型的x和int类型的y：");
        Question_2 q2=new Question_2();
        x=sc.nextDouble();
        y=sc.nextInt();
        q2.sety(y);
        q2.setx(x);
        System.out.println("q1的x值为:"+q1.getx()+" q1的y值为："+q1.gety());
        System.out.println("q2的x值为:"+q2.getx()+" q2的y值为："+q2.gety());
    }


}