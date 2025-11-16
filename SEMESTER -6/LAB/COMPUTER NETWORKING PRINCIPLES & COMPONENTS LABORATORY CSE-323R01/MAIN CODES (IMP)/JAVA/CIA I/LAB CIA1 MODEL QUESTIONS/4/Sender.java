import java.io.*;
import java.net.*;

public class Sender {
    public static void main(String[] args) {
        String serverIP = "127.0.0.1"; // Change this to the Receiver's IP if on different machines
        int port = 5000;

        try (Socket socket = new Socket(serverIP, port);
             BufferedReader in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
             PrintWriter out = new PrintWriter(socket.getOutputStream(), true);
             BufferedReader userInput = new BufferedReader(new InputStreamReader(System.in))) {

            System.out.print("Enter encryption key (1-25): ");
            int key = Integer.parseInt(userInput.readLine());

            // Thread for receiving messages
            Thread receiveThread = new Thread(() -> {
                try {
                    while (true) {
                        String encryptedMsg = in.readLine();
                        if (encryptedMsg == null) break;
                        String decryptedMsg = CaesarCipher.decrypt(encryptedMsg, key);
                        System.out.println("\nReceiver: " + decryptedMsg);
                    }
                } catch (IOException e) {
                    e.printStackTrace();
                }
            });

            // Thread for sending messages
            Thread sendThread = new Thread(() -> {
                try {
                    while (true) {
                        System.out.print("You: ");
                        String msg = userInput.readLine();
                        String encryptedMsg = CaesarCipher.encrypt(msg, key);
                        out.println(encryptedMsg);
                    }
                } catch (IOException e) {
                    e.printStackTrace();
                }
            });

            receiveThread.start();
            sendThread.start();

            receiveThread.join();
            sendThread.join();

        } catch (IOException | InterruptedException e) {
            e.printStackTrace();
        }
    }
}
