// Quiz Engine with Plugin System
// Patterns used: Factory, Strategy, Template Method, Observer

#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include <map>
#include <functional>

// ------------------- Observer ----------------------
class ScoreObserver
{
public:
    virtual void onScoreUpdate(int score) = 0;
};

class ConsoleScoreDisplay : public ScoreObserver
{
public:
    void onScoreUpdate(int score) override
    {
        std::cout << "[Score Updated] Current Score: " << score << "\n";
    }
};

// ------------------- Strategy ----------------------
class ScoringStrategy
{
public:
    virtual int calculateScore(bool correct) = 0;
    virtual ~ScoringStrategy() = default;
};

class SimpleScoring : public ScoringStrategy
{
public:
    int calculateScore(bool correct) override
    {
        return correct ? 10 : 0;
    }
};

// ------------------- Template Method ----------------------
class Question
{
protected:
    std::string text;
    std::vector<ScoreObserver *> observers;
    std::unique_ptr<ScoringStrategy> scoringStrategy;

public:
    Question(std::string t, 
            std::unique_ptr<ScoringStrategy> strategy)
            : text(std::move(t)), 
            scoringStrategy(std::move(strategy))
            {
            }

    void attach(ScoreObserver *obs)
    {
        observers.push_back(obs);
    }

    void notify(int score)
    {
        for (auto obs : observers)
            obs->onScoreUpdate(score);
    }

    void run() //template method
    {
        ask();
        bool correct = checkAnswer(getUserAnswer());
        int score = scoringStrategy->calculateScore(correct);
        notify(score);
    }

    virtual void ask() = 0;
    virtual std::string getUserAnswer() = 0;
    virtual bool checkAnswer(const std::string &ans) = 0;

    virtual ~Question() = default;
};

// ------------------- Question Types ----------------------
class MCQQuestion : public Question
{
    std::vector<std::string> options;
    char correctOption;

public:
    MCQQuestion(const std::string &t, 
                std::vector<std::string> opts, 
                char correct, 
                std::unique_ptr<ScoringStrategy> strategy)
                : Question(t, std::move(strategy)), 
                options(std::move(opts)), 
                correctOption(correct)
                {
                }

    void ask() override
    {
        std::cout << text << "\n";

        char opt = 'A';

        for (auto &o : options)
        {
            std::cout << opt++ << ". " << o << "\n";
        }
    }

    std::string getUserAnswer() override
    {
        std::string ans;
        std::cout << "> ";
        std::cin >> ans;
        return ans;
    }

    bool checkAnswer(const std::string &ans) override
    {
        return !ans.empty() && toupper(ans[0]) == correctOption;
    }
};

class TrueFalseQuestion : public Question
{
    bool correctAnswer;

public:
    TrueFalseQuestion(const std::string &t, 
                    bool correct, 
                    std::unique_ptr<ScoringStrategy> strategy)
                    : Question(t, std::move(strategy)), 
                    correctAnswer(correct) 
                    {

                    }

    void ask() override
    {
        std::cout << text << " (true/false)\n";
    }

    std::string getUserAnswer() override
    {
        std::string ans;
        std::cout << "> ";
        std::cin >> ans;
        return ans;
    }

    bool checkAnswer(const std::string &ans) override
    {
        return (ans == "true" && correctAnswer) || (ans == "false" && !correctAnswer);
    }
};

// ------------------- Factory ----------------------
class QuestionFactory
{
public:
    static std::unique_ptr<Question> createMCQ(const std::string &text, const std::vector<std::string> &options, char correct)
    {
        return std::make_unique<MCQQuestion>(text, options, correct, std::make_unique<SimpleScoring>());
    }

    static std::unique_ptr<Question> createTrueFalse(const std::string &text, bool correct)
    {
        return std::make_unique<TrueFalseQuestion>(text, correct, std::make_unique<SimpleScoring>());
    }
};

// ------------------- Main ----------------------
int main()
{

    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    ConsoleScoreDisplay scoreDisplay;
    int totalScore = 0;

    std::vector<std::unique_ptr<Question>> quiz;
    
    quiz.push_back(QuestionFactory::createMCQ("What is the capital of France?", {"Berlin", "Madrid", "Paris", "Rome"}, 'C'));
    quiz.push_back(QuestionFactory::createTrueFalse("The Earth is flat.", false));

    for (auto &q : quiz)
    {
        q->attach(&scoreDisplay);
        q->run();
    }

    std::cout << "\nQuiz complete.\n";

    return 0;
}
