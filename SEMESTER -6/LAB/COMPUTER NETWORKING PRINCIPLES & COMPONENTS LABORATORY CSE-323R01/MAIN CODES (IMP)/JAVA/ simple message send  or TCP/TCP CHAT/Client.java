import java.net.*;
import java.io.*;

class Client {
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
                printstream.println(clientMessage);
                if (clientMessage.equalsIgnoreCase("bye")) {
                    break;
                }

                serverMessage = bufferreader.readLine();
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
}