import java.net.*;
import java.io.*;

class Client {
    private static final int KEY = 3; 

    public static void main(String ar[]) {
        try {
            Socket socket = new Socket("localhost", 2000);
            BufferedReader bufferreader = new BufferedReader(new InputStreamReader(socket.getInputStream()));
            PrintStream printstream = new PrintStream(socket.getOutputStream());
            BufferedReader clientInput = new BufferedReader(new InputStreamReader(System.in));

            String serverMessage, clientMessage;
            while (true) {
                System.out.print("Client: ");
                clientMessage = clientInput.readLine();
                printstream.println(encrypt(clientMessage, KEY));
                if (clientMessage.equalsIgnoreCase("bye")) {
                    break;
                }

                serverMessage = decrypt(bufferreader.readLine(), KEY);
                if (serverMessage.equalsIgnoreCase("bye")) {
                    break;
                }
                System.out.println("Server: " + serverMessage);
            }

            socket.close();
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