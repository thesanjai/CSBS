// TCP Client - making directories
import java.io.*;
import java.net.*;

public class Client {
    public static void main(String[] args) throws IOException {
        String[] ips = {"192.168.1.116","192.168.1.117"}; // Change to your server IPs
        String[] dirNames = {"Server1_Dir", "Server2_Dir"};

        for (int i = 0; i < ips.length; i++) {
            try (Socket s = new Socket(ips[i], 2000);
                 PrintStream ps = new PrintStream(s.getOutputStream());
                 BufferedReader br = new BufferedReader(new InputStreamReader(s.getInputStream()))) 
                 {
                
                ps.println(dirNames[i]); 
                System.out.println("Server " + (i+1) + ": " + br.readLine()); // Read response
            }
        }
    }
}
