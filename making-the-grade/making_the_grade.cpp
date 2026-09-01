#include <array>
#include <string>
#include <vector>

// Round down all provided student scores.
std::vector<int> round_down_scores(std::vector<double> student_scores) {
    std::vector<int> result {};
    for (double score : student_scores)
    {
        result.emplace_back((int)score);
    }
    return result;
}

// Count the number of failing students out of the group provided.
int count_failed_students(std::vector<int> student_scores) {
    int counter{0};
    for (int score : student_scores)
    {
        counter += (score <= 40)? 1 : 0;
    }
    return counter;
}

// Create a list of grade thresholds based on the provided highest grade.
std::array<int, 4> letter_grades(int highest_score) {
    std::array<int, 4> result {41, 0, 0, 0};
    int interval = (highest_score - 40) / 4;
    for (int i = 0; i < 3; ++i)
    {
        result.at(1+i) = 41+interval+(i*interval);
    }
    return result;
}

// Organize the student's rank, name, and grade information in ascending order.
std::vector<std::string> student_ranking(
    std::vector<int> student_scores, std::vector<std::string> student_names) {
    std::vector<std::string> result {};
    for (int i = 0; i < student_scores.size(); ++i)
    {
        result.emplace_back(std::to_string(i+1) + ". "
            + student_names.at(i) + ": "
            + std::to_string(student_scores.at(i)));
    }
    return result;
}

// Create a string that contains the name of the first student to make a perfect
// score on the exam.
std::string perfect_score(std::vector<int> student_scores,
                          std::vector<std::string> student_names) {
    for (int i = 0; i < student_scores.size(); ++i)
    {
        if (student_scores.at(i) == 100)
            return student_names.at(i);
    }
    return "";
}
