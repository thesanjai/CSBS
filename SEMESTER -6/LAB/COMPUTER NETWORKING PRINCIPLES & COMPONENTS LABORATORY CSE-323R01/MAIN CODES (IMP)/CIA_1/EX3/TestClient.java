// // Decrypt without GUI:

// import java.net.*;
// import java.io.*;
// class TestClient
// {
//     public static void main(String ar[])
//     {
//         try
//         {
//             Socket s=new Socket("localhost",2000);
//             BufferedReader br=new BufferedReader(new InputStreamReader(s.getInputStream()));
//             String s1=br.readLine();
//             System.out.println("\n Received msg. "+s1);
//             //System.out.println(s1);'
//             char c[]=s1.toCharArray();
//             for(int i=0;i<c.length;i++)
//             {
//                 c[i]=(char)(c[i]+5);
//             }
//             String a=new String(c);
//             System.out.println("\n After Decrypt :"+a);
//         }
//         catch(Exception e)
//         {
//             System.out.println(e);
//         }
       
//     }
// }

import java.net.*;
import java.io.*;

class TestClient {
    public static void main(String ar[]) {
        try {
            Socket s = new Socket("localhost", 2000);  
            BufferedReader br = new BufferedReader(new InputStreamReader(s.getInputStream()));
            String receivedMessage = br.readLine();
            System.out.println("\nReceived encrypted message: " + receivedMessage);

            String decryptedMessage = decrypt(receivedMessage);
            System.out.println("\nAfter Decrypt: " + decryptedMessage);
        } catch (Exception e) {
            System.out.println(e);
        }
    }

    public static String decrypt(String message) {
        char[] c = message.toCharArray();
        for (int i = 0; i < c.length; i++) {
            c[i] = (char)(c[i] - 5);  
        }
        return new String(c);
    }
}
