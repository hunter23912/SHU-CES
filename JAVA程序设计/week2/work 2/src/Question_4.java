//题目四：请在 Eclipse 或 IntelliJ IDEA IDE 开发环境下输入如下代码：
//（1） 请测试输出结果，并解释为何如此？
//（2） 将程序中黑体的 break 替换为 continue，请测试输出结果，
//并解释为何如此？
//详见文件夹下的word
public class Question_4 {
    public static void main(String[] args) {
        int count= 0 ;
        for(int i=0; i<3; i++) {
            for(int j=0; j<3; j++) {
                if ( i==1 && j==1)continue;
                count++;
            }
        }
        System.out.println(count);
    }
}
