package com.example.chessclock;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.ImageView;
import android.widget.NumberPicker;
import android.widget.TextView;
import android.widget.Toast;

import androidx.annotation.Nullable;
import androidx.appcompat.app.AlertDialog;
import androidx.appcompat.app.AppCompatActivity;

import java.util.Locale;
import java.util.concurrent.TimeUnit;

public class CustomTimeActivity extends AppCompatActivity {

    private ImageView mBtnBack;
    private EditText mEtName;
    private TextView mTvTimeValue;
    private TextView mTvIncrementValue;
    private Button mBtnSave;

    // We'll store the selected values (in millis) here
    private long mTimeInMillis = 0;
    private long mIncrementInMillis = 0;

    @Override
    protected void onCreate(@Nullable Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_custom_time);

        mBtnBack = findViewById(R.id.iv_back);
        mEtName = findViewById(R.id.et_name);
        mTvTimeValue = findViewById(R.id.tv_time_value);
        mTvIncrementValue = findViewById(R.id.tv_increment_value);
        mBtnSave = findViewById(R.id.btn_save);

        mBtnBack.setOnClickListener(v -> {
            setResult(Activity.RESULT_CANCELED);
            finish();
        });

        // Show the time picker dialog when "Time" is clicked
        mTvTimeValue.setOnClickListener(v -> showSetTimeDialog(true));

        // Show the time picker dialog when "Increment" is clicked
        mTvIncrementValue.setOnClickListener(v -> showSetTimeDialog(false));

        mBtnSave.setOnClickListener(v -> saveCustomTime());
    }

    private void saveCustomTime() {
        String name = mEtName.getText().toString().trim();

        // --- Validate Input ---
        if (name.isEmpty()) {
            Toast.makeText(this, "Please enter a name.", Toast.LENGTH_SHORT).show();
            return;
        }
        if (mTimeInMillis == 0) {
            Toast.makeText(this, "Please set a time.", Toast.LENGTH_SHORT).show();
            return;
        }

        // --- Create a new preset ---
        TimePreset newPreset = new TimePreset(name, mTimeInMillis, mIncrementInMillis);

        // --- Send the preset back to TimeSettingsActivity ---
        Intent resultIntent = new Intent();
        resultIntent.putExtra("NEW_PRESET", newPreset);
        setResult(Activity.RESULT_OK, resultIntent);
        finish();
    }

    private void showSetTimeDialog(boolean isForTime) {
        // Inflate the custom layout
        LayoutInflater inflater = this.getLayoutInflater();
        View dialogView = inflater.inflate(R.layout.dialog_set_time, null);

        // Use the dark dialog theme
        AlertDialog.Builder builder = new AlertDialog.Builder(this, R.style.Theme_ChessClock_Dialog);
        // Set the title
        builder.setTitle(isForTime ? R.string.dialog_title_set_time : R.string.dialog_title_set_increment);
        builder.setView(dialogView);

        // Find views in the dialog layout
        NumberPicker minutePicker = dialogView.findViewById(R.id.picker_minute);
        NumberPicker secondPicker = dialogView.findViewById(R.id.picker_second);
        Button btnCancel = dialogView.findViewById(R.id.btn_cancel);
        Button btnSave = dialogView.findViewById(R.id.btn_save_time);

        // --- Configure Pickers ---
        minutePicker.setMinValue(0);
        minutePicker.setMaxValue(59);
        secondPicker.setMinValue(0);
        secondPicker.setMaxValue(59);

        // Get the current time for the selected picker
        long currentTimeInMillis = isForTime ? mTimeInMillis : mIncrementInMillis;
        long minutes = TimeUnit.MILLISECONDS.toMinutes(currentTimeInMillis);
        long seconds = TimeUnit.MILLISECONDS.toSeconds(currentTimeInMillis) % 60;

        // Set the pickers to the current time
        minutePicker.setValue((int) minutes);
        secondPicker.setValue((int) seconds);

        // Create the dialog
        AlertDialog dialog = builder.create();

        // Set Button Listeners
        btnCancel.setOnClickListener(v -> dialog.dismiss());

        btnSave.setOnClickListener(v -> {
            // Get new values
            int newMinutes = minutePicker.getValue();
            int newSeconds = secondPicker.getValue();

            // Convert to millis
            long newTimeInMillis = TimeUnit.MINUTES.toMillis(newMinutes) +
                    TimeUnit.SECONDS.toMillis(newSeconds);

            // Format as "MM : SS"
            String formattedTime = String.format(Locale.getDefault(), "%02d : %02d", newMinutes, newSeconds);

            // Update the correct variable and TextView
            if (isForTime) {
                mTimeInMillis = newTimeInMillis;
                mTvTimeValue.setText(formattedTime);
            } else {
                mIncrementInMillis = newTimeInMillis;
                mTvIncrementValue.setText(formattedTime);
            }

            dialog.dismiss();
        });

        // Show the dialog
        dialog.show();
    }
}
