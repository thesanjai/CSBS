import java.util.Random;

class LeakyBucket {
    private int capacity;
    private int outputRate;
    private int currentLevel;

    public LeakyBucket(int capacity, int outputRate) {
        this.capacity = capacity;
        this.outputRate = outputRate;
        this.currentLevel = 0;
    }

    public void addPacket(int packetSize) {
        if (currentLevel + packetSize > capacity) {
            System.out.println("LeakyBucket: Packet of size " + packetSize + " dropped. Bucket full!");
        } else {
            currentLevel += packetSize;
            System.out.println("LeakyBucket: Packet of size " + packetSize + " added. Current level: " + currentLevel);
        }
    }

    public void leak() {
        int leakAmount = Math.min(currentLevel, outputRate);
        currentLevel -= leakAmount;
        System.out.println("LeakyBucket: Leaked " + leakAmount + ". Current level: " + currentLevel);
    }
}

class TokenBucket {
    private int capacity;
    private int tokenRate;
    private int tokens;

    public TokenBucket(int capacity, int tokenRate) {
        this.capacity = capacity;
        this.tokenRate = tokenRate;
        this.tokens = 0;
    }

    public void addTokens() {
        int tokensToAdd = Math.min(tokenRate, capacity - tokens);
        tokens += tokensToAdd;
        System.out.println("TokenBucket: Added " + tokensToAdd + " tokens. Available tokens: " + tokens);
    }

    public void sendPacket(int packetSize) {
        if (tokens >= packetSize) {
            tokens -= packetSize;
            System.out.println("TokenBucket: Packet of size " + packetSize + " sent. Tokens left: " + tokens);
        } else {
            System.out.println("TokenBucket: Packet of size " + packetSize + " dropped. Not enough tokens!");
        }
    }
}

public class CongestionControlSimulation {
    public static void main(String[] args) throws InterruptedException {
        Random rand = new Random();

        System.out.println("=== Leaky Bucket Simulation ===");
        LeakyBucket leakyBucket = new LeakyBucket(10, 3);
        for (int i = 0; i < 5; i++) {
            int packetSize = rand.nextInt(4) + 1;
            leakyBucket.addPacket(packetSize);
            leakyBucket.leak();
            Thread.sleep(500);
        }

        System.out.println("\n=== Token Bucket Simulation ===");
        TokenBucket tokenBucket = new TokenBucket(10, 3);
        for (int i = 0; i < 5; i++) {
            tokenBucket.addTokens();
            int packetSize = rand.nextInt(4) + 1;
            tokenBucket.sendPacket(packetSize);
            Thread.sleep(500);
        }
    }
}
