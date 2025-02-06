
        string result;  // Use a separate string to store the result

        for (char ch : s) {
            if (ch != '*') {
                result.push_back(ch);  // Add characters to the result
            } else if (!result.empty()) {
                result.pop_back();  // Remove the last non-star character
            }
        }

        return result;

        