import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class Problem_1 {



   public static void main(String args[]) {
      WindowMouse win=new WindowMouse();
      win.setTitle("处理鼠标事件"); 
      win.setBounds(500,200,800,800);
   }
}
class WindowMouse extends JFrame {
   JTextField text;
   JButton button;
   JTextArea textArea;
   MousePolice police;

   FocusEventDemo focus;

   WindowMouse() {
      init();
      setBounds(100,100,420,220);
      setVisible(true);
      setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
   }

   void init() {
      setLayout(new FlowLayout());
      text=new JTextField(8);
      textArea=new JTextArea(15,30);

      police=new MousePolice();
      police.setJTextArea(textArea);
      focus=new FocusEventDemo(text,textArea);

      text.addMouseListener(police);
      text.addMouseMotionListener(police);
      text.addFocusListener(focus);

      button=new JButton("按钮");
      button.addMouseListener(police);
      button.addMouseMotionListener(police);

      addMouseListener(police);
      addMouseMotionListener(police);

      add(button);
      add(text);
      add(new JScrollPane(textArea));
   }
}
class MousePolice implements MouseListener, MouseMotionListener {
   JTextArea area;

   public void setJTextArea(JTextArea area) {
      this.area=area;
   }

   public void mousePressed(MouseEvent e) {
      area.append("\n鼠标按下,位置:"+"("+e.getX()+","+e.getY()+")");
   }

   public void mouseReleased(MouseEvent e) {
      area.append("\n鼠标释放,位置:"+"("+e.getX()+","+e.getY()+")");
   }

   public void mouseEntered(MouseEvent e)  {
      if(e.getSource() instanceof JButton)
         area.append("\n鼠标进入按纽,位置:"+"("+e.getX()+","+e.getY()+")");
      if(e.getSource() instanceof JTextField)
         area.append("\n鼠标进入文本框,位置:"+"("+e.getX()+","+e.getY()+")");
      if(e.getSource() instanceof JFrame)
         area.append("\n鼠标进入窗口,位置:"+"("+e.getX()+","+e.getY()+")");
   }

   public void mouseExited(MouseEvent e) {
      area.append("\n鼠标退出,位置:"+"("+e.getX()+","+e.getY()+")");
   }

   public void mouseClicked(MouseEvent e) {
      if(e.getClickCount()>=2)
         area.setText("\n鼠标连击，位置:"+"("+e.getX()+","+e.getY()+")");
   }

   public void mouseDragged(MouseEvent e) {
      if(e.getSource() instanceof JButton) {
         area.append("\n鼠标在按钮中拖动,位置:" + "(" + e.getX() + "," + e.getY() + ")");
      }else if(e.getSource() instanceof JTextField){
         area.append("\n鼠标在文本框中拖动,位置:" + "(" + e.getX() + "," + e.getY() + ")");
      }else if(e.getSource() instanceof JFrame){
         area.append("\n鼠标在窗口中拖动,位置:" + "(" + e.getX() + "," + e.getY() + ")");
      }
   }

   public void mouseMoved(MouseEvent e) {
      if(e.getSource() instanceof JButton) {
         area.append("\n鼠标在按钮中移动,位置:" + "(" + e.getX() + "," + e.getY() + ")");
      }else if(e.getSource() instanceof JTextField){
         area.append("\n鼠标在文本框中移动,位置:" + "(" + e.getX() + "," + e.getY() + ")");
      }else if(e.getSource() instanceof JFrame){
         area.append("\n鼠标在窗口中移动,位置:" + "(" + e.getX() + "," + e.getY() + ")");
      }
   }
}
class FocusEventDemo extends JFrame implements FocusListener {
   private JTextField tblock;
   private JTextArea tarea;

   @Override
   public void focusGained(FocusEvent e) {
      JComponent component=(JComponent)e.getSource();
      if(component==tblock) {
         tblock.setBackground(Color.white);
         tarea.setText("文本框获得了焦点");
      }else if(component==tarea){
         tarea.setText("文本框获得了焦点");
         tarea.setBackground(Color.white);
      }
   }

   @Override
   public void focusLost(FocusEvent e) {
      JComponent component=(JComponent)e.getSource();
      if(component==tblock) {
         tblock.setText("");
         tblock.setBackground(Color.RED);
         tarea.setText("文本框失去了了焦点");
      }else if(component==tarea){
         tarea.setText("");
         tarea.setBackground(Color.RED);
      }
   }
   FocusEventDemo(JTextField tblock, JTextArea tarea){
      this.tblock=tblock;
      this.tarea=tarea;
   }
}