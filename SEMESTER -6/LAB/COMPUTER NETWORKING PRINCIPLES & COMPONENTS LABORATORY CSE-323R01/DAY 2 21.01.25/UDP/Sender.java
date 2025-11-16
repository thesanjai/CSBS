import java.io.*;
import java.net.*;
class Sender{
    public static void main(String[] args) {
        try {
            DatagramSocket ds = new DatagramSocket(4000);
            String str = "Hello World";
            InetAddress ip = InetAddress.getByName("localhost");
            DatagramPacket dp = new DatagramPacket(str.getBytes(), str.length(), ip, 3000);
            ds.send(dp);
            System.out.println("Data sent");
            ds.close();

        }
        catch (Exception e) {
            System.out.println(e);
        }
    }
}