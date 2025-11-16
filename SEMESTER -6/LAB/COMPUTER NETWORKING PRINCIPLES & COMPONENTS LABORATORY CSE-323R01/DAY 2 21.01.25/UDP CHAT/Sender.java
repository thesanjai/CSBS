import java.io.*;
import java.net.*;
import java.util.Scanner;

class Sender {
    public static void main(String[] args) {
        try {
            DatagramSocket ds = new DatagramSocket(4000);
            InetAddress ip = InetAddress.getByName("localhost");
            Scanner sc = new Scanner(System.in);

            while (true) {
                System.out.print("You: ");
                String str = sc.nextLine();
                DatagramPacket dp = new DatagramPacket(str.getBytes(), str.length(), ip, 3000);
                ds.send(dp);

                byte[] buf = new byte[1024];
                DatagramPacket dpReceive = new DatagramPacket(buf, 1024);
                ds.receive(dpReceive);
                String received = new String(dpReceive.getData(), 0, dpReceive.getLength());
                System.out.println("Receiver: " + received);
                
            }
        } catch (Exception e) {
            System.out.println(e);
        }
    }
}