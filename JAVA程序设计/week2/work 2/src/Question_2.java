//题目二：输出 1-100 之内前 5 个能被 3 整除的数；
public class Question_2 {
    public static void main(String[] args) {
        System.out.println("输出 1-100 之内前 5 个能被 3 整除的数；");
        int cnt=0;
        for(int i=1;i<=100;i++){
            if(i%3==0){
                cnt++;
                System.out.println(i);
                if(cnt==5)break;
            }
        }
    }
}
