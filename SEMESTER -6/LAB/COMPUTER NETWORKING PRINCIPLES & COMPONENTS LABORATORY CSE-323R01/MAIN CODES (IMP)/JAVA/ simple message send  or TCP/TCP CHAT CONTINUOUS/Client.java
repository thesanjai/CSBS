import java.net.*;
import java.io.*;

class Client {
    public static void main(String ar[]) {
        try {
            Socket socket = new Socket("localhost", 2000);
            BufferedReader bufferreader = new BufferedReader(new InputStreamReader(socket.getInputStream()));
            PrintStream printstream = new PrintStream(socket.getOutputStream());
            BufferedReader clientInput = new BufferedReader(new InputStreamReader(System.in));

            // Thread for reading messages from the server
            Thread readThread = new Thread(() -> {
                try {
                    String serverMessage;
                    while (true) {
                        serverMessage = bufferreader.readLine();
                        if (serverMessage.equalsIgnoreCase("bye")) {
                            break;
                        }
                        System.out.println("Server: " + serverMessage);
                    }
                } catch (IOException e) {
                    System.out.println(e);
                }
            });

            // Thread for sending messages to the server
            Thread writeThread = new Thread(() -> {
                try {
                    String clientMessage;
                    while (true) {
                        System.out.print("Client: ");
                        clientMessage = clientInput.readLine();
                        printstream.println(clientMessage);
                        if (clientMessage.equalsIgnoreCase("bye")) {
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
        } catch (Exception e) {
            System.out.println(e);
        }
    }
}