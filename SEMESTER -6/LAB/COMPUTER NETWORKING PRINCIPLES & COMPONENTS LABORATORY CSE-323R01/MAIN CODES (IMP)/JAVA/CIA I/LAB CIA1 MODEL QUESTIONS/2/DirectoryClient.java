import java.io.*;
import java.net.*;
import java.io.File;

public class DirectoryClient {
    public static void main(String[] args) {
        String serverIP = "localhost"; // Replace with actual server IP
        int port = 5000;

        try (Socket socket = new Socket(serverIP, port);
             BufferedReader in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
             PrintWriter out = new PrintWriter(socket.getOutputStream(), true)) {

            // Receive directory request from the server
            String request = in.readLine();
            System.out.println("Server requested: " + request);

            if (request.startsWith("list ")) {
                String dirPath = request.substring(5); // Extract path
                File directory = new File(dirPath);

                if (directory.exists() && directory.isDirectory()) {
                    StringBuilder response = new StringBuilder("Files and Directories in " + dirPath + ":\n");

                    String[] fileList = directory.list();
                    if (fileList != null) {
                        for (String file : fileList) {
                            response.append(file).append("\n");
                        }
                    }
                    out.println(response.toString()); // Send directory list
                } else {
                    out.println("Error: Directory does not exist - " + dirPath);
                }
            } else {
                out.println("Invalid request from server.");
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
