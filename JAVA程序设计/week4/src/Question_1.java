import java.util.Scanner;

//第一题
public class Question_1 {
}
class Parameter{
    double a,b;
}
class computePower{
    static void compPower(double x,double y){
        System.out.println(x+"的平方是："+x*x);
        System.out.println(y+"的平方是："+y*y);
        x=x*x;y=y*y;
        System.out.println("静态函数中：");
        System.out.println("计算后x和y的值为："+x+" "+y);
    }
    static void compPower(Parameter x) {
        System.out.println(x.a+"的平方是："+x.a*x.a);
        System.out.println(x.b+"的平方是："+x.b*x.b);
        x.a=x.a*x.a;x.b=x.b*x.b;
        System.out.println("计算后静态函数中：");
        System.out.println("计算后x和y的值为："+x.a+" "+x.b);

    }
}
class computePowerTest{
    public static void main(String[] args) {
        double x,y;
        System.out.println("基本数据类型值传递：\n请输入两个数字x和y：");
        Scanner sc=new Scanner(System.in);
        x=sc.nextDouble();
        y=sc.nextDouble();
        computePower.compPower(x,y);
        System.out.println("主函数中：");
        System.out.println("计算后x和y的值为："+x+" "+y);
        Parameter p=new Parameter();
        System.out.println("传引用------------------------------------");
        p.a=x;p.b=y;
        computePower.compPower(p);
        System.out.println("主函数中：");
        System.out.println("计算后x和y的值为："+p.a+" "+p.b);
    }
}