import java.net.*;
import java.io.*;

public class Server {
    private static final int KEY = 3; // Simple key for Caesar cipher

    public static void main(String ar[]) {
        try {
            ServerSocket serversocket = new ServerSocket(2000);
            System.out.println("\n Waiting...");
            Socket socket = serversocket.accept();
            System.out.println("\n Connection Established");

            PrintStream printstream = new PrintStream(socket.getOutputStream());
            BufferedReader bufferreader = new BufferedReader(new InputStreamReader(socket.getInputStream()));
            BufferedReader serverInput = new BufferedReader(new InputStreamReader(System.in));

            String clientMessage, serverMessage;
            while (true) {
                clientMessage = decrypt(bufferreader.readLine(), KEY);
                if (clientMessage.equalsIgnoreCase("bye")) {
                    break;
                }
                System.out.println("Client: " + clientMessage);

                System.out.print("Server: ");
                serverMessage = serverInput.readLine();
                printstream.println(encrypt(serverMessage, KEY));
                if (serverMessage.equalsIgnoreCase("bye")) {
                    break;
                }
            }

            socket.close();
            serversocket.close();
        } catch (Exception e) {
            System.out.println(e);
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