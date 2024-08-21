// Solution in C++

class Solution
{
public:
    int strangePrinter(const std::string &s)
    {
        // Handle the edge case where the input string is empty
        if (s.empty())
            return 0;

        // Remove consecutive duplicates from the input string
        std::vector<char> filtered_chars;
        for (char c : s)
        {
            if (filtered_chars.empty() || c != filtered_chars.back())
            {
                filtered_chars.push_back(c);
            }
        }

        int m = filtered_chars.size();

        // Initialize the dynamic programming (DP) table and last occurrence tracking
        std::vector<std::vector<int>> dp(m, std::vector<int>(m, std::numeric_limits<int>::max()));
        std::vector<int> next_occurrence(m, -1);

        // Fill the DP table with base cases (each character can be printed in 1 turn)
        for (int i = 0; i < m; ++i)
        {
            dp[i][i] = 1;
        }

        // Precompute the next occurrence for each character in the filtered string
        std::unordered_map<char, int> last_seen;
        for (int i = m - 1; i >= 0; --i)
        {
            char c = filtered_chars[i];
            if (last_seen.find(c) != last_seen.end())
            {
                next_occurrence[i] = last_seen[c];
            }
            last_seen[c] = i;
        }

        // Fill the DP table using dynamic programming
        for (int length = 2; length <= m; ++length)
        { // length of substring
            for (int start = 0; start <= m - length; ++start)
            {
                int end = start + length - 1;
                // Initial case: print each character separately
                dp[start][end] = dp[start + 1][end] + 1;
                // Try to find a better solution by matching characters
                char current_char = filtered_chars[start];
                int next_pos = next_occurrence[start];
                while (next_pos != -1 && next_pos <= end)
                {
                    dp[start][end] = std::min(dp[start][end], dp[start][next_pos - 1] + (next_pos + 1 <= end ? dp[next_pos + 1][end] : 0));
                    next_pos = next_occurrence[next_pos];
                }
            }
        }

        // Return the minimum number of turns required to print the entire string
        return dp[0][m - 1];
    }
};

int kuchbhi()
{
    std::string line;
    std::vector<std::string> test_cases;

    // Read all input lines
    while (std::getline(std::cin, line))
    {
        test_cases.push_back(line);
    }

    Solution solution;
    std::vector<int> results;

    // Process each test case
    for (const std::string &test_case : test_cases)
    {
        // Convert JSON string to std::string (assumes input is valid)
        std::string s = test_case.substr(1, test_case.length() - 2); // remove quotes
        results.push_back(solution.strangePrinter(s));
    }

    // Write results to output file
    std::ofstream outfile("user.out");
    for (int result : results)
    {
        outfile << result << std::endl;
    }

    return 0;
}