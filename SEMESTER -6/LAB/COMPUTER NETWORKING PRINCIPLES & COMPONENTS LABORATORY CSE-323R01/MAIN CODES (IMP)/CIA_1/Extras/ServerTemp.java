import java.io.*;
import java.net.*;

public class ServerTemp {
    public static void main(String[] args) throws IOException {
        ServerSocket ss = new ServerSocket(2000);
        System.out.println("Waiting for client...");
        Socket s = ss.accept();
        PrintStream ps = new PrintStream(s.getOutputStream());
        BufferedReader br = new BufferedReader(new InputStreamReader(s.getInputStream()));

        String dirPath = "list C:\\Users"; // Change as needed
        ps.println(dirPath); // Send command

        System.out.println("Client Response: " + br.readLine());
        ss.close();
    }
}
