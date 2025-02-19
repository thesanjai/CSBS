import java.io.*;
import java.net.*;

public class DirectoryServer {
    public static void main(String[] args) {
        int port = 5000; // Use a specific port
        try (ServerSocket serverSocket = new ServerSocket(port)) {
            System.out.println("Server started on port " + port);
            while (true) {
                Socket clientSocket = serverSocket.accept();
                System.out.println("Connected to client: " + clientSocket.getInetAddress());

                BufferedReader in = new BufferedReader(new InputStreamReader(clientSocket.getInputStream()));
                PrintWriter out = new PrintWriter(clientSocket.getOutputStream(), true);

                // Read the directory name from the client
                String dirName = in.readLine();
                File directory = new File(dirName);

                // Create the directory
                if (directory.mkdir()) {
                    out.println("Successfully Created: " + dirName);
                } else {
                    out.println("Failed to Create: " + dirName);
                }

                clientSocket.close();
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
