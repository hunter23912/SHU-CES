import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.zip.CheckedOutputStream;

public class StudentApplication {
    public static void main(String[] args) throws ParseException {
        Student student;
        //创建undergraduate对象
        Undergraduate undergraduate = new Undergraduate();
        undergraduate.setName("王小二");
        undergraduate.setGender('男');
        String bir = "2001/06/01";
        Date date = new SimpleDateFormat("yyyy/MM/dd").parse(bir);
        undergraduate.setBirthDay(date);
        //System.out.println("date:" + date);
        undergraduate.setSchool("上海大学");
        undergraduate.setStuId("11128981");
        undergraduate.setCategory(Constants.UNDERGRADUATE);
        double []sc={89.5,82,87,73};
        undergraduate.setScore(sc);
        undergraduate.setStatus(false);
        //创建master对象
        Master master = new Master();
        master.setName("李燕");
        master.setGender('女');
        String b = "1999/06/12";
        Date dat = new SimpleDateFormat("yyyy/MM/dd").parse(b);
        master.setBirthDay(dat);
        //System.out.println("dat:" + dat);
        master.setSchool("上海大学");
        master.setStuId("10306");
        master.setCategory(Constants.MASTER);
        double []s={70,52.5,95,88,89,91};
        master.setScore(s);
        master.thesisLevel='B';
        master.setStatus(false);
        //创建StudentDegree类进行测试
        StudentDegree studentDegree=new StudentDegree();
        //王小虎
        student=undergraduate;
        studentDegree.printStudentInfo(student);
        studentDegree.issueDegree(student);
        System.out.println("\n");
        //李燕
        student=master;
        studentDegree.printStudentInfo(student);
        studentDegree.issueDegree(student);


    }


}
