import java.lang.reflect.ParameterizedType;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class RegexChk {

    public static boolean verify(String reg,String str){
        Pattern pattern=Pattern.compile(reg);
        Matcher matcher=pattern.matcher(str);
        boolean result=matcher.matches();
        return result;
    }
    //验证整数
    public static boolean verifyInt(String str){return verify("^-?[1-9]\\d*$|0",str);}
    //验证手机号码
    public static boolean verifyPhone(String str){return verify("^1\\d{10}$",str);}
    //验证电子邮箱
    public static boolean verifyEmail(String str){return verify("^.{3,}@\\.{1,2}$",str);}
    //验证邮政编码
    public static boolean verifyPostalCode(String str){return verify("^\\d{6}$",str);}
    //验证身份证号码
    public static boolean verifyIdCard(String str){return verify("^\\d{17}[1x]$",str);}

}
