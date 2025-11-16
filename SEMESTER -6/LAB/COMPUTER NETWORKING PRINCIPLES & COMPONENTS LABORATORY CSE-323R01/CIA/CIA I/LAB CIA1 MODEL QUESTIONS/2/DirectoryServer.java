import java.io.*;
import java.net.*;
import java.util.Scanner;

public class DirectoryServer {
    public static void main(String[] args) {
        int port = 5000;

        try (ServerSocket serverSocket = new ServerSocket(port)) {
            System.out.println("Server started. Waiting for client...");

            while (true) {
                Socket clientSocket = serverSocket.accept();
                System.out.println("Connected to client: " + clientSocket.getInetAddress());

                PrintWriter out = new PrintWriter(clientSocket.getOutputStream(), true);
                BufferedReader in = new BufferedReader(new InputStreamReader(clientSocket.getInputStream()));
                // Get directory input from the user
                Scanner scanner = new Scanner(System.in);
                System.out.print("Enter the directory path to list: ");
                String directoryPath = scanner.nextLine();
                scanner.close();
                // Request a directory listing from the client
                String request = "list " + directoryPath;
                out.println(request);

                // Receive and print the directory listing or error message
                String response;
                while ((response = in.readLine()) != null) {
                    System.out.println(response);
                }

                clientSocket.close();
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
