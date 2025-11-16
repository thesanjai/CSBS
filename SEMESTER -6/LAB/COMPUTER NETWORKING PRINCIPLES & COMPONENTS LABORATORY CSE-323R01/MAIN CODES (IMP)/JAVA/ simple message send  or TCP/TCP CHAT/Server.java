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

            String clientMessage, serverMessage;
            while (true) {
                clientMessage = bufferreader.readLine();
                if (clientMessage.equalsIgnoreCase("bye")) {
                    break;
                }
                System.out.println("Client: " + clientMessage);

                System.out.print("Server: ");
                serverMessage = serverInput.readLine();
                printstream.println(serverMessage);
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
}