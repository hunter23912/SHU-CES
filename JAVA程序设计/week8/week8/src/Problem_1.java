import com.oracle.xmlns.internal.webservices.jaxws_databinding.JavaWsdlMappingType;
import com.sun.org.apache.xml.internal.security.Init;

import javax.swing.*;
import java.awt.event.InputEvent;
import java.awt.event.KeyEvent;

public class Problem_1 extends JFrame{
    JMenuBar jMenuBar;
    JMenu menu,submenu;
    JMenuItem createFile,openFile,closeFile,saveFile,otherSaveFile,exit;
    JCheckBox javaFile,txtFile;
    JRadioButton read,write;
    public void init(){
        setTitle("典型的菜单界面");
        jMenuBar=new JMenuBar();
        menu=new JMenu("文件");
        submenu=new JMenu("文件格式");
        createFile=new JMenuItem("新建文件");
        createFile.setAccelerator(KeyStroke.getKeyStroke(KeyEvent.VK_M, InputEvent.CTRL_MASK));
        openFile=new JMenuItem("打开文件");
        openFile.setAccelerator(KeyStroke.getKeyStroke(KeyEvent.VK_O, InputEvent.CTRL_MASK));
        closeFile=new JMenuItem("关闭文件");
        closeFile.setAccelerator(KeyStroke.getKeyStroke(KeyEvent.VK_C, InputEvent.CTRL_MASK));
        saveFile=new JMenuItem("保存文件");
        saveFile.setAccelerator(KeyStroke.getKeyStroke(KeyEvent.VK_S, InputEvent.CTRL_MASK));
        otherSaveFile=new JMenuItem("文件另存为");
        exit=new JMenuItem("退出");
        exit.setAccelerator(KeyStroke.getKeyStroke(KeyEvent.VK_E, InputEvent.CTRL_MASK));
        javaFile=new JCheckBox("JAVA文件");
        txtFile=new JCheckBox("TXT文件");
        read=new JRadioButton("只读");
        write=new JRadioButton("只写");

        //拼接
        submenu.add(javaFile);
        submenu.add(txtFile);
        submenu.addSeparator();
        submenu.add(read);
        submenu.add(write);

        menu.add(createFile);
        menu.add(openFile);
        menu.add(closeFile);
        menu.addSeparator();
        menu.add(submenu);
        menu.add(saveFile);
        menu.add(otherSaveFile);
        menu.addSeparator();
        menu.add(exit);

        jMenuBar.add(menu);

        setJMenuBar(jMenuBar);
        setLocation(500,500);
        setSize(500,500);
        setVisible(true);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

    }
    public static void main(String[] args) {
        Problem_1 test=new Problem_1();
        test.init();






    }

}
