import java.io.*;
import java.net.*;
class Receiver{
    public static void main(String[] args) {
        try {
            DatagramSocket ds = new DatagramSocket(3000);
            byte[] buf = new byte[1024];
            DatagramPacket dp = new DatagramPacket(buf, 1024);
            ds.receive(dp);
            String str = new String(dp.getData(), 0, dp.getLength());
            System.out.println(str);
            System.out.println(dp.getAddress().getHostAddress());
            System.out.println(dp.getPort());
            ds.close();

        }
        catch (Exception e) {
            System.out.println(e);
        }
    }
}