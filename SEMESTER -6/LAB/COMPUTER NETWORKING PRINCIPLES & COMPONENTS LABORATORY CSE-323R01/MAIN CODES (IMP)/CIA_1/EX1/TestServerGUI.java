import java.awt.*;
import java.awt.event.*;
import java.net.*;
import java.io.*;

class TestServerGUI implements ActionListener {
    Frame f;
    TextField tf;
    TextArea ta;
    Button sendBtn, exitBtn;
    ServerSocket ss;
    Socket s;
    BufferedReader br;
    PrintStream pr;

    TestServerGUI() {
        f = new Frame("Server Chat");
        f.setSize(400, 400);
        f.setLayout(new FlowLayout());

        ta = new TextArea(15, 30);
        tf = new TextField(25);
        sendBtn = new Button("Send");
        exitBtn = new Button("Exit");

        f.add(ta);
        f.add(tf);
        f.add(sendBtn);
        f.add(exitBtn);

        sendBtn.addActionListener(this);
        exitBtn.addActionListener(this);

        f.setVisible(true);

        try {
            ss = new ServerSocket(2000);
            ta.append("Waiting for Client...\n");
            s = ss.accept();
            ta.append("Client Connected!\n");

            br = new BufferedReader(new InputStreamReader(s.getInputStream()));
            pr = new PrintStream(s.getOutputStream());
            try {
                String message;
                while ((message = br.readLine()) != null) {
                    if (message.equalsIgnoreCase("exit")) {
                        ta.append("Client disconnected.\n");
                        break;
                    }
                    ta.append("Client: " + message + "\n");
                }
                ss.close();
            } catch (Exception e) {
                ta.append("Error: " + e.getMessage() + "\n");
            }
        } catch (Exception e) {
            ta.append("Error: " + e.getMessage() + "\n");
        }
    }

    public void actionPerformed(ActionEvent ae) {
        if (ae.getSource() == sendBtn) {
            String message = tf.getText();
            pr.println(message);
            ta.append("Server: " + message + "\n");
            tf.setText("");

            if (message.equalsIgnoreCase("exit")) {
                ta.append("Server ended the chat.\n");
                System.exit(0);
            }
        } else if (ae.getSource() == exitBtn) {
            pr.println("exit");
            ta.append("Chat closed.\n");
            System.exit(0);
        }
    }

    public static void main(String[] args) {
        new TestServerGUI();
    }
}
