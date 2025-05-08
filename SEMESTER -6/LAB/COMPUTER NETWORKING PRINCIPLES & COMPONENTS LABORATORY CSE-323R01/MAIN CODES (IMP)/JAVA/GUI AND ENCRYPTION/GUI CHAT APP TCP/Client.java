import java.net.*;
import java.io.*;
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

class Client {
    private static final int KEY = 3; // Simple key for Caesar cipher
    private static JTextArea chatArea;
    private static JTextField inputField;
    private static PrintStream printstream;

    public static void main(String ar[]) {
        JFrame frame = new JFrame("Client");
        chatArea = new JTextArea();
        chatArea.setEditable(false);
        inputField = new JTextField();
        JButton sendButton = new JButton("Send");
        JButton closeButton = new JButton("Close");
        
        sendButton.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                String message = inputField.getText();
                printstream.println(encrypt(message, KEY));
                chatArea.append("Client: " + message + "\n");
                inputField.setText("");
            }
        });

        closeButton.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                System.exit(0);
            }
        });

        JPanel panel = new JPanel(new BorderLayout());
        panel.add(new JLabel("Enter text:"), BorderLayout.WEST);
        panel.add(inputField, BorderLayout.CENTER);
        panel.add(sendButton, BorderLayout.EAST);

        frame.setLayout(new BorderLayout());
        frame.add(new JScrollPane(chatArea), BorderLayout.CENTER);
        frame.add(panel, BorderLayout.SOUTH);
        frame.add(closeButton, BorderLayout.NORTH);
        frame.setSize(400, 400);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setVisible(true);

        try {
            Socket socket = new Socket("localhost", 2000);
            printstream = new PrintStream(socket.getOutputStream());
            BufferedReader bufferreader = new BufferedReader(new InputStreamReader(socket.getInputStream()));

            // Thread for reading messages from the server
            Thread readThread = new Thread(() -> {
                try {
                    String serverMessage;
                    while (true) {
                        serverMessage = decrypt(bufferreader.readLine(), KEY);
                        if (serverMessage.equalsIgnoreCase("bye")) {
                            break;
                        }
                        chatArea.append("Server: " + serverMessage + "\n");
                    }
                } catch (IOException e) {
                    chatArea.append("Error: " + e.getMessage() + "\n");
                }
            });

            readThread.start();

        } catch (Exception e) {
            chatArea.append("Error: " + e.getMessage() + "\n");
        }
    }

    private static String encrypt(String str, int key) {
        StringBuilder encrypted = new StringBuilder();
        for (char c : str.toCharArray()) {
            encrypted.append((char) (c + key));
        }
        return encrypted.toString();
    }

    private static String decrypt(String str, int key) {
        StringBuilder decrypted = new StringBuilder();
        for (char c : str.toCharArray()) {
            decrypted.append((char) (c - key));
        }
        return decrypted.toString();
    }
}