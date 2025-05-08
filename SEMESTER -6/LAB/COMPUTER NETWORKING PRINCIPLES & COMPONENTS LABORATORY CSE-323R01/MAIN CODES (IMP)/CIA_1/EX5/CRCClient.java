import java.io.*;
import java.net.*;

class CRCClient {
    public static void main(String[] args) {
        try (Socket socket = new Socket("localhost", 5000)) {
            BufferedReader input = new BufferedReader(new InputStreamReader(socket.getInputStream()));

            String divisorStr = input.readLine();
            String receivedDataStr = input.readLine();

            int[] divisor = new int[divisorStr.length()];
            for (int i = 0; i < divisorStr.length(); i++)
                divisor[i] = divisorStr.charAt(i) - '0';

            int[] data = new int[receivedDataStr.length()];
            for (int i = 0; i < receivedDataStr.length(); i++)
                data[i] = receivedDataStr.charAt(i) - '0';

            System.out.println("Received Divisor   : " + divisorStr);
            System.out.println("Received Data+CRC  : " + receivedDataStr);

            if (hasError(data, divisor)) {
                System.out.println("Error detected in transmission!");
            } else {
                System.out.println("No Error in transmission.");
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    static boolean hasError(int[] data, int[] divisor) {
        int[] rem = divide(data.clone(), divisor);
        for (int bit : rem)
            if (bit != 0) return true;
        return false;
    }

    static int[] divide(int[] div, int[] divisor) {
        for (int i = 0; i <= div.length - divisor.length; ) {
            for (int j = 0; j < divisor.length; j++) {
                div[i + j] ^= divisor[j];
            }
            while (i < div.length && div[i] == 0) i++;
        }
        int[] rem = new int[divisor.length - 1];
        System.arraycopy(div, div.length - rem.length, rem, 0, rem.length);
        return rem;
    }
}
