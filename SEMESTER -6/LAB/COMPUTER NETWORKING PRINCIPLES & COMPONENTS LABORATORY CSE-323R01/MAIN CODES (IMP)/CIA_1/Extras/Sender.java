import java.net.*;
import java.io.*;
import java.awt.*;
import java.awt.event.*;

class Sender extends Frame implements ActionListener {
    TextField tf; 
    Button send;
    Socket s; 
    PrintStream pr;
    
    Sender() {
        super("Sender"); 
        setSize(300, 150); 
        setLayout(new FlowLayout());
        tf = new TextField(20); 
        send = new Button("Send");
        add(new Label("Message:")); 
        add(tf); 
        add(send);
        send.addActionListener(this); 
        setVisible(true);

        try { s = new Socket("localhost", 2000); 
        pr = new PrintStream(s.getOutputStream()); }
        catch (Exception e) { System.out.println(e); }
    }

    public void actionPerformed(ActionEvent e) {
        String msg = tf.getText(), enc = "";
        int key = 2;
        for (char c : msg.toCharArray()) 
        {
            enc += (char)(c + key);
        }
        pr.println(enc + ":" + key);
    }

    public static void main(String[] args) { new Sender(); }
}
