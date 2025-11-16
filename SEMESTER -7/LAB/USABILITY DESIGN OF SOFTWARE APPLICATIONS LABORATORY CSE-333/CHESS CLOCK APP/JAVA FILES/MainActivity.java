package com.example.chessclock; // Make sure this matches your package name!

import androidx.activity.result.ActivityResult;
import androidx.activity.result.ActivityResultCallback;
import androidx.activity.result.ActivityResultLauncher;
import androidx.activity.result.contract.ActivityResultContracts;
import androidx.appcompat.app.AlertDialog;
import androidx.appcompat.app.AppCompatActivity;
import androidx.core.content.ContextCompat;

// --- STAGE 3: New Imports ---
import android.app.Activity;
import android.content.Intent;
// --- End New Imports ---

import android.content.DialogInterface;
import android.media.AudioManager;
import android.media.SoundPool;
import android.os.Bundle;
import android.os.CountDownTimer;
import android.view.LayoutInflater;
import android.view.View;
import android.view.WindowManager;
import android.widget.Button;
import android.widget.ImageView;
import android.widget.NumberPicker;
import android.widget.RelativeLayout;
import android.widget.TextView;
import android.widget.Toast;

import java.io.Serializable;
import java.util.Locale;
import java.util.concurrent.TimeUnit;

public class MainActivity extends AppCompatActivity {

    // --- Time Control Settings ---
    private long mPlayer1StartTimeInMillis = 60000; // 1 minute
    private long mPlayer2StartTimeInMillis = 60000;
    private long mPlayer1IncrementInMillis = 2000; // 2 seconds
    private long mPlayer2IncrementInMillis = 2000;

    // --- UI Elements ---
    private RelativeLayout mPlayer1Layout;
    private RelativeLayout mPlayer2Layout;
    private TextView mPlayer1TimerText;
    private TextView mPlayer2TimerText;
    private TextView mPlayer1MovesText;
    private TextView mPlayer2MovesText;

    private ImageView mPlayer1Settings;
    private ImageView mPlayer2Settings;

    // Middle bar icons
    private ImageView mIconReset;
    private ImageView mIconPlayPause;
    private ImageView mIconTimeSettings;
    private ImageView mIconSound;

    // --- Timer Logic Variables ---
    private CountDownTimer mCountDownTimer;
    private boolean mGameRunning;
    private boolean mIsPlayer1Turn;

    private long mPlayer1TimeLeftInMillis;
    private long mPlayer2TimeLeftInMillis;


    private int mPlayer1MoveCount;
    private int mPlayer2MoveCount;

    // --- Sound Variables ---
    private SoundPool mSoundPool;
    private int mClickSoundId;
    private boolean mSoundEnabled = true;


    // --- STAGE 3: Activity Result Launcher ---
    private ActivityResultLauncher<Intent> mTimeSettingsLauncher = registerForActivityResult(
            new ActivityResultContracts.StartActivityForResult(),
            new ActivityResultCallback<ActivityResult>() {
                @Override
                public void onActivityResult(ActivityResult result) {
                    if (result.getResultCode() == Activity.RESULT_OK) {
                        Intent data = result.getData();
                        if (data != null && data.hasExtra("SELECTED_PRESET")) {
                            TimePreset selectedPreset = (TimePreset) data.getSerializableExtra("SELECTED_PRESET");
                            mPlayer1StartTimeInMillis = selectedPreset.getTimeInMillis();
                            mPlayer2StartTimeInMillis = selectedPreset.getTimeInMillis();
                            mPlayer1IncrementInMillis = selectedPreset.getIncrementInMillis();
                            mPlayer2IncrementInMillis = selectedPreset.getIncrementInMillis();
                            resetGame();
                        }
                    }
                }
            });


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        getWindow().addFlags(WindowManager.LayoutParams.FLAG_KEEP_SCREEN_ON);

        // --- Initialize UI Elements ---
        mPlayer1Layout = findViewById(R.id.rl_player1);
        mPlayer2Layout = findViewById(R.id.rl_player2);
        mPlayer1TimerText = findViewById(R.id.tv_player1_timer);
        mPlayer2TimerText = findViewById(R.id.tv_player2_timer);
        mPlayer1MovesText = findViewById(R.id.tv_player1_moves);
        mPlayer2MovesText = findViewById(R.id.tv_player2_moves);

        mPlayer1Settings = findViewById(R.id.iv_player1_settings);
        mPlayer2Settings = findViewById(R.id.iv_player2_settings);

        mIconReset = findViewById(R.id.iv_reset);
        mIconPlayPause = findViewById(R.id.iv_play_pause);
        mIconTimeSettings = findViewById(R.id.iv_time_settings);
        mIconSound = findViewById(R.id.iv_sound);

