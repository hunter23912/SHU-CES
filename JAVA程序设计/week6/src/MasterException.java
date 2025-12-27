public class MasterException extends Exception{
    public String message;
    public MasterException(){
        message="【warning】：研究生成绩或论文等级异常";
    }
    public MasterException(String msg){
        message=msg;
    }
    public String warnMess(){
        return message;
    }


}
