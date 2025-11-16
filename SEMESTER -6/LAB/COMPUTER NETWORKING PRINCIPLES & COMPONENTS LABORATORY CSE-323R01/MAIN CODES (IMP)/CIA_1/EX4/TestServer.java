import java.net.*;
import java.io.*;

class TestServer {
    public static void main(String[] args) {
        try {
            ServerSocket ss = new ServerSocket(2000);
            System.out.println("Waiting for client...");
            Socket s = ss.accept();
            System.out.println("Connection Established");

            BufferedReader fileReader = new BufferedReader(new FileReader("message.txt"));
            PrintStream pr = new PrintStream(s.getOutputStream());

            String line;
            while ((line = fileReader.readLine()) != null) {
                char[] c = line.toCharArray();
                for (int i = 0; i < c.length; i++) 
                    {
                        c[i] = (char) (c[i] + 5);
                    }
                String encryptedLine = new String(c);
                System.out.println("Sending Encrypted: " + encryptedLine);
                pr.println(encryptedLine);  
            }
            pr.println("END"); 
            fileReader.close();
            ss.close();
        } catch (Exception e) {
            System.out.println(e);
        }
    }
}
