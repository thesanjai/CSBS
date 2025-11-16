// TCP Server - making directories 
import java.io.*;
import java.net.*;

public class Server {
    public static void main(String[] args) throws IOException {
        ServerSocket ss = new ServerSocket(2000);
        System.out.println("Waiting for client...");
        Socket s = ss.accept();
        BufferedReader br = new BufferedReader(new InputStreamReader(s.getInputStream()));
        PrintStream ps = new PrintStream(s.getOutputStream());

        String dirName = br.readLine(); 
        File dir = new File(dirName);
        ps.println(dir.mkdir() ? "Successfully Created: " + dirName : "Failed to Create");

        ss.close();
    }
}
