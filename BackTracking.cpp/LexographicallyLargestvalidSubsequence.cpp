/*
    Time Complexity: O(N!)
    Space Complexity: O(N)

    Where 'N' is the given input.
*/

vector<int> findValidSequence(vector<int> &answer, vector<int> &remaining, int index) {
    if (index == answer.size()) {
        return answer;
    }

    // If current position is already fixed try creating from the next position.
    if (answer[index] != 0) {
        return findValidSequence(answer, remaining, index + 1);
    }

    // Iterate from biggest element to smallest.
    for (int i = remaining.size() - 1; i > 0; i--) {
        if (remaining[i] == 0){
            continue;
        }

        if (i != 1 && index + i < answer.size() && answer[index + i] == 0) {
            /*
                Mark 'ANSWER[INDEX]' and 'ANSWER[INDEX + i]' as 'i' and mark the current 
                element as used and then try to create the remaining answer.
            */
            answer[index] = i;
            answer[index + i] = i;
            remaining[i] = 0;

            vector<int> tempAnswer = findValidSequence(answer, remaining, index + 1);
            
            if (!tempAnswer.empty()){
                return tempAnswer;
            }
            
            // If the sequence could not be created then mark the current element as unused.
            remaining[i] = 1;
            answer[index] = 0;
            answer[index + i] = 0;
        }

        if (i == 1) {
            /*
                Mark 'ANSWER[INDEX]' as 'i' and mark the current element as used and
                then try to create the remaining answer.
            */
            answer[index] = i;
            remaining[i] = 0;

            vector<int> tempAnswer = findValidSequence(answer, remaining, index + 1);

            if (!tempAnswer.empty()){
                return tempAnswer;
            }

            // If the sequence could not be created then mark the current element as unused.
            remaining[i] = 1;
            answer[index] = 0;
        }

    }
    
    // Return an empty vector.
    return {};
}

vector<int> validSequence(int n) {
    vector<int> answer(2 * n - 1, 0);
    vector<int> remaining(n + 1, 1);

    return findValidSequence(answer, remaining, 0);
}
