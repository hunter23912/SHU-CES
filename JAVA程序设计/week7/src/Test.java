import java.sql.SQLOutput;

public class Test {

    public static void main(String[] args) {
        //验证整数
        System.out.println("验证整数：");
        System.out.println("0:"+RegexChk.verifyInt("0"));
        System.out.println("-0:"+RegexChk.verifyInt("-0"));
        System.out.println("+0:"+RegexChk.verifyInt("+0"));
        System.out.println("10:"+RegexChk.verifyInt("10"));
        System.out.println("-10:"+RegexChk.verifyInt("-10"));
        System.out.println("1.5:"+RegexChk.verifyInt("1.5"));
        System.out.println("-1.5:"+RegexChk.verifyInt("-1.5"));

        //验证手机号码
        System.out.println("验证手机号码：");
        System.out.println("123456:"+RegexChk.verifyPhone("123456"));
        System.out.println("12345678912:"+RegexChk.verifyPhone("12345678912"));
        System.out.println("123456789123:"+RegexChk.verifyPhone("123456789123"));
        System.out.println("123456ddddd:"+RegexChk.verifyPhone("123456ddddd"));
        System.out.println("02345678912:"+RegexChk.verifyPhone("02345678912"));

        //验证电子邮箱
        System.out.println("验证电子邮箱:");
        System.out.println("?aaa?@..:"+RegexChk.verifyEmail("?aaa?@.."));
        System.out.println("user@.:"+RegexChk.verifyEmail("user@."));
        System.out.println("user@..:"+RegexChk.verifyEmail("user@.."));
        System.out.println("user@...:"+RegexChk.verifyEmail("user@..."));
        System.out.println("user@.ss.:"+RegexChk.verifyEmail("user@.ss."));
        System.out.println("us@.:"+RegexChk.verifyEmail("us@."));
        System.out.println("us@..:"+RegexChk.verifyEmail("us@.."));
        System.out.println("?aaa?@123.11.:"+RegexChk.verifyEmail("?aaa?@123.11."));

        //验证邮政编码
        System.out.println("验证邮政编码:");
        System.out.println("123456:"+RegexChk.verifyPostalCode("123456"));
        System.out.println("12345:"+RegexChk.verifyPostalCode("12345"));
        System.out.println("1234567:"+RegexChk.verifyPostalCode("1234567"));
        System.out.println("12a456:"+RegexChk.verifyPostalCode("12a456"));
        System.out.println("aaaaaa:"+RegexChk.verifyPostalCode("aaaaaa"));

        //验证身份证号码
        System.out.println("验证身份证号码:");
        System.out.println("123456789123456781:"+RegexChk.verifyIdCard("123456789123456781"));
        System.out.println("12345678912345678x:"+RegexChk.verifyIdCard("12345678912345678x"));
        System.out.println("12345678912345678a:"+RegexChk.verifyIdCard("12345678912345678a"));
        System.out.println("1234567891234567a1:"+RegexChk.verifyIdCard("1234567891234567a1"));
        System.out.println("123:"+RegexChk.verifyIdCard("123"));
        System.out.println("1234567891234567891:"+RegexChk.verifyIdCard("1234567891234567891"));



    }
}
