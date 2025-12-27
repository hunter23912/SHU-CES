public class UndergraduateException extends Exception{
    public String message;
    public UndergraduateException(){
        message="【warning】：该学生的某门课成绩不在0-100的范围内！";
    }
    public String warnMess(){
        return message;
    }


}
