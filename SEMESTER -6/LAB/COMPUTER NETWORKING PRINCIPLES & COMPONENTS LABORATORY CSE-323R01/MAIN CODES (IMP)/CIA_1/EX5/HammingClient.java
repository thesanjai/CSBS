import java.io.*;
import java.net.*;

class HammingClient {
    public static int checkForErrors(String receivedData) {
        int m = receivedData.length();
        int errorPos = 0;

        int[] hammingCode = new int[m + 1];
        for (int i = 1; i <= m; i++) {
            hammingCode[i] = receivedData.charAt(i - 1) - '0';
        }

        for (int i = 1; i <= m; i *= 2) {
            int sum = 0;
            for (int k = i; k <= m; k += 2 * i) {
                for (int l = 0; l < i && (k + l) <= m; l++) {
                    sum ^= hammingCode[k + l];
                }
            }
            if (sum == 1) {
                errorPos += i;
            }
        }

        return errorPos;
    }

    public static void main(String[] args) {
        try {
            Socket socket = new Socket("localhost", 5000);
            BufferedReader reader = new BufferedReader(new InputStreamReader(socket.getInputStream()));

            String receivedData = reader.readLine();
            System.out.println("Received Data: " + receivedData);

            int errorPos = checkForErrors(receivedData);
            if (errorPos == 0) {
                System.out.println("No Error in transmission.");
            } else {
                System.out.println("Error detected at position: " + errorPos);
            }

            socket.close();
        } catch (Exception e) {
            System.out.println(e);
        }
    }
}
