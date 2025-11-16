# Prompt the user for an input file name
file_name = input("Enter the input file name: ")

# Open the file in read mode
with open(file_name, "r") as input_file:
    rhs_dict = {}  # Dictionary to store previously computed expressions
    
    # Read each line of the file
    for line in input_file:
        line = line.strip()  # Remove any leading/trailing whitespace or newline characters
        
        # Split the line into the variable (left side) and the expression (right side)
        if " = " in line:
            var, rhs = line.split(" = ")
        else:
            continue  # Skip lines that don't match the format "variable = expression"
        
        # Check if the right-hand side expression has been computed before
        optim_rhs = rhs_dict.get(rhs, rhs)  # Use previously computed value if it exists
        
        # If the expression hasn't been computed before, store it in the dictionary
        if optim_rhs == rhs:
            rhs_dict[rhs] = var
        
        # Print the optimized line 
        print(f"{var} = {optim_rhs}")