        // --- Load Sound ---
        mSoundPool = new SoundPool.Builder().setMaxStreams(1).build();
        try {
            mClickSoundId = mSoundPool.load(this, R.raw.clock_click, 1);
        } catch (Exception e) {
            android.util.Log.e("Sound", "Could not load sound file. Make sure res/raw/clock_click.mp3 exists.");
            mClickSoundId = -1;
        }


        // --- Set Click Listeners ---

        // Player 1's clock
        mPlayer1Layout.setOnClickListener(v -> {
            if (!mGameRunning) {
                // --- START STATE FIX: ---
                // If game isn't running and it's a fresh start, tapping P1 starts P2's clock.
                if (mPlayer1MoveCount == 0 && mPlayer2MoveCount == 0) {
                    startGame(false); // false means mIsPlayer1Turn = false (P2's turn)
                }
            } else if (mIsPlayer1Turn) {
                // If game is running and it's P1's turn, switch player.
                switchPlayer();
            }
        });

        // Player 2's clock
        mPlayer2Layout.setOnClickListener(v -> {
            if (!mGameRunning) {
                // --- START STATE FIX: ---
                // If game isn't running and it's a fresh start, tapping P2 starts P1's clock.
                if (mPlayer1MoveCount == 0 && mPlayer2MoveCount == 0) {
                    startGame(true); // true means mIsPlayer1Turn = true (P1's turn)
                }
            } else if (!mIsPlayer1Turn) {
                // If game is running and it's P2's turn, switch player.
                switchPlayer();
            }
        });

        // Middle Bar: Reset
        mIconReset.setOnClickListener(v -> resetGame());

        // Middle Bar: Play/Pause
        mIconPlayPause.setOnClickListener(v -> {
            if (mGameRunning) {
                pauseGame();
            } else {
                // --- START STATE FIX: ---
                // If we are resuming, start with whoever's turn it was
                if (mPlayer1MoveCount > 0 || mPlayer2MoveCount > 0 || mPlayer1TimeLeftInMillis != mPlayer1StartTimeInMillis) {
                    startGame(mIsPlayer1Turn);
                } else {
                    // If it's a fresh game and "Play" is pressed, default to starting P1's clock
                    startGame(true);
                }
            }
        });

        // Middle Bar: Sound
        mIconSound.setOnClickListener(v -> toggleSound());

        // --- STAGE 3: Updated Click Listener ---
        // Middle Bar: Time Settings
        mIconTimeSettings.setOnClickListener(v -> {
            if(mGameRunning) {
                Toast.makeText(this, "Pause the game to change settings.", Toast.LENGTH_SHORT).show();
            } else {
                // Launch our new Activity
                Intent intent = new Intent(MainActivity.this, TimeSettingsActivity.class);
                mTimeSettingsLauncher.launch(intent);
            }
        });

        // Player 1 Settings (Adjust Time)
        mPlayer1Settings.setOnClickListener(v -> {
            if (mGameRunning) {
                Toast.makeText(this, "Pause the game to adjust time.", Toast.LENGTH_SHORT).show();
            } else {
                showAdjustTimeDialog(true); // true for Player 1
            }
        });

        // Player 2 Settings (Adjust Time)
        mPlayer2Settings.setOnClickListener(v -> {
            if (mGameRunning) {
                Toast.makeText(this, "Pause the game to adjust time.", Toast.LENGTH_SHORT).show();
            } else {
                showAdjustTimeDialog(false); // false for Player 2
            }
        });

