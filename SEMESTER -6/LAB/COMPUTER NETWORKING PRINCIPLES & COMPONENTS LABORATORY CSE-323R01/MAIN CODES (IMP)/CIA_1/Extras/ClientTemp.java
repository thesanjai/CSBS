import java.io.*;
import java.net.*;

public class ClientTemp {
    public static void main(String[] args) throws IOException {
        Socket s = new Socket("192.168.1.116", 2000); // Change to your server IP
        BufferedReader br = new BufferedReader(new InputStreamReader(s.getInputStream()));
        PrintStream ps = new PrintStream(s.getOutputStream());

        String command = br.readLine(); // Read directory request
        if (command.startsWith("list ")) {
            File dir = new File(command.substring(5));
            if (dir.exists() && dir.isDirectory()) {
                String[] files = dir.list();
                ps.println(files != null ? String.join(", ", files) : "No files found.");
            } else {
                ps.println("Error: Directory not found.");
            }
        }
        s.close();
    }
}
