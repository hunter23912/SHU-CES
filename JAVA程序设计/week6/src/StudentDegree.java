import java.rmi.server.ExportException;

public class StudentDegree {
    //输出学位授予情况
    public void issueDegree(Manageable manage) throws Exception {
        manage.printInfo();
        System.out.println(" 课程成绩平均分为：" + manage.computeAverage());
        manage.getPass();
    }



}
