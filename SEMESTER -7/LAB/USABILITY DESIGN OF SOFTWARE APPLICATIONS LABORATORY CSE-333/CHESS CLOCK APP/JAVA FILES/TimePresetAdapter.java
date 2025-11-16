package com.example.chessclock;

import android.content.Context;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ImageView;
import android.widget.RelativeLayout;
import android.widget.TextView;

import androidx.annotation.NonNull;
import androidx.core.content.ContextCompat;
import androidx.recyclerview.widget.RecyclerView;

import java.util.List;

public class TimePresetAdapter extends RecyclerView.Adapter<TimePresetAdapter.PresetViewHolder> {

    // This interface is a "listener" that will send clicks back to our Activity
    public interface OnPresetClickListener {
        void onPresetClick(int position);
    }

    private Context mContext;
    private List<TimePreset> mPresetList;
    private OnPresetClickListener mListener;
    private int mSelectedPosition = -1; // -1 means no selection

    // Constructor
    public TimePresetAdapter(Context context, List<TimePreset> presetList, OnPresetClickListener listener) {
        mContext = context;
        mPresetList = presetList;
        mListener = listener;
    }

    @NonNull
    @Override
    public PresetViewHolder onCreateViewHolder(@NonNull ViewGroup parent, int viewType) {
        // Create the view from our XML layout file (time_preset_item.xml)
        View v = LayoutInflater.from(mContext).inflate(R.layout.time_preset_item, parent, false);
        return new PresetViewHolder(v);
    }

    @Override
    public void onBindViewHolder(@NonNull PresetViewHolder holder, int position) {
        // Get the data for this row
        TimePreset currentPreset = mPresetList.get(position);
        holder.presetName.setText(currentPreset.getName());

        // Check if this row is the selected one
        if (position == mSelectedPosition) {
            // It's selected: show checked radio button
            holder.radioButton.setImageResource(R.drawable.ic_radio_button_checked);
            // --- THIS LINE IS FIXED ---
            holder.radioButton.setColorFilter(ContextCompat.getColor(mContext, R.color.color_accent_green));
        } else {
            // It's not selected: show unchecked radio button
            holder.radioButton.setImageResource(R.drawable.ic_radio_button_unchecked);
            // --- THIS LINE IS FIXED ---
            holder.radioButton.setColorFilter(ContextCompat.getColor(mContext, R.color.text_moves));
        }
    }

    @Override
    public int getItemCount() {
        return mPresetList.size();
    }

    // This method updates which item is selected
    public void setSelectedPosition(int position) {
        mSelectedPosition = position;
        notifyDataSetChanged(); // This tells the list to refresh itself
    }

    public int getSelectedPosition() {
        return mSelectedPosition;
    }

    // This "ViewHolder" class holds the UI elements for a *single row*
    public class PresetViewHolder extends RecyclerView.ViewHolder implements View.OnClickListener {

        public TextView presetName;
        public ImageView radioButton;
        public RelativeLayout itemLayout;

        public PresetViewHolder(@NonNull View itemView) {
            super(itemView);
            presetName = itemView.findViewById(R.id.tv_preset_name);
            radioButton = itemView.findViewById(R.id.iv_radio_button);
            itemLayout = itemView.findViewById(R.id.item_layout);

            // Set a click listener on the entire row
            itemLayout.setOnClickListener(this);
        }

        @Override
        public void onClick(View v) {
            if (mListener != null) {
                int position = getAdapterPosition();
                if (position != RecyclerView.NO_POSITION) {
                    // Send the click back to the Activity
                    mListener.onPresetClick(position);
                }
            }
        }
    }
}

