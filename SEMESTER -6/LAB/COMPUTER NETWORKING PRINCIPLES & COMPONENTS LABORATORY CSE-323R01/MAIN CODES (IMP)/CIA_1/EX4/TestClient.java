import java.net.*;
import java.io.*;

class TestClient {
    public static void main(String[] args) {
        try {
            Socket s = new Socket("localhost", 2000);
            BufferedReader br = new BufferedReader(new InputStreamReader(s.getInputStream()));
            BufferedWriter fileWriter = new BufferedWriter(new FileWriter("output.txt"));

            String line;
            while (!(line = br.readLine()).equals("END")) {
                char[] c = line.toCharArray();
                for (int i = 0; i < c.length; i++) c[i] = (char) (c[i] - 5);
                fileWriter.write(new String(c) + "\n"); 
                System.out.println("Decrypted: " + new String(c));
            }

            fileWriter.close();
            s.close();
        } catch (Exception e) {
            System.out.println(e);
        }
    }
}
