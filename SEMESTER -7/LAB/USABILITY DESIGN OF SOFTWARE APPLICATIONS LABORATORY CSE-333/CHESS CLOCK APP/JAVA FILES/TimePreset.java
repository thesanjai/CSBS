package com.example.chessclock;

import java.io.Serializable;

// This class is a "blueprint" for our time controls.
// We implement Serializable so we can pass this object between Activities.
public class TimePreset implements Serializable {

    private String name;
    private long timeInMillis;
    private long incrementInMillis;

    // Constructor
    public TimePreset(String name, long timeInMillis, long incrementInMillis) {
        this.name = name;
        this.timeInMillis = timeInMillis;
        this.incrementInMillis = incrementInMillis;
    }

    // Getters
    public String getName() {
        return name;
    }

    public long getTimeInMillis() {
        return timeInMillis;
    }

    public long getIncrementInMillis() {
        return incrementInMillis;
    }
}
