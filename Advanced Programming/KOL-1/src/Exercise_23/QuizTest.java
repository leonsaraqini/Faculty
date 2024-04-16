package Exercise_23;

import java.io.PrintStream;
import java.io.PrintWriter;
import java.util.*;
import java.util.concurrent.ExecutionException;
import java.util.stream.Stream;

enum QuestionType{
    MC,
    TF
}

abstract class Question{
    private String text;
    private int points;

    public Question(String text, int points) {
        this.text = text;
        this.points = points;
    }

    public abstract float getPointsWon(String s);

    public String getText() {
        return text;
    }

    public int getPoints() {
        return points;
    }
}

class TFQ extends Question{
    private boolean answer;

    public TFQ(String text, int points, boolean answer) {
        super(text, points);
        this.answer = answer;
    }

    @Override
    public float getPointsWon(String s) {
        return Boolean.parseBoolean(s) == answer ? getPoints() : 0;
    }

    @Override
    public String toString() {
        return String.format("True/False Question: %s Points: %d Answer: %s", getText(), getPoints(), answer);
    }
}

class MCQ extends Question{
    private String answer;

    public MCQ(String text, int points, String answer) {
        super(text, points);
        this.answer = answer;
    }

    public static boolean checkAnswer(String answer){
        switch (answer) {
            case "A" : case "B" : case "C": case "D": case "E": return true;
            default: return false;
        }
    }

    @Override
    public float getPointsWon(String s) {
        return s.equals(answer) ? getPoints() :  (0 - getPoints()) * 0.2F;
    }

    @Override
    public String toString() {
        return String.format("Multiple Choice Question: %s Points %d Answer: %s", getText(), getPoints(), answer);
    }
}

class Quiz{
    private List<Question> questions;

    public Quiz() {
        this.questions = new ArrayList<>();
    }

    public void addQuestion(String s) throws InvalidOperationException {
        String[] lines = s.split(";");


        if (lines[0].equals("MC")) {
            if(!MCQ.checkAnswer(lines[3])) throw new InvalidOperationException(lines[3]);

            questions.add(new MCQ(lines[1], Integer.parseInt(lines[2]), lines[3]));
        }else{
            questions.add(new TFQ(lines[1], Integer.parseInt(lines[2]), Boolean.parseBoolean(lines[3])));
        }

    }

    public void printQuiz(PrintStream out) {
        PrintWriter pw = new PrintWriter(out, true);

        questions.stream()
                .sorted(Comparator
                        .comparing(Question::getPoints)
                        .reversed()).forEach(pw::println);
    }

    public void answerQuiz(List<String> answers, PrintStream out) throws InvalidOperationException {
        if(answers.size() > questions.size()) throw new InvalidOperationException(true);

        PrintWriter pw = new PrintWriter(out, true);

        float totalPoints = 0;

        for(int i = 0; i < questions.size(); i++){
            float pointsWon = questions.get(i).getPointsWon(answers.get(i));

            pw.printf(String.format("%d. %.2f\n",i+1, pointsWon));

            totalPoints += pointsWon;
        }

        pw.printf(String.format("Total points: %.2f\n", totalPoints));


    }
}

class InvalidOperationException extends Exception{
    public InvalidOperationException(String message) {
        super(message + " is not allowed option for this question");
    }

    public InvalidOperationException(boolean error) {
        super("Answers and questions must be of same length!");
    }
}

public class QuizTest {
    public static void main(String[] args) throws InvalidOperationException {

        Scanner sc = new Scanner(System.in);

        Quiz quiz = new Quiz();

        int questions = Integer.parseInt(sc.nextLine());

            for (int i=0;i<questions;i++) {
                try{
                    quiz.addQuestion(sc.nextLine());
                }catch (Exception e){
                    System.out.println(e.getMessage());
                }

            }


        List<String> answers = new ArrayList<>();

        int answersCount =  Integer.parseInt(sc.nextLine());

        for (int i=0;i<answersCount;i++) {
            answers.add(sc.nextLine());
        }

        int testCase = Integer.parseInt(sc.nextLine());

        if (testCase==1) {
            quiz.printQuiz(System.out);
        }
        else if (testCase==2) {
            try{
                quiz.answerQuiz(answers, System.out);
            }catch (Exception e){
                System.out.println(e.getMessage());
            }

        } else {
            System.out.println("Invalid test case");
        }
    }
}

