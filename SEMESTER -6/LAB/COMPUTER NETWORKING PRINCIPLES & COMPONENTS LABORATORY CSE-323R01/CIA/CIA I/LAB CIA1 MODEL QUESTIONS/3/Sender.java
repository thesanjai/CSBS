import java.io.*;
import java.net.*;
import java.util.Scanner;

public class Sender {
    public static void main(String[] args) {
        String serverIP = "localhost"; // Change to receiver's IP if needed
        int port = 5000;

        try (Socket socket = new Socket(serverIP, port);
             PrintWriter out = new PrintWriter(socket.getOutputStream(), true);
             BufferedReader in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
             Scanner scanner = new Scanner(System.in)) {

            // Get message and key from user
            System.out.print("Enter message to encrypt: ");
            String message = scanner.nextLine();
            System.out.print("Enter encryption key (1-25): ");
            int key = scanner.nextInt();

            // Encrypt message
            String encryptedMessage = CaesarCipher.encrypt(message, key);
            System.out.println("Encrypted Message: " + encryptedMessage);

            // Send encrypted message and key
            out.println(encryptedMessage);
            out.println(key);

            // Receive confirmation from Receiver
            String response = in.readLine();
            System.out.println("Receiver: " + response);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
