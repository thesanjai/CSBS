from flask import Flask, request, render_template
import joblib
import numpy as np
from collections import OrderedDict

app = Flask(__name__)

# Load the trained model, scaler, and feature names
try:
    model = joblib.load('full_model.joblib')
    scaler = joblib.load('full_scaler.joblib')
    feature_names = joblib.load('feature_names.joblib')
except FileNotFoundError:
    print("Model/scaler/feature_names files not found. Please run 'train_full_model.py' first.")
    exit()
except Exception as e:
    print(f"Error loading files: {e}")
    exit()

# Define the mappings for categorical features (from 0/1 to text)
cat_mappings = {
    'rbc': {'1': 'Normal', '0': 'Abnormal'},
    'pc': {'1': 'Normal', '0': 'Abnormal'},
    'pcc': {'0': 'Not Present', '1': 'Present'},
    'ba': {'0': 'Not Present', '1': 'Present'},
    'htn': {'0': 'No', '1': 'Yes'},
    'dm': {'0': 'No', '1': 'Yes'},
    'cad': {'0': 'No', '1': 'Yes'},
    'appet': {'0': 'Good', '1': 'Poor'},
    'pe': {'0': 'No', '1': 'Yes'},
    'ane': {'0': 'No', '1': 'Yes'}
}

# Define user-friendly names for the features
feature_display_names = {
    'age': 'Age', 'bp': 'Blood Pressure', 'sg': 'Specific Gravity',
    'al': 'Albumin', 'su': 'Sugar', 'rbc': 'Red Blood Cells', 'pc': 'Pus Cell',
    'pcc': 'Pus Cell Clumps', 'ba': 'Bacteria', 'bgr': 'Blood Glucose',
    'bu': 'Blood Urea', 'sc': 'Serum Creatinine', 'sod': 'Sodium',
    'pot': 'Potassium', 'hemo': 'Hemoglobin', 'pcv': 'Packed Cell Volume',
    'wc': 'WBC Count', 'rc': 'RBC Count', 'htn': 'Hypertension', 'dm': 'Diabetes Mellitus',
    'cad': 'Coronary Artery Disease', 'appet': 'Appetite', 'pe': 'Pedal Edema', 'ane': 'Anemia'
}


@app.route('/')
def home():
    # Renders the main form page
    return render_template('index.html')

@app.route('/predict', methods=['POST'])
def predict():
    
    display_data = OrderedDict()
    input_features_for_model = []

    try:
        # Get the raw form data
        form_data = request.form
        
        # --- 1. Prepare data for Model Prediction AND for Display ---
        for feature in feature_names: # 'feature_names' is from our joblib file
            value = form_data[feature]
            
            # Add to list for the model
            input_features_for_model.append(float(value))
            
            # Add to dictionary for display
            display_name = feature_display_names.get(feature, feature)
            if feature in cat_mappings:
                # Translate categorical value to text (e.g., '1' -> 'Yes')
                display_data[display_name] = cat_mappings[feature].get(value, value)
            else:
                # Use the numerical value directly
                display_data[display_name] = value

        # --- 2. Make Prediction ---
        final_features = np.array(input_features_for_model).reshape(1, -1)
        scaled_features = scaler.transform(final_features)
        prediction = model.predict(scaled_features)
        
        # --- 3. Prepare Result ---
        if prediction[0] == 1:
            # Match the CSS class 'positive' from your HTML
            prediction_text = "Positive" 
            prediction_class = "positive" 
        else:
            # Match the CSS class 'negative' from your HTML
            prediction_text = "Negative"
            prediction_class = "negative"
            
    except Exception as e:
        prediction_text = f"Error: {e}"
        prediction_class = "positive" # Show errors in red

    # Render the result.html page, passing in all the data
    return render_template('result.html', 
                           prediction_text=prediction_text, 
                           result_class=prediction_class, 
                           display_data=display_data) # Pass the submitted data

if __name__ == "__main__":
    print("Starting Flask server... Go to http://127.0.0.1:5000")
    app.run(debug=True)