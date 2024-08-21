// Solution in Rust

use std::collections::HashMap;
use std::cmp::min;

impl Solution {
    pub fn strange_printer(s: String) -> i32 {
        // Convert the input string to a vector of characters
        let s: Vec<char> = s.chars().collect();
        
        // Remove consecutive duplicates from the input string
        let mut filtered_chars = Vec::new();
        for &c in &s {
            if filtered_chars.is_empty() || c != *filtered_chars.last().unwrap() {
                filtered_chars.push(c);
            }
        }

        // Get the length of the filtered characters
        let m = filtered_chars.len();
        
        // Initialize a 2D vector `dp` with dimensions `m x m`, where `dp[i][j]` will store
        // the minimum number of turns required to print the substring from index `i` to `j`.
        let mut dp = vec![vec![i32::MAX; m]; m];
        
        // Initialize a vector `next_occurrence` to store the next occurrence of each character
        let mut next_occurrence = vec![None; m];
        
        // Fill the DP table with base cases
        for i in 0..m {
            // The minimum number of turns required to print a single character is 1
            dp[i][i] = 1;
        }

        // Precompute the next occurrence for each character
        let mut last_seen = HashMap::new();
        for i in (0..m).rev() {
            let c = filtered_chars[i];
            if let Some(&pos) = last_seen.get(&c) {
                next_occurrence[i] = Some(pos);
            }
            last_seen.insert(c, i);
        }

        // Fill the DP table
        for length in 2..=m {
            for start in 0..=m - length {
                let end = start + length - 1;
                // Initialize the minimum number of turns required to print the substring from `start` to `end`
                // as the minimum number of turns required to print the substring from `start + 1` to `end` plus 1
                dp[start][end] = dp[start + 1][end] + 1;
                if let Some(mut next_pos) = next_occurrence[start] {
                    // Try to find a better solution by considering the next occurrence of the character at `start`
                    while next_pos <= end {
                        if next_pos + 1 <= end {
                            // Update the minimum number of turns required to print the substring from `start` to `end`
                            // by taking the minimum of the current value and the sum of the minimum number of turns
                            // required to print the substrings from `start` to `next_pos - 1` and from `next_pos + 1` to `end`
                            dp[start][end] = min(dp[start][end], dp[start][next_pos - 1] + dp[next_pos + 1][end]);
                        } else {
                            // Update the minimum number of turns required to print the substring from `start` to `end`
                            // by taking the minimum of the current value and the minimum number of turns required to print
                            // the substring from `start` to `next_pos - 1`
                            dp[start][end] = min(dp[start][end], dp[start][next_pos - 1]);
                        }
                        if let Some(pos) = next_occurrence[next_pos] {
                            next_pos = pos;
                        } else {
                            break;
                        }
                    }
                }
            }
        }

        // Return the minimum number of turns required to print the entire string
        dp[0][m - 1]
    }
}