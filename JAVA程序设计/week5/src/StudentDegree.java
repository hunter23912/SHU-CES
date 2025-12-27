public class StudentDegree {
    //输出学生信息
    public void printStudentInfo(Student student){
        System.out.println("姓名："+student.getName());
        System.out.println("性别："+student.getGender());
        System.out.println("出生日期："+student.getBirthDay());
        System.out.println("学校："+student.getSchool());
        System.out.println("学号："+student.getStuId());
        System.out.println("学生类别："+student.getCategory());
        System.out.println("平均成绩："+student.computeAverage());
    }
    //输出学位授予情况
    public void issueDegree(Student student){
        System.out.println("学位情况："+student.getDegree());
    }



}
