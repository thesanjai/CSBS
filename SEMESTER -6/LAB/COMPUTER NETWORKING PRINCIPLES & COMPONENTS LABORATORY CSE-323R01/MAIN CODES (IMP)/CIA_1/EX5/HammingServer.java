import java.io.*;
import java.net.*;
import java.util.*;

class HammingServer {
    public static int[] generateHammingCode(int[] data, int n) {
        int r = 0;
        while (Math.pow(2, r) < (n + r + 1)) {
            r++;
        }
        int m = n + r; 
        int[] hammingCode = new int[m + 1];
        int j = 0;
        for (int i = 1; i <= m; i++) {
            if ((i & (i - 1)) == 0) { 
                hammingCode[i] = 0;
            } else {
                hammingCode[i] = data[j++];
            }
        }
        for (int i = 1; i <= m; i *= 2) {
            int sum = 0;
            for (int k = i; k <= m; k += 2 * i) {
                for (int l = 0; l < i && (k + l) <= m; l++) {
                    sum ^= hammingCode[k + l];
                }
            }
            hammingCode[i] = sum;
        }

        return hammingCode;
    }

    public static void main(String[] args) {
        try {
            ServerSocket server = new ServerSocket(5000);
            System.out.println("Server is waiting for connection...");
            Socket socket = server.accept();
            System.out.println("Client connected!");

            BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
            PrintWriter writer = new PrintWriter(socket.getOutputStream(), true);

            System.out.print("Enter number of data bits: ");
            int n = Integer.parseInt(reader.readLine());

            int[] data = new int[n];
            System.out.print("Enter data bits: ");
            for (int i = 0; i < n; i++) {
                data[i] = Integer.parseInt(reader.readLine());
            }

            int[] hammingCode = generateHammingCode(data, n);

            StringBuilder codeStr = new StringBuilder();
            for (int i = 1; i < hammingCode.length; i++) {
                codeStr.append(hammingCode[i]);
            }

            System.out.println("Transmitted codeword: " + codeStr);
            writer.println(codeStr.toString()); 

            server.close();
        } catch (Exception e) {
            System.out.println(e);
        }
    }
}
