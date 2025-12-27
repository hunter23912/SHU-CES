
//题目一：实现用户从键盘上输入 3 个 1-100 的整数；每输入一次，检查当
//前输入是否为有效输入，直到有效次数为 3 结束程序，统计三次
//有效输入和输出；要求能够给出无效提示和正确输入次数提示。
import java.util.Scanner;

public class Question_1 {
    public static void main(String[] args) {

        int count=0;
        int cnttrue=0;
        int cntfalse=0;
        System.out.println("请输入三个1-100之间的数字！");
        while(true){
            count++;
            Scanner sc=new Scanner(System.in);
            try {
                int num=sc.nextInt();
                if(num>=1&&num<=100){
                    cnttrue++;
                    if(cnttrue==3)break;
                    System.out.println("输入正确，还需输入"+(3-cnttrue)+"次");
                }
                else {
                    cntfalse++;
                    System.out.println("输入错误，请输入1-100之间的数字！还需输入"+(3-cnttrue)+"次");
                }
            }catch (Exception e){
                System.out.println("请输入正确的数字格式");
            }

        }
        System.out.println("输入完毕，总共输入"+count+"次，其中输入有效次数为3次，输入无效次数为"+cntfalse+"次");


    }
}
