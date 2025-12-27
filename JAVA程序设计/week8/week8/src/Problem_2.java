import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

//异常处理
class numberException  extends Exception{
    String e;
    public numberException(){
    }
    public numberException(String message){
        this.e=message;
    }
    public String jTextareas(){
        return e;

    }
}

class Calculation extends JFrame implements ActionListener {
    private JPanel north, south;
    private JTextArea jTextarea;
    StringBuffer leftNumber;
    StringBuffer rightNumber;



    char op ='~'; //初始运算符为~
    double  A;
    double  B;
    private String[] text2 = {
            "0", "1", "2", "3",
            "4", "5", "6", "7",
            "8", "9", "+", "-",
            "*","/", "C", "="};
    private JButton[] munButton = new JButton[text2.length];

    public void init() {//初始化
        north = new JPanel();
        south = new JPanel();
        jTextarea = new JTextArea();
        rightNumber=new StringBuffer();
        leftNumber=new StringBuffer();

        north.setSize(500, 100);
        jTextarea.setPreferredSize(new Dimension(500, 145));
        north.add(jTextarea);
        north.setBackground(Color.white);
        south.setBackground(Color.white);
        south.setLayout(new GridLayout(4, 4, 2, 3));
        south.setPreferredSize(new Dimension(450, 300));
        this.setTitle("计算器");
        this.setLayout(new BorderLayout());
        this.add(north, BorderLayout.NORTH);
        this.add(south, BorderLayout.SOUTH);
        //添加数字按键
        for (int i = 0; i < text2.length; i++) {
            munButton[i] = new JButton(text2[i]);
            south.add(munButton[i]);
        }
        //添加按钮监听器
        for (int i = 0; i < munButton.length; i++)
            munButton[i].addActionListener(this);

        setFont(new Font("仿宋", Font.BOLD, 100));
        setLocation(600,200);
        setSize(550,500);
        this.setVisible(true);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

    }
    //除法异常处理
    public double division(double x,double y)throws numberException{
        if(y==0){
            throw new numberException("除数不能为0！");
        }
        else{
            return x/y;
        }
    }
    @Override
    public void actionPerformed(ActionEvent e) {
        try {
            String act=e.getActionCommand();
            char a=act.charAt(0);
            if (a=='0' ||a=='1' || a=='2' ||a=='3'||a=='4'||a=='5'||a=='6'||a=='7'||a=='8'||a=='9') {
                if(op=='~'){
                    leftNumber.append(a);
                    jTextarea.setText(String.valueOf(leftNumber));
                }else {
                    rightNumber.append(a);
                    jTextarea.setText(String.valueOf(leftNumber)+op+String.valueOf(rightNumber));
                }

            } else if(a=='+'||a=='-'||a=='/'||a=='*'){
                op=a;
                jTextarea.setText(String.valueOf(leftNumber)+op);

            } else if(a=='='){
                if(rightNumber.length()==0||leftNumber.length()==0){
                    jTextarea.setText("请输入正确的代数式！ ");
                    return;
                }
                A = Double.parseDouble(String.valueOf(leftNumber));
                B = Double.parseDouble(String.valueOf(rightNumber));
                double j;
                int lenA=leftNumber.length();
                int lenB=rightNumber.length();
                //加法运算
                if (op == '+') {
                    j = A + B;
                    jTextarea.setText(Double.toString(j));

                    leftNumber.delete(0,lenA);
                    rightNumber.delete(0,lenB);
                    leftNumber.append(j);

                } else if (op == '-') {
                    j = A - B;
                    jTextarea.setText(Double.toString(j));

                    leftNumber.delete(0,lenA);
                    rightNumber.delete(0,lenB);
                    leftNumber.append(j);
                } else if (op == '*') {
                    j = A * B;
                    jTextarea.setText(Double.toString(j));

                    leftNumber.delete(0,lenA);
                    rightNumber.delete(0,lenB);
                    leftNumber.append(j);
                } else if (op == '/') {
                    try{
                        j= division(A, B);
                        jTextarea.setText(Double.toString(j));

                        leftNumber.delete(0,lenA);
                        rightNumber.delete(0,lenB);
                        leftNumber.append(j);
                    }catch(numberException u){
                        jTextarea.setText(u.jTextareas());
                    }
                }else if(op == '~'){
                    jTextarea.setText("请输入正确的代数式！ ");
                }
            } else if (a=='C') {
                jTextarea.setText(" ");
                op='~';
                int lenA=leftNumber.length();
                int lenB=rightNumber.length();

                leftNumber.delete(0,lenA);
                rightNumber.delete(0,lenB);

            }
        }catch(ArithmeticException m){
            System.out.println("除数不能为0");
        }
    }

    public static void main(String[] args) {
        Calculation c=new Calculation();
        c.init();
    }
}