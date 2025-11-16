import java.io.*;
import java.net.*;

public class Receiver {
    public static void main(String[] args) {
        int port = 5000;
        try (ServerSocket serverSocket = new ServerSocket(port)) {
            System.out.println("Waiting for connection...");

            Socket socket = serverSocket.accept();
            System.out.println("Connected to Sender!");

            BufferedReader in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
            PrintWriter out = new PrintWriter(socket.getOutputStream(), true);
            BufferedReader userInput = new BufferedReader(new InputStreamReader(System.in));

            System.out.print("Enter encryption key (1-25): ");
            int key = Integer.parseInt(userInput.readLine());

            // Thread for receiving messages
            Thread receiveThread = new Thread(() -> {
                try {
                    while (true) {
                        String encryptedMsg = in.readLine();
                        if (encryptedMsg == null) break;
                        String decryptedMsg = CaesarCipher.decrypt(encryptedMsg, key);
                        System.out.println("\nSender: " + decryptedMsg);
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

            socket.close();
        } catch (IOException | InterruptedException e) {
            e.printStackTrace();
        }
    }
}
