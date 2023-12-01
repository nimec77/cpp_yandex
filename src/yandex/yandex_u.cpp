#include <iostream>
#include <vector>

using namespace std;

class SequenceGenerator {
private:
    int n;
    vector<string> sequences_;

    void generate(const string &sequence, int openingParenthesis, int closingParenthesis, int openingSquare,
                  int closingSquare) {
        if (sequence.length() == n) {
            sequences_.push_back(sequence);
            return;
        }
        if ((openingParenthesis + openingSquare) < n / 2) {
            if (openingParenthesis < n / 2 && openingSquare == closingSquare) {
                generate(sequence + "(", openingParenthesis + 1, closingParenthesis, openingSquare, closingSquare);
            }
            if (openingSquare < n / 2) {
                generate(sequence + "[", openingParenthesis, closingParenthesis, openingSquare + 1, closingSquare);
            }
        }
        if (closingParenthesis < openingParenthesis && openingSquare == closingSquare) {
            generate(sequence + ")", openingParenthesis, closingParenthesis + 1, openingSquare, closingSquare);
        }
        if (closingSquare < openingSquare) {
            generate(sequence + "]", openingParenthesis, closingParenthesis, openingSquare, closingSquare + 1);
        }
    }

public:
    explicit SequenceGenerator(int n) : n(n), sequences_() {}

    void base() {
        if (n == 0 || n % 2 != 0) {
            return;
        }
        generate("", 0, 0, 0, 0);
    }

    [[nodiscard]] vector<string> getSequences() const {
        return sequences_;
    }
};

void outputAnswer(const vector<string> &sequences) {
    for (const string &sequence: sequences) {
        cout << sequence << " ";
    }
}

vector<string> generateSequences(int n) {
    SequenceGenerator sequenceGenerator(n);
    sequenceGenerator.base();

    return sequenceGenerator.getSequences();
}

int main() {
    int n;
    cin >> n;
    outputAnswer(generateSequences(n));
}