        // Initialize the game
        resetGame();
    }

    // --- STAGE 2: New Method to show the dialog ---
    private void showAdjustTimeDialog(boolean isPlayer1) {
        // Inflate the custom layout
        LayoutInflater inflater = this.getLayoutInflater();
        View dialogView = inflater.inflate(R.layout.dialog_adjust_time, null);

        AlertDialog.Builder builder = new AlertDialog.Builder(this, R.style.Theme_ChessClock_Dialog);
        builder.setView(dialogView);

        // Find views in the dialog layout
        NumberPicker hourPicker = dialogView.findViewById(R.id.picker_hour);
        NumberPicker minutePicker = dialogView.findViewById(R.id.picker_minute);
        NumberPicker secondPicker = dialogView.findViewById(R.id.picker_second);
        Button btnCancel = dialogView.findViewById(R.id.btn_cancel);
        Button btnSave = dialogView.findViewById(R.id.btn_save_time);

        // --- Configure Pickers ---
        hourPicker.setMinValue(0);
        hourPicker.setMaxValue(9); // Max 9 hours
        minutePicker.setMinValue(0);
        minutePicker.setMaxValue(59);
        secondPicker.setMinValue(0);
        secondPicker.setMaxValue(59);

        // Get the current time for the selected player
        long currentTimeInMillis = isPlayer1 ? mPlayer1TimeLeftInMillis : mPlayer2TimeLeftInMillis;

        // Convert millis to H:M:S
        long hours = TimeUnit.MILLISECONDS.toHours(currentTimeInMillis);
        long minutes = TimeUnit.MILLISECONDS.toMinutes(currentTimeInMillis) % 60;
        long seconds = TimeUnit.MILLISECONDS.toSeconds(currentTimeInMillis) % 60;

        // Set the pickers to the current time
        hourPicker.setValue((int) hours);
        minutePicker.setValue((int) minutes);
        secondPicker.setValue((int) seconds);

        // Create the dialog
        AlertDialog dialog = builder.create();

        // Set Button Listeners
        btnCancel.setOnClickListener(v -> dialog.dismiss());

        btnSave.setOnClickListener(v -> {
            // Get new values
            int newHours = hourPicker.getValue();
            int newMinutes = minutePicker.getValue();
            int newSeconds = secondPicker.getValue();

            // Convert to millis
            long newTimeInMillis = TimeUnit.HOURS.toMillis(newHours) +
                    TimeUnit.MINUTES.toMillis(newMinutes) +
                    TimeUnit.SECONDS.toMillis(newSeconds);

            // Update the correct player
            if (isPlayer1) {
                mPlayer1TimeLeftInMillis = newTimeInMillis;
                mPlayer1StartTimeInMillis = newTimeInMillis; // Also update the start time for resets
                updateTimerText(mPlayer1TimerText, mPlayer1TimeLeftInMillis);
            } else {
                mPlayer2TimeLeftInMillis = newTimeInMillis;
                mPlayer2StartTimeInMillis = newTimeInMillis; // Also update the start time for resets
                updateTimerText(mPlayer2TimerText, mPlayer2TimeLeftInMillis);
            }

            dialog.dismiss();
        });

        // Show the dialog
        dialog.show();
    }

    // --- START STATE FIX: ---
    // Modified startGame to accept whose turn it is
    private void startGame(boolean startWithPlayer1Turn) {
        if (mCountDownTimer != null) {
            mCountDownTimer.cancel();
        }

        playSound(); // Play sound on the very first tap

        mIsPlayer1Turn = startWithPlayer1Turn;
        long timeToStart = mIsPlayer1Turn ? mPlayer1TimeLeftInMillis : mPlayer2TimeLeftInMillis;
        startTimer(timeToStart);
        mGameRunning = true;
        mIconPlayPause.setImageResource(R.drawable.ic_pause);
        updateActivePlayerUI();
    }

    private void switchPlayer() {
        if (mCountDownTimer != null) {
            mCountDownTimer.cancel();
        }

        playSound();

        if (mIsPlayer1Turn) {
            mPlayer1TimeLeftInMillis += mPlayer1IncrementInMillis;
            updateTimerText(mPlayer1TimerText, mPlayer1TimeLeftInMillis);
            mPlayer1MoveCount++;
        } else {
            mPlayer2TimeLeftInMillis += mPlayer2IncrementInMillis;
            updateTimerText(mPlayer2TimerText, mPlayer2TimeLeftInMillis);
            mPlayer2MoveCount++;
        }

        mIsPlayer1Turn = !mIsPlayer1Turn;
        long timeToStart = mIsPlayer1Turn ? mPlayer1TimeLeftInMillis : mPlayer2TimeLeftInMillis;
        startTimer(timeToStart);
        updateMoveCounters();
        updateActivePlayerUI();
    }

    private void pauseGame() {
        if (mCountDownTimer != null) {
            mCountDownTimer.cancel();
        }
        mGameRunning = false;
        mIconPlayPause.setImageResource(R.drawable.ic_play);
    }

    private void resetGame() {
        if (mCountDownTimer != null) {
            mCountDownTimer.cancel();
        }

        mGameRunning = false;
        mPlayer1TimeLeftInMillis = mPlayer1StartTimeInMillis;
        mPlayer2TimeLeftInMillis = mPlayer2StartTimeInMillis;

        mPlayer1MoveCount = 0;
        mPlayer2MoveCount = 0;

        updateTimerText(mPlayer1TimerText, mPlayer1TimeLeftInMillis);
        updateTimerText(mPlayer2TimerText, mPlayer2TimeLeftInMillis);
        updateMoveCounters();

        mIconPlayPause.setImageResource(R.drawable.ic_play);

        // --- START STATE FIX: ---
        // Set both players to the inactive (grey) state
        mPlayer1Layout.setBackgroundColor(ContextCompat.getColor(this, R.color.color_inactive));
        mPlayer1TimerText.setTextColor(ContextCompat.getColor(this, R.color.text_inactive));
        mPlayer1MovesText.setTextColor(ContextCompat.getColor(this, R.color.text_moves));
        mPlayer1Settings.setColorFilter(ContextCompat.getColor(this, R.color.text_inactive));

        mPlayer2Layout.setBackgroundColor(ContextCompat.getColor(this, R.color.color_inactive));
        mPlayer2TimerText.setTextColor(ContextCompat.getColor(this, R.color.text_inactive));
        mPlayer2MovesText.setTextColor(ContextCompat.getColor(this, R.color.text_moves));
        mPlayer2Settings.setColorFilter(ContextCompat.getColor(this, R.color.text_inactive));
    }

    private void startTimer(long timeInMillis) {
        mCountDownTimer = new CountDownTimer(timeInMillis, 100) {
            @Override
            public void onTick(long millisUntilFinished) {
                if (mIsPlayer1Turn) {
                    mPlayer1TimeLeftInMillis = millisUntilFinished;
                    updateTimerText(mPlayer1TimerText, millisUntilFinished);
                } else {
                    mPlayer2TimeLeftInMillis = millisUntilFinished;
                    updateTimerText(mPlayer2TimerText, millisUntilFinished);
                }
            }

            @Override
            public void onFinish() {
                mGameRunning = false;
                Toast.makeText(MainActivity.this, "Time's up!", Toast.LENGTH_LONG).show();
                mIconPlayPause.setImageResource(R.drawable.ic_play);
            }
        }.start();
    }

    private void updateTimerText(TextView timerText, long millisLeft) {
        long minutes = (millisLeft / 1000) / 60;
        long seconds = (millisLeft / 1000) % 60;

        long hours = (millisLeft / 1000) / 3600;
        if (hours > 0) {
            minutes = (millisLeft / 1000) % 3600 / 60;
        }

        String timeLeftFormatted;
        if (hours > 0) {
            timeLeftFormatted = String.format(Locale.getDefault(), "%d:%02d:%02d", hours, minutes, seconds);
        } else {
            timeLeftFormatted = String.format(Locale.getDefault(), "%d:%02d", minutes, seconds);
        }

        timerText.setText(timeLeftFormatted);
    }

    private void updateMoveCounters() {
        mPlayer1MovesText.setText(String.format(Locale.getDefault(), getString(R.string.moves_text), mPlayer1MoveCount));
        mPlayer2MovesText.setText(String.format(Locale.getDefault(), getString(R.string.moves_text), mPlayer2MoveCount));
    }

    private void playSound() {
        if (mSoundEnabled && mClickSoundId != -1) {
            mSoundPool.play(mClickSoundId, 1.0f, 1.0f, 0, 0, 1.0f);
        }
    }

    private void toggleSound() {
        mSoundEnabled = !mSoundEnabled;
        if (mSoundEnabled) {
            mIconSound.setImageResource(R.drawable.ic_sound_on);
        } else {
            mIconSound.setImageResource(R.drawable.ic_sound_off);
        }
    }

    private void updateActivePlayerUI() {
        if (mIsPlayer1Turn) {
            mPlayer1Layout.setBackgroundColor(ContextCompat.getColor(this, R.color.color_active));
            mPlayer1TimerText.setTextColor(ContextCompat.getColor(this, R.color.text_active));
            mPlayer1MovesText.setTextColor(ContextCompat.getColor(this, R.color.text_moves));
            mPlayer1Settings.setColorFilter(ContextCompat.getColor(this, R.color.text_active));

            mPlayer2Layout.setBackgroundColor(ContextCompat.getColor(this, R.color.color_inactive));
            mPlayer2TimerText.setTextColor(ContextCompat.getColor(this, R.color.text_inactive));
            mPlayer2MovesText.setTextColor(ContextCompat.getColor(this, R.color.text_moves));
            mPlayer2Settings.setColorFilter(ContextCompat.getColor(this, R.color.text_inactive));
        } else {
            mPlayer1Layout.setBackgroundColor(ContextCompat.getColor(this, R.color.color_inactive));
            mPlayer1TimerText.setTextColor(ContextCompat.getColor(this, R.color.text_inactive));
            mPlayer1MovesText.setTextColor(ContextCompat.getColor(this, R.color.text_moves));
            mPlayer1Settings.setColorFilter(ContextCompat.getColor(this, R.color.text_inactive));

            mPlayer2Layout.setBackgroundColor(ContextCompat.getColor(this, R.color.color_active));
            mPlayer2TimerText.setTextColor(ContextCompat.getColor(this, R.color.text_active));
            mPlayer2MovesText.setTextColor(ContextCompat.getColor(this, R.color.text_moves));
            mPlayer2Settings.setColorFilter(ContextCompat.getColor(this, R.color.text_active));
        }
    }


    @Override
    protected void onDestroy() {
        super.onDestroy();
        if (mCountDownTimer != null) {
            mCountDownTimer.cancel();
        }
        if (mSoundPool != null) {
            mSoundPool.release();
            mSoundPool = null;
        }
    }
}

