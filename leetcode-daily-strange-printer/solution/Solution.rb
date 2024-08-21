# Solution in Ruby

# @param {String} s
# @return {Integer}
def strange_printer(s)
  # Remove consecutive duplicates from the string and convert it to an array of characters
  @s = s.gsub(/(.)\1*/, '\1').chars
  
  # Initialize a memoization hash to store intermediate results
  @memo = {}
  
  # Initialize a hash to store the indices of each character in the string
  @indices = {}
  
  # Populate the indices hash
  @s.each_with_index do |char, index|
    (@indices[char] ||= []) << index
  end
  
  # Call the recursive function to find the minimum number of turns
  check_str(0, @s.size - 1)
end

# Recursive function to find the minimum number of turns
def check_str(start_index, end_index)
  # If the result is already memoized, return it
  return @memo[[start_index, end_index]] if @memo[[start_index, end_index]]
  
  # Base case: if the start index is greater than the end index, return 0
  return 0 if start_index > end_index
  
  # Get the character at the start index
  char = @s[start_index]
  
  # Find all indices of the same character between the start and end indices
  suitable_indices = @indices[char].select { |char_index| char_index.between?(start_index + 1, end_index) }
  
  # Initialize an array to store the results of the recursive calls
  sub_results = []
  
  # Iterate over the suitable indices and make recursive calls
  suitable_indices.each do |char_index|
    # Make recursive calls for the two subproblems and add the results to the sub_results array
    sub_results << check_str(start_index + 1, char_index - 1) + check_str(char_index, end_index)
  end
  
  # Add the result of not printing the current character to the sub_results array
  sub_results << (check_str(start_index + 1, end_index) + 1)
  
  # Memoize the result and return it
  @memo[[start_index, end_index]] = sub_results.min
end