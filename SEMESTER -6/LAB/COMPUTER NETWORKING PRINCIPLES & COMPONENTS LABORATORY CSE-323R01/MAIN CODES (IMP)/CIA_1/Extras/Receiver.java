import java.net.*;
import java.io.*;
import java.awt.*;

class Receiver extends Frame {
    TextArea ta;
    
    Receiver() {
        super("Receiver"); 
        setSize(300, 150); 
        setLayout(new FlowLayout());
        ta = new TextArea(5, 25); 
        add(ta); 
        setVisible(true);

        try {
            ServerSocket ss = new ServerSocket(2000);
            Socket s = ss.accept();
            BufferedReader br = new BufferedReader(new InputStreamReader(s.getInputStream()));
            String[] data = br.readLine().split(":");
            String msg = data[0]; int key = Integer.parseInt(data[1]);
            String dec = "";
            for (char c : msg.toCharArray()) dec += (char)(c - key);
            ta.setText("Decrypted: " + dec);
        }
        catch (Exception e) { System.out.println(e); }
    }

    public static void main(String[] args) { new Receiver(); }
}
