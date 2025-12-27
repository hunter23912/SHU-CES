import com.sun.org.apache.bcel.internal.generic.NEW;
import com.sun.org.apache.xml.internal.security.Init;

import javax.swing.*;
import javax.swing.event.DocumentEvent;
import javax.swing.event.DocumentListener;
import javax.swing.text.BadLocationException;
import javax.swing.text.Document;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.concurrent.ConcurrentHashMap;

public class Problem_2 {
    public static void main(String[] args) {
        ShowMenu showMenu=new ShowMenu();
        showMenu.setTitle("对话框");
        showMenu.setBounds(500,100,800,400);


    }
}


class ShowMenu extends JFrame {
    JButton jButton;
    JTextArea jTextArea;
    ShowMenu(){
        init();
        setBounds(100,100,420,220);
        setVisible(true);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }

    public void init(){
        setLayout(new BorderLayout());
        jButton=new JButton("打开对话框");
        add(jButton,BorderLayout.NORTH);


        jTextArea=new JTextArea();
        add(jTextArea,BorderLayout.CENTER);

        ButtonListener buttonListener=new ButtonListener(jTextArea);
        jButton.addActionListener(buttonListener);
    }

}
class ButtonListener implements ActionListener{
    JTextArea jTextArea;
    ButtonListener(JTextArea jTextArea){
        this.jTextArea=jTextArea;
    }
    @Override
    public void actionPerformed(ActionEvent e) {
        JFrame jFrame =new JFrame("弹出窗口");
        jFrame.setBounds(600,500,400,400);
        jFrame.setLayout(new FlowLayout());
        JLabel jLabel=new JLabel("输入相关信息至主窗口");
        jFrame.add(jLabel);
        JTextField jTextField=new JTextField();
        TextListener textListener= new TextListener(jTextArea,jTextField);
        jTextField.addActionListener(textListener);
        jTextField.setColumns(25);
        jFrame.add(jTextField);
        jFrame.setVisible(true);

    }
}
class TextListener implements ActionListener {
    JTextArea jTextArea;
    JTextField jTextField;
    TextListener(JTextArea jTextArea,JTextField jTextField){
        this.jTextArea=jTextArea;
        this.jTextField=jTextField;
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        jTextArea.append(jTextField.getText());
        jTextField.setText("");
    }
}
