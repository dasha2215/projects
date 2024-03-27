import csv

def preprocess_csv(input_file, output_file):
    with open(input_file, 'r', newline='') as csvfile:
        reader = csv.reader(csvfile)
        with open(output_file, 'w', newline='') as outfile:
            writer = csv.writer(outfile)
            for row in reader:
                processed_row = []
                for value in row:
                    # Check if the value is an integer (can be converted to int)
                    try:
                        int_value = int(value)
                        # If the value is an integer, replace \n with an empty string
                        processed_row.append(str(int_value).replace(' NULL', 0))
                    except ValueError:
                        # If the value cannot be converted to an integer, assume it's a string
                        # Replace \n with a space character
                        processed_row.append(value.replace(' NULL', ' '))
                writer.writerow(processed_row)

# Example usage:
input_file = '/Users/eklinka/name.basics.csv'
output_file = '/Users/eklinka/name.basics3.csv'
preprocess_csv(input_file, output_file)
print(f"CSV file '{input_file}' preprocessed and saved as '{output_file}'.")

