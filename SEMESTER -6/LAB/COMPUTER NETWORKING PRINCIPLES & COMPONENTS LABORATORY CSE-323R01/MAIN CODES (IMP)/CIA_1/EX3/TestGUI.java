// code for GUI with encrypt and decrypt:

import java.awt.*;
import java.awt.event.*;
import java.net.*;
import java.io.*;
class Test1 implements ActionListener
{
    Frame f;
    TextField tf;
    TextArea ta;    
    Button b,b1;
    PrintStream pr;
    ServerSocket ss;
    Socket s;
    Test1()
    {    
        f=new Frame("Chat App.");
        f.setSize(400,400);    
        tf=new TextField(20);
        ta=new TextArea(20,20);
        b=new Button("Send");
        b1=new Button("Cancel");
        f.setLayout(new FlowLayout());
        f.add(new Label("Enter Message:"));
        f.add(tf);
        f.add(ta);
        f.add(b);
        f.add(b1);
        b.addActionListener(this);
        b1.addActionListener(this);
        f.setVisible(true);
        try{
            ss=new ServerSocket(2000);    
            s=ss.accept();
            pr=new PrintStream(s.getOutputStream());
        }
        catch(Exception e)
        {}

    }
    public void actionPerformed(ActionEvent ae)
    {
        if(ae.getSource()==b)
        {
            String s1=tf.getText();
            char c[]=s1.toCharArray();
            for(int i=0;i<c.length;i++)
            {
                c[i]=(char)(c[i]-5);
            }
            String a=new String(c);
            pr.println(a);        
            System.out.println(a);

        }
        else if(ae.getSource()==b1)
        {
            System.out.println("cancel");
        }

    }
}    

class TestGUI
{
    public static void main(String ar[])
    {    
        Test1 t1=new Test1();
    }
}
