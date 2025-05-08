import java.io.*;
import java.net.*;
import java.util.Scanner;
import java.util.Base64;

public class DirectoryClient {
    private static final String SECRET_KEY = "MySecretKey123";

    public static void main(String[] args) {
        String serverIP = "localhost"; 
        int port = 5000;

        try (
            Socket socket = new Socket(serverIP, port);
            PrintWriter out = new PrintWriter(socket.getOutputStream(), true);
            BufferedReader in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
            Scanner scanner = new Scanner(System.in)
        ) {
            System.out.print("Enter the directory path to list: ");
            String directoryPath = scanner.nextLine();
            String request = "list " + directoryPath;
            
            out.println(encrypt(request));

            String encryptedResponse = in.readLine();
            if (encryptedResponse != null) {
                String response = decrypt(encryptedResponse);
                System.out.println("Server response:");
                System.out.println(response);
            }

        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    private static String encrypt(String data) {
        StringBuilder encrypted = new StringBuilder();
        for (int i = 0; i < data.length(); i++) {
            encrypted.append((char) (data.charAt(i) ^ SECRET_KEY.charAt(i % SECRET_KEY.length())));
        }
        return Base64.getEncoder().encodeToString(encrypted.toString().getBytes());
    }

    private static String decrypt(String encryptedData) {
        byte[] decodedBytes = Base64.getDecoder().decode(encryptedData);
        String decoded = new String(decodedBytes);
        StringBuilder decrypted = new StringBuilder();
        for (int i = 0; i < decoded.length(); i++) {
            decrypted.append((char) (decoded.charAt(i) ^ SECRET_KEY.charAt(i % SECRET_KEY.length())));
        }
        return decrypted.toString();
    }
}
