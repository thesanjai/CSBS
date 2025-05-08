import java.io.*;
import java.net.*;

public class Receiver {
    public static void main(String[] args) {
        int port = 5000;

        try (ServerSocket serverSocket = new ServerSocket(port)) {
            System.out.println("Waiting for connection...");

            while (true) {
                Socket socket = serverSocket.accept();
                System.out.println("Connected to Sender");

                BufferedReader in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
                PrintWriter out = new PrintWriter(socket.getOutputStream(), true);

                // Receive encrypted message and key
                String encryptedMessage = in.readLine();
                int key = Integer.parseInt(in.readLine());

                System.out.println("Received Encrypted Message: " + encryptedMessage);
                System.out.println("Key: " + key);

                // Decrypt message
                String decryptedMessage = CaesarCipher.decrypt(encryptedMessage, key);
                System.out.println("Decrypted Message: " + decryptedMessage);

                // Send confirmation to Sender
                out.println("Message received and decrypted successfully!");

                socket.close();
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
