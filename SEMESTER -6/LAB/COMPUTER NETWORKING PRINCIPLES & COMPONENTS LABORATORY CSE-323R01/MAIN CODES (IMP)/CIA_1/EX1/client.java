// import java.net.*;
// import java.io.*;
// class TestClient
// {
//     public static void main(String ar[])
//     {
//         try
//         {
//             Socket s=new Socket("192.168.1.116",2000);
//             BufferedReader br=new BufferedReader(new InputStreamReader(s.getInputStream()));
//             String s1=br.readLine();
//             System.out.println(s1);
       
//             PrintStream pr=new PrintStream(s.getOutputStream());
//             pr.println("Thank u");
//         }
//         catch(Exception e)
//         {
//             System.out.println(e);
//         }
       
//     }
// }

import java.net.*;
import java.io.*;
import java.util.Scanner;

class TestClient {
    public static void main(String[] ar) {
        try {
            Socket s = new Socket("192.168.1.116", 2000); 
            BufferedReader br = new BufferedReader(new InputStreamReader(s.getInputStream()));
            PrintStream pr = new PrintStream(s.getOutputStream());

            Scanner scanner = new Scanner(System.in);

            while (true) {
                System.out.print("Client: ");
                String clientMessage = scanner.nextLine();
                pr.println(clientMessage);

                if (clientMessage.equalsIgnoreCase("exit")) {
                    System.out.println("Client ended the chat.");
                    break;
                }

                String serverMessage = br.readLine();
                if (serverMessage == null || serverMessage.equalsIgnoreCase("exit")) {
                    System.out.println("Server disconnected.");
                    break;
                }
                System.out.println("Server: " + serverMessage);
            }

            s.close();
        } catch (Exception e) {
            System.out.println(e);
        }
    }
}
