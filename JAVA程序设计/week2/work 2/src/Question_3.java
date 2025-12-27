import java.util.Random;
import java.util.Scanner;
import java.util.zip.CheckedOutputStream;
//题目三：请按照下图剪刀石头布的游戏规则，采用 switch 分支结构实现人
//与机器进行剪刀石头布游戏。游戏规则和信息提示如下：
//（1） 每次游戏时，程序提示从命令行输入 1、2 或 3，分别作为
//剪刀、石头和布；
//（2） 机器由程序随机生成剪刀、石头或布等三种中的一种；
//（3） 根据下图游戏规则，输出人与机器游戏的结果；
public class Question_3 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        System.out.println("——自动剪刀石头布游戏——");
        while(true){
            System.out.println("(1)剪刀   (2)石头   (3)布    (other)退出");
            System.out.println("请输入你的选择：");
            int ch=sc.nextInt();
            if(ch!=1&&ch!=2&&ch!=3)break;
            Random random=new Random();
            int computer=random.nextInt(3)+1;
            switch (ch){
                case 1:
                    if(computer==1) System.out.println("电脑：剪刀    \n平局！");
                    else if(computer==2) System.out.println("电脑：石头    \n电脑获胜！");
                    else System.out.println("电脑：布    \n玩家获胜！");
                    break;
                case 2:
                    if(computer==1) System.out.println("电脑：剪刀    \n玩家获胜！");
                    else if(computer==2) System.out.println("电脑：石头    \n平局！");
                    else System.out.println("电脑：布    \n电脑获胜！");
                    break;
                case 3:
                    if(computer==1) System.out.println("电脑：剪刀    \n电脑获胜！");
                    else if(computer==2) System.out.println("电脑：石头    \n玩家获胜！");
                    else System.out.println("电脑：布    \n平局！");
                    break;
                default:
                    break;
            }
            System.out.println("\n\n");
        }
        System.out.println("欢迎下次游玩！");

    }
}
