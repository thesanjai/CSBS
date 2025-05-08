import java.net.*;
import java.io.*;

class Server {
    public static void main(String[] args) {
        try {
            ServerSocket serversocket = new ServerSocket(2000);
            System.out.println("\n Waiting...");
            Socket socket = serversocket.accept();
            System.out.println("\n Connection Established");

            BufferedReader bufferreader = new BufferedReader(new InputStreamReader(socket.getInputStream()));
            PrintStream printstream = new PrintStream(socket.getOutputStream());

            // Receive filename from client
            String filename = bufferreader.readLine();
            System.out.println("Client requested file: " + filename);

            File file = new File(filename);
            if (file.exists()) {
                FileInputStream fis = new FileInputStream(file);
                byte[] buffer = new byte[4096];
                int bytesRead;
                while ((bytesRead = fis.read(buffer)) != -1) {
                    printstream.write(buffer, 0, bytesRead);
                }
                fis.close();
            } else {
                printstream.println("File not found!");
            }

            socket.close();
            serversocket.close();

        } catch (Exception e) {
            System.out.println(e);
        }
    }
}