package com.example.chessclock;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.ImageView;
import android.widget.Toast;

import androidx.activity.result.ActivityResult;
import androidx.activity.result.ActivityResultCallback;
import androidx.activity.result.ActivityResultLauncher;
import androidx.activity.result.contract.ActivityResultContracts;
import androidx.annotation.Nullable;
import androidx.appcompat.app.AppCompatActivity;
import androidx.recyclerview.widget.LinearLayoutManager;
import androidx.recyclerview.widget.RecyclerView;

import java.util.ArrayList;
import java.util.List;
import java.util.concurrent.TimeUnit;

public class TimeSettingsActivity extends AppCompatActivity implements TimePresetAdapter.OnPresetClickListener {

    private RecyclerView mRecyclerView;
    private TimePresetAdapter mAdapter;
    private List<TimePreset> mPresetList;

    private Button mBtnStartGame;
    private ImageView mBtnBack;

    // --- STAGE 4: Launcher for the CustomTimeActivity ---
    private ActivityResultLauncher<Intent> mCustomTimeLauncher = registerForActivityResult(
            new ActivityResultContracts.StartActivityForResult(),
            new ActivityResultCallback<ActivityResult>() {
                @Override
                public void onActivityResult(ActivityResult result) {
                    if (result.getResultCode() == Activity.RESULT_OK) {
                        Intent data = result.getData();
                        if (data != null && data.hasExtra("NEW_PRESET")) {
                            // We got our new custom preset!
                            TimePreset newPreset = (TimePreset) data.getSerializableExtra("NEW_PRESET");

                            // Add it to our list
                            mPresetList.add(newPreset);

                            // Tell the adapter the list has changed
                            mAdapter.notifyDataSetChanged();

                            // Automatically select the new preset
                            mAdapter.setSelectedPosition(mPresetList.size() - 1);
                        }
                    }
                }
            });


    @Override
    protected void onCreate(@Nullable Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_time_settings);

        mRecyclerView = findViewById(R.id.recycler_view_presets);
        mBtnStartGame = findViewById(R.id.btn_start_game);
        mBtnBack = findViewById(R.id.iv_back);

        // --- STAGE 4: Updated Click Listener ---
        Button btnNewCustomTime = findViewById(R.id.btn_new_custom_time);
        btnNewCustomTime.setOnClickListener(v -> {
            // Launch the CustomTimeActivity
            Intent intent = new Intent(TimeSettingsActivity.this, CustomTimeActivity.class);
            mCustomTimeLauncher.launch(intent);
        });


        mBtnBack.setOnClickListener(v -> {
            // Just go back without sending data
            setResult(Activity.RESULT_CANCELED);
            finish();
        });

        mBtnStartGame.setOnClickListener(v -> {
            int selectedPosition = mAdapter.getSelectedPosition();
            if (selectedPosition == -1) {
                Toast.makeText(this, "Please select a time control.", Toast.LENGTH_SHORT).show();
                return;
            }

            // Get the selected preset
            TimePreset selectedPreset = mPresetList.get(selectedPosition);

            // Create an Intent to send the data back
            Intent resultIntent = new Intent();
            resultIntent.putExtra("SELECTED_PRESET", selectedPreset);
            setResult(Activity.RESULT_OK, resultIntent);
            finish(); // Close this screen and go back
        });

        initPresetList();
        setupRecyclerView();
    }

    private void initPresetList() {
        mPresetList = new ArrayList<>();
        // Create our list of presets based on your screenshot
        mPresetList.add(new TimePreset(getString(R.string.preset_30_sec), TimeUnit.SECONDS.toMillis(30), 0));
        mPresetList.add(new TimePreset(getString(R.string.preset_1_min_2_sec), TimeUnit.MINUTES.toMillis(1), TimeUnit.SECONDS.toMillis(2)));
        mPresetList.add(new TimePreset(getString(R.string.preset_1_min), TimeUnit.MINUTES.toMillis(1), 0));
        mPresetList.add(new TimePreset(getString(R.string.preset_3_min_2_sec), TimeUnit.MINUTES.toMillis(3), TimeUnit.SECONDS.toMillis(2)));
        mPresetList.add(new TimePreset(getString(R.string.preset_5_min), TimeUnit.MINUTES.toMillis(5), 0));
        mPresetList.add(new TimePreset(getString(R.string.preset_10_min), TimeUnit.MINUTES.toMillis(10), 0));

        // Note: Custom presets will be added to this list dynamically
    }

    private void setupRecyclerView() {
        mAdapter = new TimePresetAdapter(this, mPresetList, this);
        mRecyclerView.setLayoutManager(new LinearLayoutManager(this));
        mRecyclerView.setAdapter(mAdapter);

        // Select "1 min | 2 sec" by default (it's at index 1)
        mAdapter.setSelectedPosition(1);
    }

    @Override
    public void onPresetClick(int position) {
        // When an item is clicked, update the adapter
        mAdapter.setSelectedPosition(position);
    }
}

