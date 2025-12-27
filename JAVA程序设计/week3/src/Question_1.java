//问题一：输出 101-200 之内的所有质数；

public class Question_1 {
    public static boolean isPrim(int x){
        for(int i=2;i*i<=x;i++){
            if(x%i==0)return false;
        }
        return true;
    }
    public static void main(String[] args) {
        System.out.println("101-200之间的所有素数：");
        for(int i=101;i<=200;i++){
            if(isPrim(i)) System.out.println(i);
        }
    }
}
