import pandas as pd
import numpy as np
import joblib
from sklearn.impute import SimpleImputer
from sklearn.preprocessing import LabelEncoder, MinMaxScaler
from sklearn.ensemble import (
    RandomForestClassifier, 
    GradientBoostingClassifier, 
    AdaBoostClassifier,
    StackingClassifier
)
from xgboost import XGBClassifier
from sklearn.svm import SVC
from sklearn.tree import DecisionTreeClassifier
from sklearn.linear_model import LogisticRegression

print("Starting FULL model training process...")

# --- 1. Load and Preprocess Data (from Stage 1) ---
try:
    df = pd.read_csv('kidney_disease.csv')
except FileNotFoundError:
    print("Error: 'kidney_disease.csv' not found. Please add it to the project folder.")
    exit()

df.drop('id', axis=1, inplace=True, errors='ignore')
df.replace(['?', '\t?', '\t'], np.nan, inplace=True)

# List of all numeric and categorical columns
all_numeric_cols = ['age', 'bp', 'sg', 'al', 'su', 'bgr', 'bu', 'sc', 'sod', 'pot', 'hemo', 'pcv', 'wc', 'rc']
all_categorical_cols = ['rbc', 'pc', 'pcc', 'ba', 'htn', 'dm', 'cad', 'appet', 'pe', 'ane']

# Convert data types
for col in all_numeric_cols:
    df[col] = pd.to_numeric(df[col], errors='coerce')

# Impute missing values
num_imputer = SimpleImputer(strategy='median')
cat_imputer = SimpleImputer(strategy='most_frequent')

df[all_numeric_cols] = num_imputer.fit_transform(df[all_numeric_cols])
df[all_categorical_cols] = cat_imputer.fit_transform(df[all_categorical_cols])

# Encode categorical data
# This creates the 0/1 mappings our app will use
le = LabelEncoder()
for col in all_categorical_cols:
    df[col] = le.fit_transform(df[col])
    # Print mappings for our reference
    # print(f"Mappings for {col}: {list(le.classes_)} -> {list(le.transform(le.classes_))}")

# Encode target variable
df['classification'] = df['classification'].map({'ckd': 1, 'notckd': 0, 'ckd\t': 1})
df.dropna(subset=['classification'], inplace=True)
df['classification'] = df['classification'].astype(int)

# --- 2. Create X and y with ALL 24 features ---
X_full = df.drop('classification', axis=1)
y = df['classification']

# Get feature names in order for the app
feature_names = X_full.columns.tolist()
print(f"Training on {len(feature_names)} features: {feature_names}")

# --- 3. Scale ALL 24 Features ---
full_scaler = MinMaxScaler()
X_full_scaled = full_scaler.fit_transform(X_full)

# Save this scaler
joblib.dump(full_scaler, 'full_scaler.joblib')
joblib.dump(feature_names, 'feature_names.joblib') # Save feature names too
print("Saved full_scaler.joblib and feature_names.joblib")

# --- 4. Train the Blended Model ---
print("Training the Blended (Stacking) Model on 24 features...")
base_models = [
    ('RandomForest', RandomForestClassifier(random_state=42)),
    ('GradientBoosting', GradientBoostingClassifier(random_state=42)),
    ('AdaBoost', AdaBoostClassifier(estimator=DecisionTreeClassifier(max_depth=1), random_state=42)),
    ('XGBoost', XGBClassifier(random_state=42, eval_metric='logloss')),
    ('SVM', SVC(probability=True, random_state=42)),
    ('DecisionTree', DecisionTreeClassifier(random_state=42)),
    ('LogisticRegression', LogisticRegression(random_state=42, max_iter=1000))
]

meta_model = LogisticRegression(random_state=42, max_iter=1000)

stacking_model = StackingClassifier(
    estimators=base_models,
    final_estimator=meta_model,
    cv=5,
    n_jobs=-1
)

# Fit the model on our 24-feature scaled data
stacking_model.fit(X_full_scaled, y)

# Save the final app model
joblib.dump(stacking_model, 'full_model.joblib')
print("Saved full_model.joblib")
print("\n--- FULL Model training complete. You can now run 'app.py' ---")