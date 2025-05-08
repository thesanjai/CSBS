import java.io.*;
import java.net.*;
import java.util.Scanner;

class Receiver {
    public static void main(String[] args) {
        try {
            DatagramSocket ds = new DatagramSocket(3000);
            Scanner sc = new Scanner(System.in);

            while (true) {
                byte[] buf = new byte[1024];
                DatagramPacket dp = new DatagramPacket(buf, 1024);
                ds.receive(dp);
                String str = new String(dp.getData(), 0, dp.getLength());
                System.out.println("Sender: " + str);

                System.out.print("You: ");
                String response = sc.nextLine();
                InetAddress ip = dp.getAddress();
                int port = dp.getPort();
                DatagramPacket dpSend = new DatagramPacket(response.getBytes(), response.length(), ip, port);
                ds.send(dpSend);
            }
        } catch (Exception e) {
            System.out.println(e);
        }
    }
}