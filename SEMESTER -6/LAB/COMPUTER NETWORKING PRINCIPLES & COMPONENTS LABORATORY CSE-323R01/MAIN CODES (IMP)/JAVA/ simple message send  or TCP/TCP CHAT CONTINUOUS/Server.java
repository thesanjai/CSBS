import java.net.*;
import java.io.*;

public class Server {
    public static void main(String ar[]) {
        try {
            ServerSocket serversocket = new ServerSocket(2000);
            System.out.println("\n Waiting...");
            Socket socket = serversocket.accept();
            System.out.println("\n Connection Established");

            PrintStream printstream = new PrintStream(socket.getOutputStream());
            BufferedReader bufferreader = new BufferedReader(new InputStreamReader(socket.getInputStream()));
            BufferedReader serverInput = new BufferedReader(new InputStreamReader(System.in));

            // Thread for reading messages from the client
            Thread readThread = new Thread(() -> {
                try {
                    String clientMessage;
                    while (true) {
                        clientMessage = bufferreader.readLine();
                        if (clientMessage.equalsIgnoreCase("bye")) {
                            break;
                        }
                        System.out.println("Client: " + clientMessage);
                    }
                } catch (IOException e) {
                    System.out.println(e);
                }
            });

            // Thread for sending messages to the client
            Thread writeThread = new Thread(() -> {
                try {
                    String serverMessage;
                    while (true) {
                        System.out.print("Server: ");
                        serverMessage = serverInput.readLine();
                        printstream.println(serverMessage);
                        if (serverMessage.equalsIgnoreCase("bye")) {
                            break;
                        }
                    }
                } catch (IOException e) {
                    System.out.println(e);
                }
            });

            readThread.start();
            writeThread.start();

            readThread.join();
            writeThread.join();

            socket.close();
            serversocket.close();
        } catch (Exception e) {
            System.out.println(e);
        }
    }
}