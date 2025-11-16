import java.io.*;
import java.net.*;
import java.util.Scanner;

public class DirectoryClient {
    public static void main(String[] args) {
        String server1 = "localhost"; // Replace with Machine 1 IP
        // String server2 = "192.168.1.102"; // Replace with Machine 2 IP
        int port = 5000;

        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter the name of the directory you want to create: ");
        String dirName = scanner.nextLine();
        scanner.close();
        sendDirectoryRequest(server1, port, dirName);
        // sendDirectoryRequest(server2, port, "Machine2_Dir");
    }

    private static void sendDirectoryRequest(String serverIP, int port, String dirName) {
        try (Socket socket = new Socket(serverIP, port);
             PrintWriter out = new PrintWriter(socket.getOutputStream(), true);
             BufferedReader in = new BufferedReader(new InputStreamReader(socket.getInputStream()))) {

            // Send the directory name
            out.println(dirName);

            // Receive confirmation
            String response = in.readLine();
            System.out.println("Response from " + serverIP + ": " + response);

        } catch (IOException e) {
            System.err.println("Error connecting to " + serverIP);
            e.printStackTrace();
        }
    }
}
